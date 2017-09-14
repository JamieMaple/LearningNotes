#include "singlelistArr.h"

SingleListArr CreateList(int size, int increase) {
  SingleListArr arrPointer = (SingleListArr)malloc(sizeof(SingleListArrNode));
  
  if (arrPointer == NULL) {
    FatalError("No space for singlelist malloc");
  }

  arrPointer -> element = (ELementType *)malloc(sizeof(ELementType) * size);
  
  if (arrPointer -> element == NULL) {
    FatalError("No space for array list");
  }

  arrPointer -> length = 0;
  arrPointer -> size = size;

  return arrPointer;
}

bool IsFull(SingleListArr L) {
  return L -> length == L -> size;
}

bool IsEmpty(SingleListArr L) {
  return L -> length == 0;
}

bool AppendNode(SingleListArr L, ELementType element) {
  if (IsFull(L)) {
    return false;
  } else {
    L -> element[L -> length] = element;
    L -> length++;
    
    return true;
  }
}

void DisposeList(SingleListArr L) {
  free(L -> element);

  L -> element = NULL;
  L -> length = 0;
  L -> size = 0;
}