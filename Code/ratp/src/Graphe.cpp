#include "Graphe.h"
#include <vector>
#include <iostream>
#include <stdio.h> //printf
#include <string.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Node.h"
#include "Edge.h"
#include <math.h>
#include <windows.h> //couleurs palette

Graphe::Graphe(string wd)
{
    importerNodes(wd + "/Data projet/voisins.txt");
    importerEdges(wd + "/Data projet/voisins.txt", wd + "/Data projet/voisins_type.txt");
}


Node* Graphe::extractSmallest(vector<Node*>& nodes, bool min_itineraire)
{
    int size = nodes.size();
    if (size == 0)
        return NULL;
    int smallestPosition = 0;
    Node* smallest = nodes.at(0);
    for (int i=1; i<size; ++i)
    {
        Node* current = nodes.at(i);
        if (current->getDistanceFromStart(min_itineraire) <
                smallest->getDistanceFromStart(min_itineraire))
        {
            smallest = current;
            smallestPosition = i;
        }//
    }
    nodes.erase(nodes.begin() + smallestPosition);
    return smallest;
}

bool Graphe::contains(vector<Node*>& nodes, Node* node)
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

vector<Node*>* Graphe::adjacentRemainingNodes(Node* node)
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
        if (adjacent && contains(nodes, adjacent))
        {
            adjacentNodes->push_back(adjacent);
        }
    }
    return adjacentNodes;
}

int Graphe::calculerDistance(Node* node1, Node* node2, bool min_itineraire)
{
    const int size = edges.size();
    for(int i=0; i<size; ++i)
    {
        Edge* edge = edges.at(i);
        if (edge->connects(node1, node2))
        {
            return edge->getDistance(min_itineraire);
        }
    }
    return -1; // ne doit jamais arriver
}

int Graphe::getIndiceFromNode(string identifiant, vector<Node*> les_noeuds)
{
    int id_int;
    stringstream temp_id(identifiant);
    temp_id >> id_int;
    int indice_sortie;
    const int size = les_noeuds.size();
    for(int i=0; i<size; ++i){
        if(les_noeuds[i]->getIdNode()== id_int){
            indice_sortie = i;
        }
    }
    return(indice_sortie);
}

vector<string> split(string str, string sep)
{
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL)
    {
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

Node* Graphe::dijkstras(string entree, string sortie, bool min_itineraire){
    this->initialiserNodes();
    //On crée une copie de nodes pour garder le vecteur en mémoire
    vector<Node*> nodes_algo;
    for (int i=0; i<nodes.size(); i++)
        nodes_algo.push_back(nodes[i]);

    int entree_int = getIndiceFromNode(entree, nodes_algo);
    int sortie_int = getIndiceFromNode(sortie, nodes_algo);

    nodes_algo[entree_int]->setDistanceFromStart(0, false); // initialiser le noeud de départ
    nodes_algo[entree_int]->setDistanceFromStart(0, true);
    Node* node_fin = nodes_algo[sortie_int];
    Node* node_entree = nodes_algo[entree_int];


   while (nodes_algo.size() > 0)
    {
        Node* smallest = extractSmallest(nodes_algo, min_itineraire); // smallest est le sommet le plus proche
        vector<Node*>* adjacentNodes =
            adjacentRemainingNodes(smallest); //adjacentNodes permet d'identifier les voisins "restant" de ce voisin le plus proche
        const int size = adjacentNodes->size();
        for (int i=0; i<size; ++i)
        {
            Node* adjacent = adjacentNodes->at(i);
            int distance = calculerDistance(smallest, adjacent, min_itineraire) +
                           smallest->getDistanceFromStart(min_itineraire);
            if (distance < adjacent->getDistanceFromStart(min_itineraire))
            {
                adjacent->setDistanceFromStart(calculerDistance(smallest, adjacent, false) +
                           smallest->getDistanceFromStart(false),
                                       false); //on met à jour la distance qui minimise le temps
                adjacent->setDistanceFromStart(calculerDistance(smallest, adjacent, true) +
                           smallest->getDistanceFromStart(true),
                                       true); // puis on met à jour la distance qui minimise le nb de changements
                adjacent->previous = smallest;
            }
        }
        delete adjacentNodes;
    }


    return(node_fin);
}
void Graphe::importerNodes(string chemin){
    string chaine;
    const char* chemin_char = chemin.c_str();
    ifstream fichier(chemin_char);
    int nligne = 0;
    string ligne;
    getline(fichier,ligne);
    std::vector<std::string> identifiants_ligne;
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
}

void Graphe::importerEdges(string chemin, string chemin_changement){
    const char* chemin_char = chemin.c_str();
    const char* chemin_changement_char = chemin_changement.c_str();
    string chaine;
    ifstream fichier(chemin_char); // acquisition
    ifstream fichier_chg(chemin_changement_char);

    int nligne = 0;
    do
    {
        string ligne, ligne_chg;
        getline(fichier, ligne);
        getline(fichier_chg, ligne_chg);
       if (nligne==0)  // Si c'est la première ligne je récupère les identifiants d'arret
       {
        }
        else   // Je recupere les coordonnées
        {
            vector<string> distances, distances_chg;
            distances = split(ligne, "\t");
            distances_chg = split(ligne_chg, "\t");
            for (int i=1; i<nodes.size()+1; i++) //test const
            {
             stringstream sgst(distances[i]);
             stringstream sgst_chg(distances_chg[i]);
             int num, num_chg = -1;
             sgst >> num;
             sgst_chg >> num_chg;
             if (num!=(-1))
             {
                Edge* edge = new Edge(nodes[nligne-1] ,nodes[i-1],num, num_chg) ;
                edges.push_back(edge);
             }
            }
        }
        if (fichier.eof())
            break;
        nligne++;
    }
    //while ( !fichier.eof() ); //BUG : bizarre !
    while ( nligne<= 758 );

    fichier.close(); // relachement mémoire
}

void Graphe::initialiserNodes(){
    for(int i=0; i<nodes.size(); ++i)
    {
        nodes[i]->initialiserNode();
    }
}
