#include <stdio.h>
#include <string.h>


int main() {
    char *string1 = "Hey";
    char *string2 = "Hey Jude";
    char *unrelated_str = "ABC";
    char dest_string[10];

    // strstr
    // returns all the substring after match. why? because it returns the pointer of the match
    printf("First result, when found something: %s\n", strstr(string2, string1));
    // if no match, returns null pointer
    printf("Second result, when not found anything: %s\n", strstr(string2, unrelated_str));

    // strcpy: result stored in first argument, dest string, that needs to be an array
    strcpy(dest_string, unrelated_str);
    printf("Was the string succesfully copied? %s\n", dest_string);

    // strcat: result is stored in first argument, that needs to be an array
    char concatenated_str[20] = "Hello C! ";
    strcat(concatenated_str, string2);
    puts(concatenated_str);

    // strlen
    printf("The length of the concatenated string is %lu\n", strlen(concatenated_str));

    // strchr, also returns a pointer
    printf("Found character location: %s", strchr(string2, 'J'));

    return 0;
}