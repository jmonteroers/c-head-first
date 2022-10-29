#include <stdio.h>
#include <string.h>


char tracks[][80] = {
    "I left my heart in Harvard Med School",
    "Newark - a wonderful town",
    "Dancing with a Dork"
};

void find_track(char search_for[])
{
    for (int i = 0; i < sizeof(tracks)/sizeof(*tracks); i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

int main() 
{
    char search_for[80];
    printf("Search for: ");
    scanf("%79s", search_for);
    // add sentinel char
    // search_for[strlen(search_for) -1] = '\0';
    find_track(search_for);
    return 0;
}