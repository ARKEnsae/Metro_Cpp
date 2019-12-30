#devtools::install_github("bergant/datamodelr")
#install.packages("DiagrammeR")
#install.packages("shinyAce")
rm(list=ls())

library(datamodelr)

tables <- data.frame("table" = c("Ligne","Arret","Metro","Itineraire","Edge","Node"),
                     "segment" = c("Métro","Métro",NA,"Algorithme","Algorithme","Algorithme"),
                     "display" = c("accent1","accent1",NA,"accent2","accent2","accent2"),
                     stringsAsFactors = FALSE
)

Ligne <- data.frame("column" = c("-route_id",
                                 "-numero_ligne",
                                 "-nom_trajet",
                                 "-couleur",
                                 "-direction",
                                 "-liste_arrets",
                                 "+ajouteArret(Arret* arret)"
), 
"type" = c("int",
           "string",
           "string",
           "string",
           "string",
           "vector&lt;Arret*&gt;",
           "void"
), 
"table" = "Ligne",
"key" = FALSE,
"ref" = NA, 
stringsAsFactors = FALSE
)


Edge <- data.frame("column" = c("+node1",
                                "+node2",
                                "-distance",
                                "-distance_changement",
                                "+Connects(node1 : Node* , node2 : Node*)",
                                "+getDistance(min_itineraire : bool)"
),
"type" = c("Node*",
           "Node*",
           "int",
           "int",
           "bool",
           "int"
), 
"table" = "Edge",
"key" = FALSE,
"ref" = NA, 
stringsAsFactors = FALSE
)

Node <- data.frame("column" = c("-arret",
                                "-distanceFromStart",
                                "-distanceFromStartMinChangement",
                                "+previous",
                                "+memeLigne",
                                "+memeArret",
                                "+setDistance(dist : int, min_itineraire : bool)"),
                   "type" = c("Arret*",
                              "int",
                              "int",
                              "Node*",
                              "bool",
                              "bool",
                              "void"
                   ), 
                   "table" = "Node",
                   "key" = FALSE,
                   "ref" = NA, 
                   stringsAsFactors = FALSE
)







Itineraire <- data.frame("column" = c("-nodes",
                                      "-edges",
                                      "-AdjacentRemainingNodes(node : Node*)",
                                      "-AdjacentEdges(edges : vector&lt;Edge*&gt;&amp;, node : Node*)",
                                      "+DijkstrasFinal(entree : string, sortie : string, min_itineraire : bool)",
                                      "+chargerDonnees(wd : string, metro : Metro*)",
                                      "-chargerNodes(chemin : string,  metro : Metro*)",
                                      "-chargerEdges(chemin : string)",
                                      "-ExtractSmallest(&amp;nodes : vector&lt;Node*&gt;, min_itineraire : bool)",
                                      "-Contains(&amp;nodes : vector&lt;Node*&gt;, node : Node*)",
                                      "-Distance(node1 : Node* , node2 : Node*, min_itineraire : bool)",
                                      "-PrintShortestRouteTo( destination : Node*)",
                                      "-Dijkstras(min_itineraire : bool)",
                                      "-RemoveEdge(&amp;edges : vector&lt;Edge*&gt;, edge : Edge*)",
                                      "-getIndiceFromNode(identifiant : string, les_noeuds : vector&lt;Node*&gt;)"
),
"type" = c("vector&lt;Node*&gt;",
           "vector&lt;Edge*&gt;",
           "vector&lt;Node*&gt;* ",
           "vector&lt;Edge*&gt;*",
           "void",
           "void",
           "void",
           "void",
           "Node*",
           "bool",
           "int",
           #"bool",
           "void",
           "void",
           "void",
           "int"
),
"table" = "Itineraire",
"key" = FALSE,
"ref" = NA,
stringsAsFactors = FALSE
)



Metro <- data.frame("column" = c("+itineraire",
                                 "-liste_arrets",
                                 "-liste_lignes",
                                 "+chargeDonnees(wd : string)",
                                 "-ajouteToutesLignes(wd : string)",
                                 "-ajouteTousStopTxt(wd : string)",
                                 "-ajouteStopTxt(path_fichier : string)",
                                 "-ajouteArret(arret : Arret*)",
                                 "-ajouteLigne(path_fichier : string)"
),
"type" = c("Itineraire",
           "vector&lt;Arret*&gt;",
           "vector&lt;Ligne*&gt;",
           "void",
           "void",
           "void",
           "void",
           "void",
           "bool"
), 
"table" = "Metro",
"key" = FALSE,
"ref" = NA, 
stringsAsFactors = FALSE
)

Arret <- data.frame("column" = c("-stop_id",
                                 "-nom",
                                 "-adresse",
                                 "-stop_lon",
                                 "-stop_lat",
                                 "-lignes",
                                 "+associeLigne(ligne : Ligne*)",
                                 "+memeLigne (arret : Arret*)",
                                 "+memeArret (arret : Arret*)"
),
"type" = c("int",
           "string",
           "string",
           "float",
           "float",
           "vector&lt;Ligne*&gt;",
           "void",
           "bool",
           "bool"
), 
"table" = "Arret",
"key" = FALSE,
"ref" = NA, 
stringsAsFactors = FALSE
)

columns <- rbind(Metro,Itineraire,Edge,Node,Ligne,Arret)
#columns <- rbind(Itineraire)
rm(Metro,Itineraire,Edge,Node,Ligne,Arret)

#references = NULL
references <- data.frame("table" = c("Ligne","Arret","Node","Ligne","Arret","Arret","Node","Edge","Itineraire"),
                         column=NA,
                         "ref" = c("Arret","Ligne","Edge","Metro","Metro","Node","Itineraire","Itineraire","Metro"),
                         "ref_col"=NA,
                         "ref_id" = 1,
                         "ref_col_num" = 1,
                         stringsAsFactors = FALSE)
                         

dm_f <- list(tables = tables,columns = columns, references = references)

attr(dm_f,"class") <- c("data_model","list")

graph <- dm_create_graph(dm_f, rankdir = "TB", col_attr = c("column", "type"))
dm_render_graph(graph)


