#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue queueTest = CreateQueue(10);
    
    for (int i = 0; i < 16; i++) {
        Enqueue(i+1, queueTest);
    }
    
    printf("font - %d\n", Front(queueTest));
    printf("rear - %d\n", Rear(queueTest));
    for (int i = 0; i < Capacity(queueTest); i++) {
        printf("Queue %d : %d\n", i + 1, queueTest -> Array[i]);
    }
    for (int i = 0; i < 10; i++) {
        printf("Dequeue     ");
        Dequeue(queueTest);
        printf("font - %d   ", Front(queueTest));
        printf("rear - %d   ", Rear(queueTest));
        printf("size - %d\n", queueTest -> size);
    }
    printf("font - %d\n", Front(queueTest));
    printf("rear - %d\n", Rear(queueTest));
    
    DisposeQueue(queueTest);
    
    return 0;
}
