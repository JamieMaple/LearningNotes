#include "api/doublylist.h"

int main(void) {
  DoublyList testList = CreateList();

  for (int i = 0; i < 10; i++) {
    AppendNode(testList, i + 1);
  }

  SwapNeighborNode(testList, 5);
  
  DisposeList(testList);

  return 0;
}