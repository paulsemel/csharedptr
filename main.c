#include "shared_ptr.h"
#include <stdio.h>

int *test(void)
{
    shared int *ptr = make_shared(int, 2);
    ptr[0] = 42;
    ptr[1] = 1024;
    return reference(ptr);
}

int main(void)
{
    shared int *ptr = test();
    printf("Here is the value of ptr[0] %d and ptr[1] %d\n", ptr[0], ptr[1]);
    return 0;
}
