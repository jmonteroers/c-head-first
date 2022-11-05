#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
    int len = strlen(s);
    printf("Length of the string: %i\n", len);

    // pointer to last value
    char *t = s + len - 1;
    
    // while pointer is not smaller than first pointer
    // at the beginning of the string
    while ( t >= s) {
        printf("%c", *t);

        t = t - 1;
    }
    puts("\nCompleted reverse string.");
}

int main() 
{
    print_reverse("Hey");
    return 0;
}