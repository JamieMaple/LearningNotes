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
    struct single_list * previous;
};
struct single_list_arr {
    int length;
    int size;
    ELementType * element;
};
struct stact_list {
    ELementType element;
    struct stack_list * next;
};
struct queue_list {
    ELementType element;
    struct queue_list * next;
};

#endif
