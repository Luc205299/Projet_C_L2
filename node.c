//
// Created by lucas on 09/11/2022.
//

#include "node.h"
#include <stdlib.h>
#include <stdio.h>


p_node create_node(char lettre)
{
    p_node nouveau_fiston = malloc(sizeof(t_node));
    nouveau_fiston->frere = NULL;
    nouveau_fiston->fils = NULL;
    nouveau_fiston->lettre = lettre;
    nouveau_fiston->flechie = NULL;
    return nouveau_fiston;

}