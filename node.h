//
// Created by lucas on 09/11/2022.
//

#ifndef UNTITLED2_NODE_H
#define UNTITLED2_NODE_H

struct s_node
{
    int value;
    struct s_node   *left, *right;
    int depth;
};

typedef struct s_node t_node, *p_node;

p_node createNode(int);
#endif //UNTITLED2_NODE_H
