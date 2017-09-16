#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

struct node {
    int num;
    struct node * next;
};

typedef struct node * List, Node;

List CreateList();

bool IsEmpty(const List);

bool IsLast(const List);

int ListLength(List);

bool AddItem(const List, int);

List FindList(const List, int);

List FindPrevious(const List, int);

List InsertToList(const List, int);

bool DeleteNode(const List, int);
void FreeAllList(List);

#endif
