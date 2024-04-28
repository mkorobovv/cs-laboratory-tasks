#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> 

#define VOWELS (1u << ('a'-'a') | 1u << ('e'-'a') | 1u << ('i'-'a') | 1u << ('o'-'a') | 1u << ('u'-'a'))

int isVowel(int c) {
    c = tolower(c);
    return VOWELS & (1u << (c - 'a'));
}

int main() {
    int c;
    bool temp = true;
    bool check = false;
    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            if (temp) 
                check = true;
            temp = true;
        }
        else {
            if (!isVowel(c)) {
                temp = false;
            }
        }
    }

    if (check) printf("\nТакое слово есть");
    else printf("\nТакого слова нет");

    return 0;
}