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
    int number_titles = sizeof(titles)/sizeof(titles[0]);
    printf("Number of titles in database %i\n", number_titles);
    puts("Welcome to the Search Title programme");
    // if title is Exit, then leave loop
    char search[80];
    do {
        puts("Search keyword: ");
        scanf("%79s", search);
        if (!strcmp(search, "Exit")) {
            puts("Exiting...");
            continue;
        }
        int some_found = 0;
        for (int i=0; i < number_titles; i++) {
            if (strstr(titles[i], search)) {
                printf("Found match %s\n", titles[i]);
                some_found = 1;
            }
        }
        if (!some_found) {
            puts("No title found, try again.");
        }
    } while (strcmp(search, "Exit"));

    return 0;
    
}