#include "single-linkedList.h"

/*
 * Create List 
 * params: no
 * retrun Node head pointer
 */
List CreateList() {
    List head;
    head = malloc(sizeof(Node));
    head -> next = NULL;
    
    return head;
}
/*
 * Add Item to the last
 * params: Node head pointer, data: num
 * return bool
 */
bool AddItem(const List list, int num) {
    List tempList = list;
    List end;
    
    while (tempList -> next != NULL) {
        tempList = tempList -> next;
    }
    
    end = (List)malloc(sizeof(Node));
    tempList -> next = end;
    
    if (end == NULL) {
        
        return false;
    } else {
        end -> num = num;
        end -> next = NULL;
        
        return true;
    }
}
/*
 * check the list if is empty
 * params: Node head pointer
 * return bool
 */
bool IsEmpty(const List list) {
    return list -> next == NULL;
}
/*
 * is it the last node pointer
 * params: Node pointer
 * return bool
 */
bool IsLast(const List list) {
    return list -> next == NULL;
}
/*
 * get the num of all nodes except head node
 * params: Node pointer, data: num
 * return int
 */
int ListLength(const List list) {
    List tempNode = list;
    int length = 0;
    
    while (tempNode -> next != NULL) {
        length++;
        tempNode = tempNode -> next;
    }
    
    return length;
}
/*
 * insert an element to some place
 * params: previous Node pointer, data: num
 * return insertion Node pointer
 */
List InsertToList(const List prev, int num) {
    List insertion;
    
    insertion = (List)malloc(sizeof(Node));
    if (insertion == NULL) {
        return NULL;
    }
    insertion -> num = num;
    if (IsLast(prev)) {
        prev -> next = insertion;
    } else {
        List temp;
        temp = prev -> next;
        prev -> next = insertion;
        insertion -> next = temp;
    }
    
    return insertion;
}
/*
 * free all the malloc
 * params: List head node
 * return void
 */
/* still remain a question -- 野指针已解决 */
void FreeAllList(List list) {
    List  current;
    List tempNodePointer;
    
    current = list -> next;
    list -> next = NULL;
    
    while (current != NULL) {
        tempNodePointer = current -> next;
        free(current);
        current = tempNodePointer;
    }
}
/*
 * find previous node 
 * params: List head node,
 * return Previous List node or not found than Last List node
 */
List FindPrevious(List list, int num) {
    List previous = list;
    
    while (previous != NULL && previous -> next != NULL) {
        if ((previous -> next) -> num == num) {
            return previous;
        }
        
        previous = previous -> next;
    }
    
    return previous;
}
/*
 * find an element
 * params: List head node, data int
 * return List node or NULL
 */
List FindList(const List list, int num) {
    
    List previous = FindPrevious(list, num);
    
    return previous -> next;
}

bool static IsLast(const List list) {
    return list -> next == NULL;
}
/*
 * delete an element
 * params: List head node, element num
 * return
 */
bool DeleteNode(const List list, ElementType num) {
    bool isDeleted = false;
    
    List previous = FindPrevious(list, num);
    if (!IsLast(previous)) {
        List deleted = previous -> next;
        previous -> next = deleted -> next;
        free(deleted);
        isDeleted = true;
    }
    
    return isDeleted;
}




































