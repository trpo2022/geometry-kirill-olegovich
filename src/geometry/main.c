#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    test();

    int n_str = 50;
    int n_re = 10;
    char str[n_str];
    char re[n_re];

    while (1) {
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';
        sscanf(str, "%[^(]%*[\n]", re);

        for (int i = 0; re[i]; i++)
            re[i] = tolower(re[i]);

        if (strcmp(re, "circle") == 0) {
            float x, y, r;
            char temp;

            if (3
                != sscanf(str, "%*[^(](%f %f, %f)%1[^\n]", &x, &y, &r, &temp)) {
                printf("Invalid input!\n");
                continue;
            }

            printf("Это %s, координаты: x = %.3f y = %.3f, радиус: %.3f\n",
                   re,
                   x,
                   y,
                   r);

            printf("Длина окружности: %.3f, площадь: %.3f",
                   2 * 3.14 * r,
                   r * r * 3.14);

        } else if (strcmp(re, "triangle") == 0) {
            float x1, y1, x2, y2, x3, y3, x4, y4, a, b, c;
            char temp;

            if (8
                != sscanf(
                        str,
                        "%*[^(]((%f %f, %f %f, %f %f, %f %f))%1[^\n]",
                        &x1,
                        &y1,
                        &x2,
                        &y2,
                        &x3,
                        &y3,
                        &x4,
                        &y4,
                        &temp)) {
                printf("Invalid input!\n");
                continue;
            }

            if (x1 != x4 || y1 != y4) {
                printf("Invalid input!\n");
                continue;
            }

            a = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
            b = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
            c = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

            printf("Это %s, координаты: x1 = %.3f y1 = %.3f, x2 = %.3f y2 = "
                   "%.3f, x3 = %.3f y3 = %.3f, x4 = %.3f y4 = %.3f\n",
                   re,
                   x1,
                   y1,
                   x2,
                   y2,
                   x3,
                   y3,
                   x4,
                   y4);

            printf("Периметр: %.3f, площадь: %.3f",
                   a + b + c,
                   fabs((x1 * (y2 - y3) + x2 * (y1 - y3) + x3 * (y1 - y2))
                        / 2));

        } else
            printf("Invalid input!\n");
    }

    return 0;
}
