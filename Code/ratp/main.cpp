#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Arret.h"
#include "metro.h"
#include "Node.h"
#include "Edge.h"
#include <sstream> //Pour transformation


#include <string.h>
#include <stdio.h>
#include <sstream>
#include <algorithm> //??


#define INT_MAX 10000000

using namespace std;


// a effacer plus tard...
vector<Node*> nodes;
//vector<Edge*> edges;
Edge** edges;


// Fonctions Kim
// Find the node with the smallest distance,
// remove it, and return it.
Node* ExtractSmallest(vector<Node*>& nodes)
{
    int size = nodes.size();
    if (size == 0)
        return NULL;
    int smallestPosition = 0;
    Node* smallest = nodes.at(0);
    for (int i=1; i<size; ++i)
    {
        Node* current = nodes.at(i);
        if (current->distanceFromStart <
                smallest->distanceFromStart)
        {
            smallest = current;
            smallestPosition = i;
        }//
    }
    nodes.erase(nodes.begin() + smallestPosition);
    return smallest;
}

// Does the 'nodes' vector contain 'node'
bool Contains(vector<Node*>& nodes, Node* node)
{
    const int size = nodes.size();
    for(int i=0; i<size; ++i)
    {
        if (node == nodes.at(i))
        {
            return true;
        }
    }
    return false;
}

// Return all nodes adjacent to 'node' which are still
// in the 'nodes' collectiovector<Edge*>& Edgesn.
vector<Node*>* AdjacentRemainingNodes(Node* node)
{
    vector<Node*>* adjacentNodes = new vector<Node*>();
    const int size = edges.size();
    for(int i=0; i<size; ++i)
    {
        Edge* edge = edges.at(i);
        Node* adjacent = NULL;
        if (edge->node1 == node)
        {
            adjacent = edge->node2;
        }
        //else if (edge->node2 == node) //pas dans les deux sens
        //{
         //   adjacent = edge->node1;
        //}
        if (adjacent && Contains(nodes, adjacent))
        {
            adjacentNodes->push_back(adjacent);
        }
    }
    return adjacentNodes;
}



// Return distance between two connected nodes
int Distance(Node* node1, Node* node2)
{
    const int size = edges.size();
    for(int i=0; i<size; ++i)
    {
        Edge* edge = edges.at(i);
        if (edge->Connects(node1, node2))
        {
            return edge->distance;
        }
    }
    return -1; // should never happen
}

///////////////////
void PrintShortestRouteTo(Node* destination)
{
    Node* previous = destination;
    cout << "Temps de trajet : "
         << destination->distanceFromStart << endl;
    while (previous)
    {
        cout << previous->id << " ";
        previous = previous->previous;
    }
    cout << endl;
}

void Dijkstras()
{
    while (nodes.size() > 0)
    {
        Node* smallest = ExtractSmallest(nodes);
        vector<Node*>* adjacentNodes =
            AdjacentRemainingNodes(smallest);
        const int size = adjacentNodes->size();
        for (int i=0; i<size; ++i)
        {
            Node* adjacent = adjacentNodes->at(i);
            int distance = Distance(smallest, adjacent) +
                           smallest->distanceFromStart;
//vector<Edge*>& Edges
            if (distance < adjacent->distanceFromStart)
            {
                adjacent->distanceFromStart = distance;
                adjacent->previous = smallest;
            }
        }
        delete adjacentNodes;
    }
}




// these two not needed
vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node)
{
    vector<Edge*>* adjacentEdges = new vector<Edge*>();
    const int size = edges.size();
    for(int i=0; i<size; ++i)
    {
        Edge* edge = edges.at(i);
        if (edge->node1 == node)
        {
            cout << "adjacent: " << edge->node2->id << endl;
            adjacentEdges->push_back(edge);
        }
        else if (edge->node2 == node)
        {
            cout << "adjacent: " << edge->node1->id << endl;
            adjacentEdges->push_back(edge);
        }
    }
    return adjacentEdges;
}
void RemoveEdge(vector<Edge*>& edges, Edge* edge)
{
    vector<Edge*>::iterator it;
    for (it=edges.begin(); it<edges.end(); ++it)
    {
        if (*it == edge)
        {
            edges.erase(it);
            return;
        }
    }
}

int getIndiceFromNode(std::string identifiant ,vector<Node*> les_noeuds)
{

 int indice_sortie;
 const int size = les_noeuds.size();
 for(int i=0; i<size; ++i){
 //       cout << "identifiant noeud : " << les_noeuds[i]->id << endl;
 //       cout << "identifiant : " << identifiant << endl;
        if(les_noeuds[i]->id== identifiant){
            indice_sortie = i;
        }

 }


 return(indice_sortie);

}

