#include <stdio.h>

typedef unsigned long ulong;  // 现在 ulong 就是 unsigned long 的别名

int main() {
    ulong big_number = 1234567890;  // 等同于 unsigned long big_number = 1234567890;
    printf("%lu\n", big_number);
    return 0;
}