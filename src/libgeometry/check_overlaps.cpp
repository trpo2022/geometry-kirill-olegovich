#include "check_overlaps.h"
#include <libgeometry/check_shape.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int overlaps_circle_circle(circle c1, circle c2)
{
    float d = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));

    if ((d <= c1.r - c2.r) || (d <= c2.r - c1.r) || (d <= c1.r + c2.r))
        return 1;
    return 0;
}
