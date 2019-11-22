stops_id <- unlist(lapply(list.dirs("Data/",recursive = FALSE),function(dir){
    stops <- read.csv(paste0(dir,"/", "stops.txt"),
                      header = TRUE,
                      sep = ",",
                      stringsAsFactors = FALSE)
    stops$stop_id
}))
voisins <- matrix(0, nrow = length(stops_id), ncol = length(stops_id),
                  dimnames = list(stops_id, stops_id))
voisins_type <- matrix("", nrow = length(stops_id), ncol = length(stops_id),
                 dimnames = list(stops_id, stops_id))
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
        voisins[from, to] <- transfers[i, "min_transfer_time"]
        voisins_type[from, to] <- "transfer"
    }
    
    stop_times$order <- seq_len(nrow(stop_times))

    stop_times2 <- merge(stop_times, stops, by = "stop_id", sort = FALSE)
    stop_times2 <- stop_times2[order(stop_times2$order),]
    trips2 <- merge(trips, routes, by = "route_id")
    i_unique_route_id <- sapply(unique(trips2$route_id), function(i) which(trips2$route_id == i)[1])
    
    for (i in i_unique_route_id){
        if (!(i == 1807 & dir == "Data//RATP_GTFS_METRO_10")){
            trips3 <- trips2[i, ]
            stop_times3 <- merge(stop_times2, trips3, by = "trip_id")
            stop_times3 <- stop_times3[order(stop_times3$order),]
            if (any(duplicated(stop_times3$stop_sequence))){
                remove_i <- which(stop_times3$stop_sequence ==1)[2]:nrow(stop_times3)
                stop_times3 <- stop_times3[-remove_i,]
            }
            
            for(j in seq_len(nrow(stop_times3) - 1)){
                from = as.character(stop_times3[j, "stop_id"])
                to = as.character(stop_times3[j + 1, "stop_id"])
                
                from_time = as.POSIXlt(stop_times3[j,"arrival_time"], format="%H:%M:%S")
                to_time = as.POSIXlt(stop_times3[j+1,"arrival_time"], format="%H:%M:%S")
                transfer_time = as.numeric(difftime(to_time,from_time,units="secs"))
                
                voisins[from, to] <- transfer_time
                voisins_type[from, to] <- trips3$route_long_name
            }
            stop_times3 <- stop_times3[,c("trip_id", "stop_id", "arrival_time", "departure_time", "stop_sequence", 
                                          "stop_name", "stop_desc", "stop_lat", "stop_lon", 
                                          "route_id", "service_id", "route_short_name", 
                                          "route_long_name", "route_color")]
            write.table(stop_times3, 
                        file = paste0(sub("Data", "Data projet", dir), "/","route_",i,".txt"),
                        sep = "\t",
                        row.names = FALSE, col.names = TRUE,fileEncoding = "UTF-8")
            try(file.copy(paste0(dir,"/", "stops.txt"), 
                          paste0(sub("Data", "Data projet", dir),"/", "stops.txt"),
                          overwrite = FALSE))
        }
    }
}
write.table(voisins, file = "Data projet/voisin.txt", sep = "\t",
          row.names = TRUE, col.names = TRUE,fileEncoding = "UTF-8")
write.table(voisins_type, file = "Data projet/voisin_type.txt", sep = "\t",
            row.names = TRUE, col.names = TRUE,fileEncoding = "UTF-8")


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
