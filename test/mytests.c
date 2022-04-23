#include <ctest.h>
#include <libgeometry/check_shape.h>
#include <libgeometry/print.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(ctest, write1)
{
    ASSERT_EQUAL(0, check_circle("circle(1 2, 3)", "circle"));
}

CTEST(ctest, write2)
{
    ASSERT_EQUAL(0, check_circle("circle(1 2, 3))", "circle"));
}

CTEST(ctest, write3)
{
    ASSERT_EQUAL(0, check_circle("circle(1 2 3)", "circle"));
}

CTEST(ctest, write4)
{
    ASSERT_EQUAL(
            0, check_triangle("triangle((1 2, 2 3, 3 4, 1 2))", "triangle"));
}

CTEST(ctest, write5)
{
    ASSERT_EQUAL(
            0, check_triangle("triangle((1 2, 2 3, 3 4, 1 2)))", "triangle"));
}

CTEST(ctest, write6)
{
    ASSERT_EQUAL(
            0, check_triangle("triangle((1 2, 2 3, 3 4, 1 3))", "triangle"));
}
