#include "std.h"

typedef struct single_list_arr * SingleListArr, SingleListArrNode;

SingleListArr CreateList(int, int);

bool IsFull(SingleListArr);

bool IsEmpty(SingleListArr);

bool AppendNode(SingleListArr, ELementType);

void DisposeList(SingleListArr);