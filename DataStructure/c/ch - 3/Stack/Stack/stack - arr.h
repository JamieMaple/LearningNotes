//
//  stack - arr.h
//  Stack
//
//  Created by Jamie on 9/7/17.
//  Copyright © 2017 Jamie. All rights reserved.
//

#ifndef stack___arr_h
#define stack___arr_h

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

Stack CreateStack(int max);

void DisposeStack(Stack);

void Push(Stack);

void Pop(Stack);

ElementType Top(Stack);

ElementType TopAndPop(Stack);

#endif /* stack___arr_h */







































