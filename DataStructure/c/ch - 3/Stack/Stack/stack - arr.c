#include "stack - arr.h"
/*
 * create a Stack
 * params: maxSize
 * return Stack Node
 */
Stack CreateStack(int MaxStackSize) {
    Stack S;
    
    if (MaxStackSize < MinStackSize) {
        return NULL;
    }
    S = (Stack)malloc(sizeof(struct StackRecord));
    S -> array = (ElementType *)malloc(sizeof(ElementType));
    
    return S;
}
/*
 * check if it is empty
 * params: Stack Node
 * return bool
 */
bool IsEmpty(Stack S) {
    return S -> array == NULL;
}






































