#include <stdio.h>
#include "single-linkedList.h"
void displayList(const List);
void test(int*);

int main(void) {
    List list1 = CreateList();
    // empty test
    printf("Is the list empty：%d\n", IsEmpty(list1));
    // is last
    printf("Is last list: %d\n", IsLast(list1));
    /***********
    ** create **
    ***********/
    // add and insert test
    for (int i = 0; i < 20; i++) {
        AddItem(list1, i);
        if  (i == 1) {
            InsertToList(list1, 10);
        }
    }
    displayList(list1);
    /**********
     ** read **
     **********/
    // found test
    List found1 = FindList(list1, 11);
    if (found1 != NULL) {
        printf("%p is %d\n", found1, found1 -> num);
    }
    found1 = FindPrevious(list1, 11);
    if (!IsLast(found1)) {
        printf("%p is %d\n", found1, found1 -> num);
    }
    /************
     ** delete **
     ***********/
    // delete test
    DeleteNode(list1, 2);
    displayList(list1);
    
    /* last operation */
    
    // free test
    FreeAllList(list1);
    
    return 0;
}

/* some other function */
void displayList(const List list) {
    if (list == NULL) {
        return;
    }
    List tempList = list -> next;
    int i = 0;
    while (tempList != NULL) {
        printf("第%d个是%d\n", ++i, tempList -> num);
        tempList = tempList -> next;
    }
}











