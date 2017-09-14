#include "std.h"

typedef struct single_list * DoublyList, DoublyListNode;

DoublyList CreateList(void);
bool AppendNode(DoublyList, ELementType);
// 交换这个元素和后面的元素
bool SwapNeighborNode(DoublyList, ELementType);

void DisposeList(DoublyList);