//
// Created by lucas on 09/11/2022.
//

#ifndef UNTITLED2_NODE_H
#define UNTITLED2_NODE_H

struct Struct_flechie
{
    int nombre_flechies;
    char** forme_flechie;
    char** forme_mode;
    char** base;
};
typedef struct Struct_flechie s_flechie;

struct s_node
{
    char lettre;
    struct s_node *fils, *frere;
    s_flechie *flechie;
};
typedef struct s_node t_node, *p_node;


p_node create_node(char lettre);
#endif //UNTITLED2_NODE_H
