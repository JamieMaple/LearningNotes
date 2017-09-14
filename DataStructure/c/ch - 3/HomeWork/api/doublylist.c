#include "doublylist.h"

DoublyList CreateList(void) {
  DoublyList L = (DoublyList)malloc(sizeof(DoublyListNode));
  if (L == NULL) {
      FatalError("No space");
  }
  
  L -> previous = NULL;
  L -> next = NULL;
  
  return L;
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
  // 由于交换的是后面的元素与前面的元素
  if (muchNext != NULL) {
    muchNext -> previous = previousNode;
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
}
void DestroyList(DoublyList * L) {
  free(*L);
}