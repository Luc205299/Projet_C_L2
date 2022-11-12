//
// Created by lucas on 09/11/2022.
//

#ifndef UNTITLED2_BINTREE_H
#define UNTITLED2_BINTREE_H
#include "node.h"
#include <stdlib.h>

typedef p_node tree;

tree create_tree();
void empty_char(char* word, int taille);
void print2DUtil(p_node toto, int space);
void print2D(p_node toto);
tree full_tree(char* adresse, char* type);

#endif //UNTITLED2_BINTREE_H
