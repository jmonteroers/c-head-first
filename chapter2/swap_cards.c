#include <stdio.h>

int main() {
    const char *cards = "JQK";
    char a_card = cards[2];
    // memory error, can't overwrite the string literal since it's read-only
    // that's why it's better to use const for your string literals!
    // cards[1] = a_card;
    printf("The shuffled card is %c\n", a_card);
    return 0;
}