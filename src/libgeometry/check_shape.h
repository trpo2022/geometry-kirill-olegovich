#ifndef TEST
#define TEST

#include <vector>

using namespace std;

struct circle {
    float x, y, r;
};

struct triangle {
    float x1, y1, x2, y2, x3, y3;
};

extern vector<circle> circles;
extern vector<triangle> triangles;

int check_circle(char str[], char re[]);
int check_triangle(char str[], char re[]);
circle make_circle(float x, float y, float r);
triangle
make_triangle(float x1, float y1, float x2, float y2, float x3, float y3);

#endif
