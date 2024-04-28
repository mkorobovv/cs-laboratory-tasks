#include <stdio.h>

#define MAX_SIZE 7

// Функция для проверки, содержится ли элемент в массиве
int contains(int arr[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int uniqueCols[MAX_SIZE]; // Массив для хранения информации о том, был ли уже скопирован столбец
    int rows, cols;

    int uniqueCount = 0;  // Количество найденных уникальных столбцов

    printf("Введите количество строк и столбцов матрицы (не более %d каждого): ", MAX_SIZE);
    scanf("%d %d", &rows, &cols);

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Проверяем каждый столбец на уникальность
    for (int j = 0; j < cols; ++j) {
        int isUnique = 1; // Предполагаем, что столбец уникален

        // Проверяем столбец на наличие в массиве уникальных столбцов
        for (int k = 0; k < uniqueCount; ++k) {
            int same = 1; // Предполагаем, что столбец совпадает с уже найденным
            for (int i = 0; i < rows; ++i) {
                if (matrix[i][j] != matrix[i][uniqueCols[k]]) {
                    same = 0; // Столбец не совпадает
                    break;
                }
            }
            if (same) {
                isUnique = 0; // Столбец не уникален
                break;
            }
        }

        // Если столбец уникален, добавляем его в массив уникальных столбцов
        if (isUnique) {
            uniqueCols[uniqueCount] = j;
            uniqueCount++;
        }
    }

    printf("Уникальные столбцы матрицы:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < uniqueCount; ++j) {
            printf("%d ", matrix[i][uniqueCols[j]]);
        }
        printf("\n");
    }

    return 0;
}