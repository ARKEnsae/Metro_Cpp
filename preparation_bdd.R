stops_id <- do.call(rbind, lapply(list.dirs("Data/",recursive = FALSE),function(dir){
    stops <- read.csv(paste0(dir,"/", "stops.txt"),
                      header = TRUE,
                      sep = ",",
                      stringsAsFactors = FALSE)
    data.frame(id = stops$stop_id, dir = dir, 
               nom = stops$stop_name,
               stringsAsFactors = F)
}))
stops_id[stops_id$id == 2170,]
stops_id <- stops_id$id
stops_id <- stops_id[stops_id != 2371]
voisins <- matrix(-1, nrow = length(stops_id), ncol = length(stops_id),
                  dimnames = list(stops_id, stops_id))
voisins_type <- matrix("", nrow = length(stops_id), ncol = length(stops_id),
                 dimnames = list(stops_id, stops_id))
dir = "Data//RATP_GTFS_METRO_7"
for (dir in list.dirs("Data/",recursive = FALSE)){
    try(dir.create(sub("Data", "Data projet", dir)))
    list_fichier = list.files(dir)
    for (i in list_fichier){
        assign(x = gsub(".txt", "", i),
               value = read.csv(paste0(dir,"/", i),
                                header = TRUE,
                                sep = ",",
                                stringsAsFactors = FALSE))
        
    }
    transfers <- transfers[transfers$from_stop_id%in%stops_id & transfers$to_stop_id%in%stops_id,]
    for(i in seq_len(nrow(transfers))){
        from <- as.character(transfers[i, "from_stop_id"])
        to <- as.character(transfers[i, "to_stop_id"])
        voisins[from, to] <- voisins[to, from]  <- transfers[i, "min_transfer_time"]
        voisins_type[from, to] <- voisins_type[to, from] <- "transfer"
    }
    
    stop_times$order <- seq_len(nrow(stop_times))

    stop_times2 <- merge(stop_times, stops, by = "stop_id", sort = FALSE)
    stop_times2 <- stop_times2[order(stop_times2$order),]
    trips2 <- merge(trips, routes, by = "route_id")
    i_unique_route_id <- sapply(unique(trips2$route_id), function(i) which(trips2$route_id == i)[1])
    i_export = 0
    i=i_unique_route_id[3]
    for (i in i_unique_route_id){
        if (!(i %in% c(1807, 1808) & dir == "Data//RATP_GTFS_METRO_10")){
            trips3 <- trips2[i, ]
            #stop_times3 <- stop_times2[stop_times2$trip_id == trips3$trip_id,]
            stop_times3 <- merge(stop_times2, trips3, by = "trip_id",sort = F)
            stop_times3 <- stop_times3[order(stop_times3$order),]
            if( i == 6179 & dir == "Data//RATP_GTFS_METRO_13" ||
                i == 3139 & dir == "Data//RATP_GTFS_METRO_7" ||
                (i == 4123 & dir == "Data//RATP_GTFS_METRO_1") || 
                (i == 1184 & dir == "Data//RATP_GTFS_METRO_7b") ||
                (i == 3565 & dir == "Data//RATP_GTFS_METRO_4")){
                #Pour bien avoir la ligne 13 retour depuis Saint-Denis
                # Et la ligne 7 retour depuis Villejuif
                keep_i <- which(stop_times3$stop_sequence ==1)[2]:nrow(stop_times3)
                stop_times3 <- stop_times3[keep_i,]
            }
            if (any(duplicated(stop_times3$stop_sequence))){
                remove_i <- which(stop_times3$stop_sequence ==1)[2]:nrow(stop_times3)
                stop_times3 <- stop_times3[-remove_i,]
            }

            # if((i == 4123 & dir == "Data//RATP_GTFS_METRO_1") || 
            #    (i == 1184 & dir == "Data//RATP_GTFS_METRO_7b") ||
            #    (i == 3565 & dir == "Data//RATP_GTFS_METRO_4")
            #    ){
            #     stop_times3$stop_sequence <- seq(nrow(stop_times3), 1, -1)
            #     stop_times3<- stop_times3[stop_times3$stop_sequence,]
            # }
            
            for(j in seq_len(nrow(stop_times3) - 1)){
                from = as.character(stop_times3[j, "stop_id"])
                to = as.character(stop_times3[j + 1, "stop_id"])
                
                from_time = as.POSIXlt(stop_times3[j,"arrival_time"], format="%H:%M:%S")
                to_time = as.POSIXlt(stop_times3[j+1,"arrival_time"], format="%H:%M:%S")
                transfer_time = as.numeric(difftime(to_time,from_time,units="secs"))
                
                voisins[from, to] <- abs(transfer_time)
                voisins_type[from, to] <- trips3$route_long_name
            }
            stop_times3 <- stop_times3[,c("trip_id", "stop_id", "arrival_time", "departure_time", "stop_sequence", 
                                          "stop_name", "stop_desc", "stop_lat", "stop_lon", 
                                          "route_id", "service_id", "route_short_name", 
                                          "route_long_name", "route_color")]
            i_export = i_export + 1
            write.table(stop_times3,
                        file = paste0(sub("Data", "Data projet", dir), "/","route_",i_export,".txt"),
                        sep = "\t",
                        row.names = FALSE, col.names = TRUE,fileEncoding = "UTF-8")
            try(file.copy(paste0(dir,"/", "stops.txt"),
                          paste0(sub("Data", "Data projet", dir),"/", "stops.txt"),
                          overwrite = FALSE))
            print(paste(paste(stop_times3$stop_name[c(1, nrow(stop_times3))], collapse = " à "),
                        " ligne : ", stop_times3$route_long_name[1]))
        }
    }
    liste_arrets <- split(stops$stop_id[stops$stop_id!=2371],stops$stop_name)
    for (i in seq_along(liste_arrets)){
        if(length(liste_arrets[[i]]) == 2){
            from <- as.character(liste_arrets[[i]][1])
            to <- as.character(liste_arrets[[i]][2])
            voisins[from, to] <- voisins[to, from]  <- 0
            voisins_type[from, to] <- voisins_type[to, from] <- "meme_ligne"
        }
    }
}
voisins["2075",voisins["2075",]>=0]
voisins["1659",voisins["1659",]>=0]
voisins["1827",voisins["1827",]>=0]
voisins["2366",voisins["2366",]>=0]
voisins["1824",voisins["1824",]>=0]
voisins["1827", "2366"]
voisins["2366", "2363"]
voisins["2366", "2363"]
# Ligne 13 Saint-Denis //
1824
2366
1827
voisins["1827","1824"]
voisins["2371","1827"]

