#ifndef _std_h_
#define _std_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Error(str) fprintf(stderr, "%s\n", str), exit(1);
#define FatalError(str) Error(str)

typedef int ELementType;

struct single_list {
    ELementType element;
    struct single_list * next;
};
struct stact_list {
    ELementType element;
    struct stack_list * next;
};
struct queue_list {
    ELementType element;
    struct queue_list * next;
};


typedef struct single_list * SingleList, SingleListNode;
typedef struct stack_list * Stack, StackNode;
typedef struct queue_list * Queue, QueueNode;


#endif
