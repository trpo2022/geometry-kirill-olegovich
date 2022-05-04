#include <ctype.h>
#include <iostream>
#include <libgeometry/check_overlaps.h>
#include <libgeometry/check_shape.h>
#include <libgeometry/print.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(void)
{
    int n_str = 50;
    int n_re = 10;
    char str[n_str];
    char re[n_re];

    while (1) {
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';

        if (strcmp(str, "stop") == 0)
            break;

        sscanf(str, "%[^(]%*[\n]", re);

        for (int i = 0; re[i]; i++)
            re[i] = tolower(re[i]);

        if (strcmp(re, "circle") == 0) {
            check_circle(str, re);

        } else if (strcmp(re, "triangle") == 0) {
            check_triangle(str, re);

        } else
            printf("Invalid input!\n");
    }

    for (long unsigned int i = 0; i < circles.size(); i++) {
        for (long unsigned int j = i + 1; j < circles.size(); j++) {
            if (overlaps_circle_circle(circles[i], circles[j])) {
                cout << "Circle " << i + 1 << " overlaps with circle " << j + 1
                     << endl;
            }
        }
    }

    return 0;
}
