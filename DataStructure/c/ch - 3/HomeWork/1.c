#include "api/singlelist.h"
#define SIZE 5
void display(SingleList);
int main(void) {
    SingleList testList = CreateList();
    
    for (int i = 0; i < SIZE; i++) {
        AppendNode(testList, i);
    }
    
    ForEachListNode(testList, display);
    
    DisposeSingleList(testList);
    
    
    return 0;
}
void display(SingleList L) {
    SingleList current = L -> next;
    for (int i = 0; current != NULL; i++) {
        printf("第%d个元素为%d\n", i+1, current -> element);
        current = current -> next;
    }
}
