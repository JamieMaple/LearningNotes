#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

struct QueueRecord {
    int Capacity;
    int front;
    int rear;
    int size;
    ElementType *Array;
};

typedef struct QueueRecord * Queue;

bool IsEmpty(Queue);

bool IsFull(Queue);

Queue CreateQueue(int);

void MakeEmpty(Queue);

void DisposeQueue(Queue);

void Enqueue(ElementType, Queue);

void Dequeue(Queue);

ElementType Front(Queue);
ElementType Rear(Queue);

ElementType FrontAndDequeue(Queue);

int Capacity(Queue);

#define MinSize 5

#endif /* queue_h */

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
