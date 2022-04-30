#include "print.h"
#include <math.h>
#include <stdio.h>

void print_circle(char re[], float x, float y, float r)
{
    printf("Это %s, координаты: x = %.3f y = %.3f, радиус: %.3f\n",
           re,
           x,
           y,
           r);

    printf("Длина окружности: %.3f, площадь: %.3f\n",
           2 * 3.14 * r,
           r * r * 3.14);
}

void print_triangle(
        char re[],
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4)
{
    float a, b, c;

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

    printf("Периметр: %.3f, площадь: %.3f\n",
           a + b + c,
           fabs((x1 * (y2 - y3) + x2 * (y1 - y3) + x3 * (y1 - y2)) / 2));
}
