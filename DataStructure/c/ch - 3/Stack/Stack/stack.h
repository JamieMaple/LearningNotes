#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;
struct node_s {
    ElementType Element;
    struct node_s * next;
};
typedef struct node_s Node;
typedef struct node_s * Stack;

/* api */

Stack CreateStack(void);
bool IsEmpty(Stack);
void DisposeStack(Stack);
void MakeEmpty(Stack);
ElementType Top(Stack);
void Push(Stack, ElementType);
void Pop(Stack);
ElementType Top(Stack);

#endif /* stack_h */
