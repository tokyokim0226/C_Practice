#include <stdio.h>


void increment(int*);

int main () {
    int a = 16;
    increment(&a);
    printf("%d\n",a);
    return 0;
}

void increment(int *n) {
    *n += 1;
}