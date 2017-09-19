#ifndef _AVLtree_h_

#define _AVLtree_h_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;

struct AVL
{
    struct AVL * leftChild;
    struct AVL * rightChild;
    int height;
    ElementType element;
};

typedef struct AVL *AVLtree, AVLnode;

AVLtree CreateAVLtree(void);

AVLtree Find(AVLtree, ElementType);

AVLtree FindMax(AVLtree);

AVLtree FindMin(AVLtree);

bool InsertNode(AVLtree, ElementType);

bool DeleteNode(AVLtree, ElementType);

void DisposeTree(AVLtree);

#endif