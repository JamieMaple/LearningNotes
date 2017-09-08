#include "stackArr.h"
/*
 * create a Stack
 * params: maxSize
 * return Stack Node
 */
Stack CreateStack(int MaxStackSize) {
    Stack S;
    MaxStackSize--;
    
    if (MaxStackSize < MinStackSize) {
        return NULL;
    }
    S = (Stack)malloc(sizeof(struct StackRecord));
    if (S -> array != NULL) {
        S -> array = (ElementType *)malloc(sizeof(ElementType) * MaxStackSize);
        S -> Capacity = MaxStackSize;
        S -> TopOfStack = EmptyTOS;
    }
    
    return S;
}
/*
 * check if it is empty
 * params: Stack Node
 * return bool
 */
bool IsEmpty(Stack S) {
    return S -> TopOfStack == EmptyTOS;
}
/*
 * check if it is full
 * params: Stack Node
 * return bool
 */
bool IsFull(Stack S) {
    return S -> Capacity <= S -> TopOfStack;
}
/*
 * free dispose the stack
 * params: Stack Node
 * return void
 */
void DisposeStack(Stack S) {
    if(S != NULL) {
        free(S -> array);
        S -> TopOfStack = EmptyTOS;
        free(S);
    }
}
/*
 * add item to the top
 * params: Stack Node
 * return void
 */
void Push(Stack S, ElementType element) {
    if (!IsFull(S)) {
        S -> array[++S->TopOfStack] = element;
    }
}
/*
 * free the top item
 * params: Stack Node
 * return void
 */
void Pop(Stack S) {
    if (!IsEmpty(S)) {
        S -> TopOfStack --;
    }
}
/*
 * get the top Element
 * param: Stack Node
 * return Top Element
 */
ElementType Top(Stack S) {
    return S -> array[S -> TopOfStack];
}
/*
 * get the top and free the top
 *
 *
 */
ElementType TopAndPop(Stack S) {
    ElementType temp = EmptyTOS;
    
    if (!IsEmpty(S)) {
        temp = S -> array[S -> TopOfStack];
        S -> TopOfStack --;
    }
    
    return temp;
}










































