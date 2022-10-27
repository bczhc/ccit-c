//
// Created by bczhc on 25/10/22.
//

#include <stdio.h>

int main() {
    int a, b;
    printf("请输入矩形的长和宽："), fflush(stdout);
    // TODO: invalid input and out of range handling
    scanf("%d %d", &a, &b); // NOLINT(cert-err34-c)
    printf("矩形的面积是：%d\n", a * b);

    return 0;
}