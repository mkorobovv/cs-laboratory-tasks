#include <stdio.h>
#include <ctype.h>

int main() {
    int c, curret_number = 0;
    int found_first = 0, first_number;
    int found_last = 0, last_number;

    while ((c = getchar()) != EOF) {

        if (c != '\n') {
            if (isdigit(c)) {
                curret_number = curret_number * 10 + (c - '0');
            } else if (curret_number != 0) {
                if (!found_first) {
                    first_number = curret_number;
                    last_number = curret_number;
                    found_first = 1;
                    found_last = 1;
                } else {
                    last_number = curret_number;
                }
                curret_number = 0;
            }
        } else {
            if (curret_number != 0) {
                if (!found_first) {
                    first_number = curret_number;
                    last_number = curret_number;
                    found_first = 1;
                    found_last = 1;
                } else {
                    last_number = curret_number;
                }
            }

            // Вывод результатов
            if (found_first)
                printf("Первое десятичное число: %d\n", first_number);
            else
                printf("Первое десятичное число не найдено.\n");

            if (found_last)
                printf("Последнее десятичное число: %d\n", last_number);
            else
                printf("Последнее десятичное число не найдено.\n");

            first_number = 0;
            last_number = 0;
            found_first = 0;
            found_last = 0;
            curret_number = 0;
        }
    }
}