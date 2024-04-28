#include <stdio.h>

#define MAX_SIZE 7

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    // Ввод размера матрицы
    printf("Введите размер квадратной матрицaы (не более %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Ввод элементов матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Элементы в заданном порядке обхода: \n");

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int direction = 0;

    while (top <= bottom && left <= right) {
        if (direction == 0) { // Moving right
            for (int i = left; i <= right; i++)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        } else if (direction == 1) { // Moving up
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][right]);
            right--;
        } else if (direction == 2) { // Moving left
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[top][i]);
            top++;
        } else if (direction == 3) { // Moving down
            for (int i = top; i <= bottom; i++)
                printf("%d ", matrix[i][left]);
            left++;
        }
        direction = (direction + 1) % 4;
    }


    return 0;
}