//
// Created by lucas on 09/11/2022.
//

#include "node.h"
#include <stdlib.h>
#include <stdio.h>

p_node createNode(int val)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->value = val;
    nouv->left = nouv->right = NULL;

    return nouv;
}

void print_node(p_node p){
    printf("val : %d \n",p->value);
    printf("left : %d \n right : %d\n", p->left->value , p->right->value);


}