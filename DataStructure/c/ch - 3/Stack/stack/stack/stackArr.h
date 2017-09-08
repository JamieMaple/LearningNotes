#ifndef stack_arr_h
#define stack_arr_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType * array;
};

typedef struct StackRecord * Stack;

#define EmptyTOS     ( -1 )
#define MinStackSize (  5 )

bool IsEmpty(Stack);

bool IsFull(Stack);

Stack CreateStack(int);

void DisposeStack(Stack);

void Push(Stack, ElementType);

void Pop(Stack);

ElementType Top(Stack);

ElementType TopAndPop(Stack);

#endif /* stack_arr_h */







