nrow(voisins)[voisins< (-1)]
write.table(voisins, file = "Data projet/voisins.txt", sep = "\t",
          row.names = TRUE, col.names = TRUE,fileEncoding = "UTF-8")
write.table(voisins_type, file = "Data projet/voisins_type.txt", sep = "\t",
            row.names = TRUE, col.names = TRUE,fileEncoding = "UTF-8")
voisins_type["2253","2252"]
voisins_type["2253","2252"]

voisins["2252","2253"]
voisins["2252","1928"]

voisins["1928","2253"]
voisins["2253","1928"]

# 
# ?read.csv
# 
# route_id = routes$route_id[1]
# trips_i <- trips[trips$route_id == route_id,]
# 
# stop_times2 <- merge(stop_times, stops, by ="stop_id", sort = FALSE)
# trips2 <- merge(trips, routes, by = "route_id")
# trips2 <- trips2[sapply(unique(trips2$route_id), function(i) which(trips2$route_id == i)[1]), ]
# stop_times3 <- merge(stop_times2, trips2, by = "trip_id")
# stop_times3 <- stop_times3[order(stop_times3$route_id, stop_times3$departure_time),]
# 
# transfers2 <- merge(transfers, stops, by.x = "from_stop_id", by.y = "stop_id",all.x = FALSE, all.y = FALSE)
# transfers3 <- merge(transfers, stops, by.x = "to_stop_id", by.y = "stop_id",all.x = FALSE, all.y = FALSE)


#### modification des fichiers stops en stops_a sans les accent
rm(list=ls())

#dir = list.dirs("Data/",recursive = FALSE)[1]
for (dir in list.dirs("Data/",recursive = FALSE)){
    value = read.csv(paste0(dir,"/", "stops.txt"), header = TRUE, sep = ",", stringsAsFactors = FALSE)
    # value$stop_name <- iconv(value$stop_name,from="UTF-8",to="ASCII//TRANSLIT")
    # value$stop_desc <- iconv(value$stop_desc,from="UTF-8",to="ASCII//TRANSLIT")
    value$stop_name <- stringi::stri_trans_general(value$stop_name, "Latin-ASCII")
    value$stop_desc <- stringi::stri_trans_general(value$stop_desc, "Latin-ASCII")
    write.table(value, file = paste0(sub("Data", "Data projet", dir), "/","stops_a.txt"), sep = ",", row.names = FALSE, col.names = TRUE,fileEncoding = "UTF-8",na="")
}        
