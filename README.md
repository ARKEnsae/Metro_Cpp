# Projet C++ sur le calcul d'itinéraire du métro parisien <img src="Rapport/img/LOGO-ENSAE-avatar.png" align="right" alt=""  width="100"/>

Ce projet a été effectué dans le cadre d'un projet C++ par le binôme [antuki](https://github.com/antuki) et [AQLT](https://github.com/AQLT).

Le rapport est disponible [ici](https://arkensae.github.io/Metro_Cpp/Rapport/KA_AQLT_Metro_rapport.pdf) et les slides de la présentation [là](https://arkensae.github.io/Metro_Cpp/Rapport/KA_AQLT_Metro_slides.pdf).

Pour exécuter le programme, télécharger l'ensemble de l'archive : https://github.com/ARKEnsae/Metro_Cpp/archive/master.zip ou les dossiers `Data projet` et `Code/ratp`.

Afin de s'assurer que le programme tourne bien sur votre ordinateur. Veillez à effectuer les vérifications suivantes sur le fichier `main.cpp` :

1. Changer le répertoire de travail (`project_directory`) : il doit s'agir du lien vers le dossier contenant le dossier `Data Projet`. Ainsi, si l'archive a été dézippée sous `D:/`, `project_directory` doit être égale à `D:/Metro_Cpp`.

2. Choisir si l'on veut mettre la couleur  (booléen `activerCouleur`).   
**Attention** : la coloration de la console utilise le package `windows.h` et n'est donc compatible que sous les ordinateurs sous Windows. Dans le cas contraire, ouvrir le fichier `IHM.h` et supprimer la ligne 6 contenant `#include <windows.h>`. 

3. Lancer le programme est se laisser guider.

![](Rapport/img/main.png)
