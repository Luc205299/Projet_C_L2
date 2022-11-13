

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    char* fichier = "../dictionnaire_non_accentue.txt";

    tree arbre_verbe = full_tree(fichier,"Ver");
    tree arbre_nom = full_tree(fichier,"Nom");
    tree arbre_adj = full_tree(fichier,"Adj");
    tree arbre_adv = full_tree(fichier,"Adv");
    //print2D(arbre_verbe);
    char* mot = "all";
    recherche_base_part2(recherche_base_part1(mot,arbre_verbe));




    base_aleatoire(arbre_verbe);
    return 0;
}