std::vector<std::string> split(std::string str,std::string sep)
{
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL)
    {
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

void charger_nodes(char* chemin){ //vector<Node*>
    std::string chaine;
    std::ifstream fichier(chemin); // acquisition
    int nligne = 0;
    //vector<Node*> nodes;
    string ligne;
    getline(fichier,ligne);
    std::vector<std::string> identifiants_ligne;

    //ligne.erase(remove(ligne.begin(), ligne.end(), '\"' ),ligne.end()); //enlever les ""
    //const char* ligne_char = ligne.c_str();
    //identifiants_ligne=split(ligne_char,"\t");

   string lignemetro;
    stringstream ligne_fichier(ligne);
   while(getline(ligne_fichier, lignemetro,'\t') ){
        lignemetro.erase(remove(lignemetro.begin(), lignemetro.end(), '\"' ),lignemetro.end());
        identifiants_ligne.push_back(lignemetro);
   }

        for (int i=0; i<identifiants_ligne.size(); i++)
            {
                Node* noeud = new Node(identifiants_ligne[i]);
                nodes.push_back(noeud);
            }
    fichier.close();
    //return(nodes);
}

void charger_edges(char* chemin){ //avant : Edge** dedans : vector<Node*> noeuds
    std::string chaine;
    std::ifstream fichier(chemin); // acquisition
    int nligne = 0;
     //Edge** edges = 0;
    // edges = new Edge*[nodes.size()]; //test const

    do
    {

        string ligne;
        getline(fichier,ligne);


       if (nligne==0)  // Si c'est la premi�re ligne je r�cup�re les identifiants d'arret
       {
        }
        else   // Je recupere les coordonn�es
        {
            //edges[nligne-1] = new Edge[nodes.size()]; //test const
            std::vector<string> distances;
            distances=split(ligne,"\t");




            for (int i=1; i<nodes.size()+1; i++) //test const
            {
             stringstream geek(distances[i]);
             int num = 0;
             geek >> num;
             if (num!=(-1))
             {
                Edge edge(nodes[nligne-1],nodes[i-1],num) ;
                edges.push_back(edge);
                //edges[nligne-1][i-1] = edge;
             }
            }
        }

        if (fichier.eof())
            break;
        nligne++;
    }
    //while ( !fichier.eof() );
    while ( nligne< 759 ); //BUG

    fichier.close(); // rel�chement
    //        return(edges);
}

DijkstrasFinal(vector<Node*> nodes, Edge** edges, std::string entree,std::string sortie){ //vector<Node*> nodes, Edge** edges,

int entree_int = getIndiceFromNode(entree,nodes);
int sortie_int = getIndiceFromNode(sortie,nodes);

nodes[entree_int]->distanceFromStart = 0; // set start node
Dijkstras();
PrintShortestRouteTo(nodes[sortie_int]);

}

// Fonction Alain


int nombre_lignes(const char* chemin){
    ifstream file(chemin);
    int nb_lignes = 0;
    string line;
    while (getline(file, line))
	{
		nb_lignes++;
	}
  file.close();
    return(nb_lignes);
}

int main()
{

    //Kim
vector<Node*> nodes_loaded = charger_nodes("W:/Documents/Cplusplus/Projet/ProjetC/Data projet/voisins.txt");
Edge** edges_loaded = charger_edges("W:/Documents/Cplusplus/Projet/ProjetC/Data projet/voisins.txt",nodes_loaded);
vector<Node*> nodes;
Edge** edges;

// Faire les trois �tapes sinon on �crase mal ce qui est fait avant...
nodes = nodes_loaded;
edges = edges_loaded;
DijkstrasFinal(nodes, edges, "1804","1948");

    // Alain
    Metro metro;
    string project_directory = "W:/Documents/Cplusplus/Projet/ProjetC";
    metro.chargeDonnees(project_directory);
    //metro.getArret("2271").affiche();

    cout << metro.getArret("2035")->getLigne()[1]->getNom()<<endl;
    cout << metro.getArret("2067")->getLigne()[0]->getNom()<<endl;

    cout << "arret : " << metro.getArret("2271")->getNom() <<
     " ligne : "<< metro.getArret("2271")->getLigne()[0]->getNumero()<< " " <<
     metro.getArret("2271")->getLigne()[0]->getNom();
     //cout << "arret : " << metro.getArret("2271")->getNom() <<
     //" ligne : "<< metro.getArret("2271")->getLigne()[1]->getNumero()<< " " <<
     //metro.getArret("2271")->getLigne()[1]->getNom();
    return 0;
}
