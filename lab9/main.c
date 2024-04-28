#include <stdio.h>

int max(int a, int b) {
    return a >= b ? a : b;
}

int min(int a, int b) {
    return a <= b ? a : b;
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int sign(int a) {
    if (a > 0) return 1;
    if (a == 0) return 0;
    return -1;
}

int main() {
    const int i_0 = -29, j_0 = 3, l_0 =  9, a = 10, b = 5;
    const int x_0 = 20, y_0 = 0;
    int i = i_0, j = j_0, l = l_0, o = 0, k;

    for (k = 1; k <= 50; k++) {
        i = ((i * max(j, l)) % 20) + ((j * min(i, l)) % 30) + k;
        j = abs(i - j + l - k) * sign(k - 10) % 20;
        l = (abs(i - j)*l - abs(j - l)*i + abs(i - l)*j)%20 - k;
        printf("k=%d i=%d j=%d l=%d\n",k, i, j, l);
        if (((float)((i-x_0)*(i-x_0))/(float)(a*a))+((float)((j-y_0)*(j-y_0))/(float)(b*b))<=1){
            o=1;
            break;
        }
    }

    if (o){
        printf("%s\n","Попадание в эллипс не более чем за 50 шагов");
        printf("%s%d\n","Время окончания = ",k);
        printf("%s%d%s%d%s\n","Конечные координаты точки: (",i,",",j,")");
        printf("%s%d\n","Значение динамического параметра движения = ",l);
    } else {
        printf("%s\n","Промах");
        printf("%s%d\n", "Время окончания = ",k);
        printf("%s%d%s%d%s\n","Конечные координаты точки: (",i,",",j,")");
        printf("%s%d\n","Значение динамического параметра движения = ",l);
    }
}