#include "area.h"
#include "check.h"
#include "crossing.h"
#include "ctest.h"
#include "fname.h"
#include "perimeter.h"
#include <stdio.h>

CTEST(name, circle)
{
    char fig[] = "circle";
    int a = figure_name(fig);
    ASSERT_EQUAL(0, a);
    char fig2[] = "circle ";
    a = figure_name(fig2);
    ASSERT_EQUAL(0, a);
    char fig3[] = " ";
    a = figure_name(fig3);
    ASSERT_EQUAL(1, a);
    char fig4[] = "";
    a = figure_name(fig4);
    ASSERT_EQUAL(1, a);
    char fig5[] = "asdfasdg";
    a = figure_name(fig5);
    ASSERT_EQUAL(1, a);
    char fig6[] = "83274";
    a = figure_name(fig6);
    ASSERT_EQUAL(1, a);
    char fig7[] = "CIRCLE";
    a = figure_name(fig7);
    ASSERT_EQUAL(1, a);
    char fig8[] = "CirCle";
    a = figure_name(fig8);
    ASSERT_EQUAL(1, a);
}

CTEST(area, Area)
{
    int a = area(5);
    ASSERT_EQUAL(78, a);
    a = area(0);
    ASSERT_EQUAL(1, a);
    a = area(-1);
    ASSERT_EQUAL(1, a);
    a = area(-12);
    ASSERT_EQUAL(1, a);
}

CTEST(perim, perimeter)
{
    int a = perimeter(5);
    ASSERT_EQUAL(31, a);
    a = perimeter(0);
    ASSERT_EQUAL(1, a);
    a = perimeter(-1);
    ASSERT_EQUAL(1, a);
    a = perimeter(-45);
    ASSERT_EQUAL(1, a);
}

CTEST(cross, crossing)
{
    int a = crossing(2, 3, 2, 4, 3, 5);
    ASSERT_EQUAL(0, a);
    a = crossing(1, 1, 4, 2, 2, 3);
    ASSERT_EQUAL(0, a);
    a = crossing(-2, 0, 1, 2, 5, 5);
    ASSERT_EQUAL(0, a);
    a = crossing(2, 1, 2, 3, 4, 5);
    ASSERT_EQUAL(0, a);
    a = crossing(1, 2, -1, 2, 4, 4);
    ASSERT_EQUAL(0, a);
    a = crossing(1, 1, 3, 3, 4, 1);
    ASSERT_EQUAL(0, a);
    a = crossing(0, 0, 0, 0, 0, 0);
    ASSERT_EQUAL(1, a);
    a = crossing(0, 0, 0, 0, -2, -3);
    ASSERT_EQUAL(1, a);
    a = crossing(1, 1, 1, 1, -2, -3);
    ASSERT_EQUAL(1, a);
}

CTEST(check, number)
{
    char* a = "fhjhfhjf";
    int flag = is_valid_number(a);
    ASSERT_EQUAL(-1, flag);
    a = "";
    flag = is_valid_number(a);
    ASSERT_EQUAL(-1, flag);
    a = "f425";
    flag = is_valid_number(a);
    ASSERT_EQUAL(-1, flag);
    a = "4af";
    flag = is_valid_number(a);
    ASSERT_EQUAL(-1, flag);
    a = "123";
    flag = is_valid_number(a);
    ASSERT_EQUAL(1, flag);
    a = "5";
    flag = is_valid_number(a);
    ASSERT_EQUAL(1, flag);
    a = "-10";
    flag = is_valid_number(a);
    ASSERT_EQUAL(-1, flag);
}
