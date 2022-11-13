//
// Created by lucas on 09/11/2022.
//
#include <string.h>
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

tree create_tree()
{
    tree arbre = malloc(sizeof(t_node));
    arbre->lettre = ' ';
    arbre->fils = NULL;
    arbre->frere = NULL;
    arbre->flechie = NULL;
    return arbre;
}

void empty_char(char* word, int taille)
{
    for(int i = 0; i<=taille; i++){
        word[i] = NULL;
    }
}

tree full_tree(char* adresse, char* type)
{
    int MAX = 100;
    int TAILLE_CHAR = 30;

    char* fi = adresse;
    FILE *f = fopen(fi, "r");
    char str1[MAX];
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    tree arbre = create_tree();

    while(!feof(f))
    {
        fgets(str1, sizeof(str1),f);
        int i = 0;
        int j = 0;
        int k = 0;
        char* flechie = malloc(sizeof (char)*100);
        empty_char(flechie, TAILLE_CHAR);
        char* base = (char*)malloc(sizeof(char)*100);
        empty_char(base, TAILLE_CHAR);
        char* mode = (char*)malloc(sizeof(char)*100);
        empty_char(mode, TAILLE_CHAR);


        // premier mot
        while (str1[i] != ' ' && str1[i] != '\t')
        {
            flechie[i] = str1[i];
            i++;
        }
        flechie[i+1] = '\0';
        // enlever espace et tabulation
        while (str1[i] == ' ' || str1[i] == '\t')
        {
            i++;
        }

        // deuxieme mot
        while (str1[i] != ' ' && str1[i] != '\t')
        {
            base[j] = str1[i];
            i++;
            j++;
        }
        base[i+1] = '\0';
        // enlever espace et tabulation
        while (str1[i] == ' ' || str1[i] == '\t')
        {
            i++;
        }

        // troisieme mot
        while (str1[i] != ' ' && str1[i] != '\n' && str1[i] != 0)
        {
            mode[k] = str1[i];
            i++;
            k++;
        }
        mode[i] = '\0';
        if (strstr(mode,type))
        {
            p_node node_tmp = arbre;
            for (i = 0;base[i]!='\0';i++)
            {
                while (base[i] != node_tmp->lettre && node_tmp->frere != NULL)
                {
                    node_tmp = node_tmp->frere;
                }
                if (node_tmp->lettre != base[i])
                {
                    node_tmp->frere = create_node(base[i]);
                    node_tmp = node_tmp->frere;
                }
                if (base[i+1] != '\0')
                {
                    if (node_tmp->fils == NULL)
                    {
                        node_tmp->fils = create_node(base[i+1]);
                    }
                    node_tmp = node_tmp->fils;
                }
            }
            if (node_tmp->flechie == NULL){
                node_tmp->flechie = malloc(sizeof(s_flechie));
                node_tmp->flechie->nombre_flechies = 1;
                node_tmp->flechie->forme_flechie = malloc(sizeof(char*));
                node_tmp->flechie->forme_mode = malloc(sizeof(char*));
                node_tmp->flechie->base = malloc(sizeof(char*));
            }else
            {
                node_tmp->flechie->nombre_flechies++;
                node_tmp->flechie->forme_flechie = realloc(node_tmp->flechie->forme_flechie,sizeof (char*)*node_tmp->flechie->nombre_flechies);
                node_tmp->flechie->forme_mode = realloc(node_tmp->flechie->forme_mode,sizeof(char*)*node_tmp->flechie->nombre_flechies);
                node_tmp->flechie->base = realloc(node_tmp->flechie->base,sizeof(char*)*node_tmp->flechie->nombre_flechies);
            }
            node_tmp->flechie->forme_flechie[node_tmp->flechie->nombre_flechies-1] = flechie;
            node_tmp->flechie->forme_mode[node_tmp->flechie->nombre_flechies-1] = mode;
            node_tmp->flechie->base[node_tmp->flechie->nombre_flechies-1] = base;
            //printf("%s,%s,%s\n",node_tmp->flechie->forme_flechie[node_tmp->flechie->nombre_flechies-1],node_tmp->flechie->base[node_tmp->flechie->nombre_flechies-1],node_tmp->flechie->forme_mode[node_tmp->flechie->nombre_flechies-1]);
        }


    }

    fclose(f);

    return arbre;
}


p_node recherche_base_part1(char* mot,tree arbre)
{
    p_node node = arbre;
    int i = 0;
    while(mot[i] != '\0')
    {
        while (mot[i] != node->lettre)
        {
            node = node->frere;
            if (node == NULL)
            {
                printf("Aucun mot ne correspond a votre recherche.");
                return 0;
            }
        }
        node = node->fils;
        i++;
    }
    if (node == NULL)
    {
        printf("%s\n",mot);
    }
    return node;
}

void recherche_base_part2(p_node node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->flechie != NULL)
    {
        printf("%s\n",node->flechie->base[0]);
    }

    recherche_base_part2(node->frere);
    recherche_base_part2(node->fils);

}

void base_aleatoire(tree arbre)
{
    srand(time(NULL));
    p_node node = arbre;
    while (node!= NULL)
    {
        p_node tmp = node;
        int compteur = 0;
        while (tmp->frere != NULL)
        {
            tmp = tmp->frere;
            compteur++;
        }
        int aleatoire = 0;
        if(compteur != 0)
        {
            aleatoire = rand() % compteur + 1;
        }
        for (int i = 0;i < aleatoire;i++)
        {
            node = node->frere;
        }
        if (node->flechie != NULL)
        {
            printf("%s\n",node->flechie->base[0]);
            return;
        }
        else
        {
            node = node->fils;
        }
    }
}


void print2DUtil(p_node toto, int space)
{
    int COUNT = 2;
    // Base case
    if (toto == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(toto->frere, space);

    // Print current node after space
    // count

    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", toto->lettre);

    // Process left child
    print2DUtil(toto->fils, space);
}

void print2D(p_node toto)
{
    // Pass initial space count as 0
    print2DUtil(toto, 0);
}
