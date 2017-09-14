#include "api/singlelistArr.h"

#define SIZE 10
#define INCREASE 10

void PrintLots(SingleListArr listNode, int position) {
  printf("%d个元素的值是%d\n", position, listNode -> element[position - 1]);
}

int main(void) {
  SingleListArr testList = CreateList(SIZE, INCREASE);
  int group[] = {1, 3, 4, 6};

  for (int i = 0; i < 8; i++) {
    AppendNode(testList, i);
  }

  for (int i = 0; i < 4; i++) {
    PrintLots(testList, group[i]);
  }

  DisposeList(testList);

  return 0;
}