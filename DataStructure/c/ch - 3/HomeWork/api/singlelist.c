#include "singlelist.h"
SingleList CreateList(void) {
  SingleList head = (SingleList)malloc(sizeof(SingleListNode));

  if (head != NULL) {
    head -> next = NULL;
    return head;
  } else {
    Error("Create Failed");
  }
}

bool IsEmpty(SingleList L) {
  return L -> next == NULL;
}

bool AppendNode(SingleList L, ELementType element) {
  SingleList lastNode = L -> next;
  SingleList tempNode = (SingleList)malloc(sizeof(SingleListNode));

  if (tempNode == NULL) {
    return false;
  } else {
    while(lastNode -> next != NULL) {
      lastNode = lastNode -> next;
    }
    lastNode -> next = tempNode;
    tempNode -> element = element;
  }
  return true;
}

bool FindNode(SingleList L, ELementType element) {
  SingleList current = L -> next;
  while(current != NULL) {
    if (current -> element == element) {
      return true;
    }
    current = current -> next;
  }

  return false;
}

ELementType Insert(SingleList previous, ELementType element) {
  SingleList tempNode = (SingleList)malloc(sizeof(SingleListNode));

  if (tempNode == NULL) {
    FatalError("Insertion failed");
  } else {
    tempNode -> element = element;
    tempNode -> next = previous -> next;
    previous -> next = tempNode;
  }

  return element;
}