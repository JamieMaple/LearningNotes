#include "queue.h"
// 学习笔记：
// 这个地方是一个循环队列，
// 一个很难理解的地方是
// 初始状态 - 队首开始位于1，结束于0
// 而添加队元素时，让队尾元素扩张,扩张的时候先让尾元素下标增加1然后再扩张
static int Succ(int value, Queue Q) {
    ++value;
    /*
     * 如果由队或队首+1超出范围，即元素，让其置为0
     */
    if (value == Q -> Capacity) {
        value = 0;
    }
    
    return value;
}

bool IsEmpty(Queue Q){
    return Q -> size == 0;
}

bool IsFull(Queue Q) {
    return Q -> size == Q -> Capacity;
}

Queue CreateQueue(int maxSize) {
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    
    if(Q != NULL) {
        // init Capacity of queue
        if (maxSize < MinSize) {
            Q -> Capacity = MinSize;
        } else {
            Q -> Capacity = maxSize;
        }
        
        MakeEmpty(Q);
        Q -> Array = (ElementType*)malloc(sizeof(ElementType) * Q -> Capacity);
    }
    
    
    return Q;
}

void MakeEmpty(Queue Q) {
    Q -> size = 0;
    Q -> front = 1;
    Q -> rear = 0;
}

void DisposeQueue(Queue Q) {
    free(Q -> Array);
    Q -> Array = NULL;
    Q -> Capacity = 0;
}

void Enqueue(ElementType element, Queue Q) {
    if (!IsFull(Q)) {
        Q -> size ++;
        Q -> rear = Succ(Q -> rear, Q);
        Q -> Array[Q -> rear] = element;
    }
}

void Dequeue(Queue Q) {
    if (!IsEmpty(Q)) {
        Q -> size --;
        Q -> front = Succ(Q -> front, Q);
    }
}

// 以下两种都可以通过检测是否为空返回正确的数值，
// 当队列为空的时候可以强制退出
ElementType Front(Queue Q) {
    if (IsEmpty(Q)) {
        Error("Error! Null");
    }
    return Q -> Array[Q -> front];
}

ElementType FrontAndDequeue(Queue Q) {
    if (IsEmpty(Q)) {
        Error("Error! Null");
    }
    ElementType temp = Front(Q);
    Dequeue(Q);
    return temp;
}

ElementType Rear(Queue Q) {
    if (IsEmpty(Q)) {
        Error("Error! Null");
    }
    
    return Q -> Array[Q -> rear];
}

int Capacity(Queue Q) {
    return Q -> Capacity;
}

int ActuallySize(Queue Q) {
    return Q -> size;
}




































