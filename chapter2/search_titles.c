#include <stdio.h>
#include <string.h>

int main(){
    char titles[][80] = {
        "Elvis",
        "Star Trek",
        "Buzz Lightyear",
        "Star Wars",
        "Collateral"
    };
    // `sizeof` returns size in bytes
    int number_titles = sizeof(titles)/sizeof(titles[0]);
    
    puts("Welcome to the Search Title programme");
    printf("Number of titles in database %i\n", number_titles);
    // if title is Exit, then leave loop
    char search[80];
    do {
        puts("Search keyword: ");
        // scanf splits words by spaces
        scanf("%79s", search);
        // strcmp is true only if they don't match
        // this reads as 'if they match'
        if (!strcmp(search, "Exit")) {
            puts("Exiting...");
            continue;
        }
        // In C, we use ints as booleans
        int some_found = 0;
        for (int i=0; i < number_titles; i++) {
            if (strstr(titles[i], search)) {
                printf("Found match %s\n", titles[i]);
                some_found = 1;
            }
        }
        if (!some_found) {
            printf("No title found that matches '%s', please try again.\n", search);
        }
    } while (strcmp(search, "Exit"));

    return 0;
    
}