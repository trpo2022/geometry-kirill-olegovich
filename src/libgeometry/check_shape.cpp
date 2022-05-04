#include "check_shape.h"
#include <ctype.h>
#include <libgeometry/print.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

vector<circle> circles;
vector<triangle> triangles;

circle make_circle(float x, float y, float r)
{
    circle temp = {x, y, r};
    return temp;
}

triangle
make_triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    triangle temp = {x1, y1, x2, y2, x3, y3};
    return temp;
}

int check_circle(char str[], char re[])
{
    float x, y, r;
    char temp;

    if (3 != sscanf(str, "%*[^(](%f %f, %f)%1[^\n]", &x, &y, &r, &temp)) {
        printf("Invalid input!\n");
        return 1;
    }

    if (x < 0 || y < 0 || r < 0) {
        printf("Invalid input!\n");
        return 1;
    }

    circles.push_back(make_circle(x, y, r));
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

    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x3 < 0 || y3 < 0 || x4 < 0
        || y4 < 0) {
        printf("Invalid input!\n");
        return 1;
    }

    triangles.push_back(make_triangle(x1, y1, x2, y2, x3, y3));
    print_triangle(re, x1, y1, x2, y2, x3, y3, x4, y4);

    return 0;
}
