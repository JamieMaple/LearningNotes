#ifndef linkedListArr_h
#define linkedListArr_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*  */
typedef int List;

typedef int ElementType;
/* position -- next or previous */
typedef int Position;

struct node {
    ElementType Element;
    Position Next;
};

void InitializeCursorSpace(void);

List MakeEmpty(List);

bool IsEmpty(const List);

bool IsLast(const List);

Position Find(const ElementType, const List);

void Delete(List);

Position FindPrevious(ElementType, const List);

void Insert(ElementType, List, Position);

void Deletelist(List);

Position head(const List);

Position First(const Position);

Position Advance(const Position);

ElementType Retrieve(const Position);



#endif /* linkedListArr_h */
