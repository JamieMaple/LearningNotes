#include "stackArr.h"
int main(void) {
    Stack testStack = CreateStack(10);
    
    for (int i = 0; i < 20; i++) {
        Push(testStack, i+1);
    }
    
    for (int i = testStack -> TopOfStack; i > -1; i--) {
        printf("%p - %d\n", &(testStack -> array[i]), testStack -> array[i]);
    }
    puts("");
    for (int i = testStack -> TopOfStack; i > -1; i--) {
        printf("%p - %d\n", &(testStack -> array[i]), testStack -> array[i]);
    }
    
    DisposeStack(testStack);
    
    return 0;
}
