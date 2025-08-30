BSQ - Biggest Square Finder
Description

BSQ (Biggest Square) est un programme en C qui trouve le plus grand carré possible dans une grille contenant des obstacles. Le programme analyse un fichier fourni en entrée, détermine la plus grande zone carrée sans obstacles, et affiche la même grille avec ce carré matérialisé.
Fonctionnalités

    Lecture de grilles depuis un fichier ou l'entrée standard

    Algorithme efficace pour trouver le plus grand carré possible

    Affichage du résultat avec le carré matérialisé

    Gestion des erreurs de format de fichier

Compilation

Pour compiler le programme, utilisez la commande make à la racine du projet :
bash

make

Cette commande compilera les fichiers sources et générera l'exécutable bsq.
Utilisation

Le programme s'utilise de la manière suivante :
bash

# Avec un fichier en paramètre
./bsq [fichier_carte]

# En lecture depuis l'entrée standard
./bsq
