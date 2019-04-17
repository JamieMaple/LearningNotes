#include "Chapter6.h"

unsigned int fact(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0) {
        return 1;
    }

    int val = 1;
    while (n > 1) {
        val *= n--;
    }

    return val;
}

