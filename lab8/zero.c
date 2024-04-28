#include <stdio.h>

int main() {
    int x, y, z;
    printf("Enter x, y, z: \n");
    scanf("%d %d %d", &x, &y, &z);
    int p = z * y;
    p /= 0;
    printf("p = %d", p);
}