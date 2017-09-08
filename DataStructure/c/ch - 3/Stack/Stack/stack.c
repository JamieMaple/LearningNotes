#include "stack.h"

/*
 * create Stack
 * params: void
 * return Stack pointer (void)
 */
Stack CreateStack(void) {
    Stack head = NULL;
    
    head = (Stack)malloc(sizeof(Node));
    if (head != NULL) {
        head -> next = NULL;
    }
    
    return head;
}
/*
 * check if empty
 * params: Stack pointer
 * return bool
 */
bool IsEmpty(Stack stack) {
    return stack -> next == NULL;
}
/*
 * free all the stack
 * params: Stack pointer
 * return void
 */
void DisposeStack(Stack stack) {
    Stack tempCell;
    Stack nextCell;
    
    tempCell = stack -> next;
    stack -> next = NULL;
    
    while (tempCell != NULL) {
        nextCell = tempCell -> next;
        free(tempCell);
        tempCell = nextCell;
    }
}
/*
 * add item to the last node
 * params: Stack pointer
 */
void Push(Stack stack, ElementType element) {
    Stack tempCell;
    tempCell = (Stack)malloc(sizeof(Node));
    if (tempCell != NULL) {
        tempCell -> Element = element;
        tempCell -> next = stack -> next;
        stack -> next = tempCell;
    }
}
/*
 * remove the last node
 * params: Stack pointer
 * return void
 */
void Pop(Stack stack) {
    if (!IsEmpty(stack)) {
        Stack frontCell = stack -> next;
        stack -> next = frontCell -> next;
        free(frontCell);
    }
}
/*
 * get the top element
 * params: Stack pointer
 * return ElementType
 */
ElementType Top(Stack stack) {
    if (!IsEmpty(stack)) {
        return stack -> next -> Element;
    }
    return 0;
}





































