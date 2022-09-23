#include <stdio.h>

int main()
{
    int x = 100000;
    short y = x;
    // hi is the format string for short
    printf("The value of y = %hi\n", y);
    return 0;
}