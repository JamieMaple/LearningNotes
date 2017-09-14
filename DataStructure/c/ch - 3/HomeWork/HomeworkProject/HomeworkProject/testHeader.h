#include "std.h"
typedef struct single_list * DoublyList, DoublyListNode;

DoublyList CreateList(void);
bool AppendNode(DoublyList, ELementType);
// 交换前面和这个元素
bool SwapNeighborNode(DoublyList, ELementType);

void DisposeList(DoublyList);
