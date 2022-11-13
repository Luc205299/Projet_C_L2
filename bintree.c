//
// Created by lucas on 09/11/2022.
//
#include <string.h>
#include "bintree.h"
#include <stdio.h>
tree create_tree()
{
    tree arbre = malloc(sizeof(t_node));
    arbre->lettre = ' ';
    arbre->LaChaireDeMaChaire = NULL;
    arbre->reuf = NULL;
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
                while (base[i] != node_tmp->lettre && node_tmp->reuf != NULL)
                {
                    node_tmp = node_tmp->reuf;
                }
                if (node_tmp->lettre != base[i])
                {
                    node_tmp->reuf = create_node(base[i]);
                    node_tmp = node_tmp->reuf;
                }
                if (base[i+1] != '\0')
                {
                    if (node_tmp->LaChaireDeMaChaire == NULL)
                    {
                        node_tmp->LaChaireDeMaChaire = create_node(base[i+1]);
                    }
                    node_tmp = node_tmp->LaChaireDeMaChaire;
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
            node = node->reuf;
            if (node == NULL)
            {
                printf("Aucun mot ne correspond a votre recherche.");
                return 0;
            }
        }
        node = node->LaChaireDeMaChaire;
        i++;
    }
    if (node == NULL)
    {
        printf("%s",mot);
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

    recherche_base_part2(node->reuf);
    recherche_base_part2(node->LaChaireDeMaChaire);

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
    print2DUtil(toto->reuf, space);

    // Print current node after space
    // count

    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", toto->lettre);

    // Process left child
    print2DUtil(toto->LaChaireDeMaChaire, space);
}

void print2D(p_node toto)
{
    // Pass initial space count as 0
    print2DUtil(toto, 0);
}
