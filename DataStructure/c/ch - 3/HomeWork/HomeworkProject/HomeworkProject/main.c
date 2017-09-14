#include "testHeader.h"

int main(void) {
    DoublyList testList = CreateList();
    
    for (int i = 0; i < 5; i++) {
        AppendNode(testList, i + 1);
    }
    puts("外部testList地址");
    SwapNeighborNode(testList, 5);
    printf("* list: %p\n** list: %p\n", testList, &testList);
    DisposeList(testList);
    
    puts("\n\n\n");
    
    int a = 1;
    int *p1, *p2;
    p1 = &a;
    p2 = &a;
    
    printf("a 自身地址%p\n", &a);
    printf("p1 内部存放的地址：%p, p2 内部存放的地址：%p\n", p1, p2);
    printf("p1 自身地址：%p，p2自身地址：%p\n", &p1, &p2);
    puts("\n\n\n");
    
    return 0;
}
