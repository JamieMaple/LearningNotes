#include "singlelist.h"

SingleList CreateList(void) {
  SingleList head = (SingleList)malloc(sizeof(SingleListNode));

  if (head != NULL) {
    head -> next = NULL;
    return head;
  } else {
    FatalError("Create Failed");
  }
}

bool IsEmpty(SingleList L) {
  return L -> next == NULL;
}

bool AppendNode(SingleList L, ELementType element) {
  SingleList lastNode = L;
  SingleList tempNode = (SingleList)malloc(sizeof(SingleListNode));

  if (tempNode == NULL) {
    return false;
  } else {
    while(lastNode -> next != NULL) {
      lastNode = lastNode -> next;
    }
    tempNode -> element = element;
    tempNode -> next = NULL;

    lastNode -> next = tempNode;
  }
  return true;
}

static SingleList FindPrevious(SingleList L, ELementType element) {
  SingleList tempNode = L -> next;
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

bool FindNode(SingleList L, ELementType element) {
  SingleList previous = FindPrevious(L, element);

  if (previous -> next == NULL) {
    return false;
  } else {
    return true;
  }
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

bool DeleteNode(SingleList L, ELementType element) {
  SingleList previous = FindPrevious(L, element);
  SingleList current  = previous -> next;
  
  // no this element exist
  if (previous -> next == NULL) {
    FatalError("No that element exist!");
  }

  previous -> next = current -> next;
  free(current);

  return true;
}

void DisposeSingleList(SingleList L) {
  SingleList current = L -> next;

  while (current != NULL) {
    SingleList temp = current -> next;
    free(current);
    current = temp;
  }

  L -> next = NULL;
}

void ForEachListNode(SingleList L, void (*p)(SingleList L)) {
  (*p)(L);
}

