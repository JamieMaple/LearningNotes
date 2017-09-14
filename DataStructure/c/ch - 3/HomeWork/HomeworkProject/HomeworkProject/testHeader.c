#include "testHeader.h"
DoublyList CreateList(void) {
    DoublyList L = (DoublyList)malloc(sizeof(DoublyListNode));
    printf("malloc 分配的地址：%p\n", L);
    if (L == NULL) {
        FatalError("No space");
    }
    
    L -> previous = NULL;
    L -> next = NULL;
    
    return L;
}

static bool IsEmpty(DoublyList L) {
    return L -> next == NULL;
}
static DoublyList FindPrevious(DoublyList L, ELementType element) {
    DoublyList tempNode = L -> next;
    if (IsEmpty(L)) {
        FatalError("Empty List");
    } else {
        while (tempNode -> next != NULL) {
            if (tempNode -> element == element) {
                break;
            }
            tempNode = tempNode -> next;
        }
    }
    
    return tempNode;
}

bool SwapNeighborNode(DoublyList L, ELementType element) {
    DoublyList previousNode = FindPrevious(L, element);
    DoublyList currentNode = previousNode -> next;
    if (currentNode == NULL) {
        return false;
    }
    
    DoublyList muchPrevious = previousNode -> previous;
    DoublyList muchNext = currentNode -> next;
    
    muchPrevious -> next = currentNode;
    currentNode -> previous = muchPrevious;
    
    currentNode -> next = previousNode;
    previousNode -> previous = currentNode;
    
    previousNode -> next = muchNext;
    muchNext -> previous = previousNode;
    
    return true;
}

bool AppendNode(DoublyList L, ELementType element) {
    DoublyList lastNode = L;
    DoublyList tempNode = (DoublyList)malloc(sizeof(DoublyListNode));
    
    if (tempNode == NULL) {
        return false;
    } else {
        while(lastNode -> next != NULL) {
            lastNode = lastNode -> next;
        }
        tempNode -> element = element;
        
        tempNode -> next = NULL;
        
        tempNode -> previous = lastNode;
        lastNode -> next = tempNode;
    }
    return true;
}

void DisposeList(DoublyList L) {
    DoublyList current = L -> next;
    
    while (current != NULL) {
        DoublyList temp = current -> next;
        free(current);
        current = temp;
    }
    
    L -> next = NULL;
    puts("内部函数引用地址：");
    printf("* list: %p\n** list: %p\n", L, &L);
}
