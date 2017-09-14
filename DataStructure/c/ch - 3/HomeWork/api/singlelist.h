#include "std.h"

typedef struct single_list * SingleList, SingleListNode;

SingleList CreateList(void);

bool FindNode(SingleList, ELementType);

bool AppendNode(SingleList, ELementType);

ELementType Insert(SingleList, ELementType);

bool DeleteNode(SingleList, ELementType);

void DisposeSingleList(SingleList L);

void ForEachListNode(SingleList, void (*p)(SingleList));