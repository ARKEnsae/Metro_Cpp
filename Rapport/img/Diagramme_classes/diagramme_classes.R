#devtools::install_github("bergant/datamodelr")
#install.packages("DiagrammeR")
#install.packages("shinyAce")
#install.packages("rsvg")
#install.packages("V8")

rm(list=ls())

library(datamodelr)

tables <- data.frame("table" = c("Graphe","Ligne","Arret","Metro","IHM","Itineraire","Edge","Node"),
                     "segment" = c("Algorithme","Métro","Métro","Métro",NA,NA,"Algorithme","Algorithme"),
                     "display" = c('accent2',"accent1","accent1","accent1",NA,NA,"accent2","accent2"),
                     stringsAsFactors = FALSE
)

IHM <- data.frame("column" = c("-hConsole",
                               "-activerCouleur",
                               "-colorerEcran(int code_couleur)",
                               "+choixDepartArrivee(metro : Metro)",
                               "+choixTypeItineraire()",
                               "+afficherItineraire(itineraire : Itineraire)",
                               "+quitter()"),
                  "type" = c("HANDLE",
                             "vector&lt;string&gt;",
                             "bool",
                             "void",
                             "bool",
                             "void",	
                             "bool"),
                  "table" = "IHM",
                  "key" = FALSE,
                  "ref" = NA, 
                  stringsAsFactors = FALSE
)      

Itineraire <- data.frame("column" = c("-arretsItineraire",
                                      "-tempsTotal",
                                      "+Itineraire(destination : Node*, metro : Metro)",
                                      "+creerItineraireSimplifie()",
                                      "+creerNbArretsSimplifie()"
),
"type" = c("vector&lt;Arret*&gt;",
           "int",
           "Itineraire",
           "vector&lt;Arret*&gt;",
           "vector&lt;int&gt;"
),
           "table" = "Itineraire",
           "key" = FALSE,
           "ref" = NA, 
           stringsAsFactors = FALSE
)


Ligne <- data.frame("column" = c("-idLigne",
                                 "-numero_ligne",
                                 "-nom_trajet",
                                 "-couleur",
                                 "-direction",
                                 "-arretsLigne",
                                 "+setArretsLigne(arret : Arret*)"
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
                                "-distanceCourtChemin",
                                "-distanceMinChangement",
                                "+connects(node1 : Node* , node2 : Node*)",
                                "+getDistance(minChangement : bool)"
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



                          
                          
Graphe <- data.frame("column" = c("-nodes",
                                  "-edges",
                                  "-adjacentRemainingNodes(node : Node*)",
                                  "-initialiserNodes()",
                                  #"+chargerDonnees(wd : string, metro : Metro*)",
                                  "-importerNodes(chemin : string)",
                                  "-importerEdges(chemin : string, chemin_changement : string)",
                                  "-extractSmallest(&amp;nodes : vector&lt;Node*&gt;, minChangement : bool)",
                                  "-contains(&amp;nodes : vector&lt;Node*&gt;, node : Node*)",
                                  "-calculerDistance(node1 : Node* , node2 : Node*, minChangement : bool)",
                                  "+dijkstras(entree : string, sortie : string, minChangement : bool)",
                                  "-getIndiceFromNode(identifiant : string, les_noeuds : vector&lt;Node*&gt;)"
                                  
                                  
                                  
),
"type" = c("vector&lt;Node*&gt;",
           "vector&lt;Edge*&gt;",
           "vector&lt;Node*&gt;* ",
           "void",
           #"void",
           "void",
           "void",
           "Node*",
           "bool",
           "int",
           "Node*",
           "int"
),
"table" = "Graphe",
"key" = FALSE,
"ref" = NA,
stringsAsFactors = FALSE
)

Metro <- data.frame("column" = c("-arretsMetro",
                                 "-lignesMetro",
                                 "+importerDonnees(wd : string)",
                                 "+getArret(int idArret)",
                                 "+getLigne(int route_id)",
                                 "-setArretsMetro(arret : Arret*)",
                                 "-importerToutesLignesTxt(wd : string)",
                                 "-importerTousStopTxt(wd : string)",
                                 "-importerStopTxt(path_fichier : string)",
                                 "-importerLigneTxt(path_fichier : string)"
                                 
                                 
                                 
                                 
                                 
),
"type" = c("vector&lt;Arret*&gt;",
           "vector&lt;Ligne*&gt;",
           "void",
           "Arret*",
           "Ligne*",
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

Arret <- data.frame("column" = c("-idArret",
                                 "-nom",
                                 "-adresse",
                                 "-stop_lon",
                                 "-stop_lat",
                                 "-lignesArret",
                                 "+setLignesArret(ligne : Ligne*)",
                                 "+memeLigne (arret : Arret*)",
                                 "+memeArret (arret : Arret*)",
                                 "-calculerDirection(arret : Arret*)"
),
"type" = c("int",
           "string",
           "string",
           "float",
           "float",
           "vector&lt;Ligne*&gt;",
           "void",
           "bool",
           "bool",
           "vector&lt;string&gt;"
), 
"table" = "Arret",
"key" = FALSE,
"ref" = NA, 
stringsAsFactors = FALSE
)


Node <- data.frame("column" = c("-idNode",
                                "-distanceFromStartCourtChemin",
                                "-distanceFromStartMinChangement",
                                "+previous",
                                "+setDistanceFromStart(dist : int, minChangement : bool)",
                   "+getDistanceFromStart(minChangement : bool)",
"+initialiserNode()"
), "type" = c("int",
           "int",
           "int",
           "Node*",
           "void",
           "int",
           "void"
), 
"table" = "Node",
"key" = FALSE,
"ref" = NA, 
stringsAsFactors = FALSE
)




columns <- rbind(Graphe,Metro,IHM,Itineraire,Edge,Node,Ligne,Arret)
#columns <- rbind(Itineraire)
rm(Graphe,Metro,IHM,Itineraire,Edge,Node,Ligne,Arret)

#references = NULL
references <- data.frame("table" = c("Ligne","Arret","Node","Ligne","Arret","Node","Edge","Metro","Arret","Node","Metro","Itineraire"),
                         column=NA,
                         "ref" = c("Arret","Ligne","Edge","Metro","Metro","Graphe","Graphe","IHM","Itineraire","Itineraire","Itineraire","IHM"),
                         "ref_col"=NA,
                         "ref_id" = 1,
                         "ref_col_num" = 1,
                         stringsAsFactors = FALSE)
                         

dm_f <- list(tables = tables,columns = columns, references = references)

attr(dm_f,"class") <- c("data_model","list")

graph <- dm_create_graph(dm_f, rankdir = "BT", col_attr = c("column", "type"))
dm_render_graph(graph)

dm_export_graph(graph, file_name = "Rapport/img/Diagramme_classes/diagramme_classes.svg",width = NULL,height = NULL)
