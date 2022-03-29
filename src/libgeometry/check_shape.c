#include "check_shape.h"
#include <ctype.h>
#include <libgeometry/print.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_circle(char str[], char re[])
{
    float x, y, r;
    char temp;

    if (3 != sscanf(str, "%*[^(](%f %f, %f)%1[^\n]", &x, &y, &r, &temp)) {
        printf("Invalid input!\n");
        return 1;
    }

    print_circle(re, x, y, r);

    return 0;
}

int check_triangle(char str[], char re[])
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
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
        return 1;
    }

    if (x1 != x4 || y1 != y4) {
        printf("Invalid input!\n");
        return 1;
    }

    print_triangle(re, x1, y1, x2, y2, x3, y3, x4, y4);

    return 0;
}
