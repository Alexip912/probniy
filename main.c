#include "area.h"
#include "check.h"
#include "crossing.h"
#include "fname.h"
#include "perimeter.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char figure[30];
    int x1, y1, x2, y2;
    int r1, r2;
    char sx1[10], sy1[10], sx2[10], sy2[10];
    char sr1[10], sr2[10];
    int s1, s2, p1, p2;
    printf("Название фигуры - ");
    scanf("%s", figure);
    int flag = figure_name(figure);
    if (flag == 0) {
        printf("Введите координаты первой окружности - ");
        scanf("%s", sx1);
        if (is_valid_number(sx1) == -1) {
            printf("Надо вводить число");
            return 0;
        }
        scanf("%s", sy1);
        if (is_valid_number(sy1) == -1) {
            printf("Надо вводить число");
            return 0;
        }
        printf("Введите радиус первой окружности: ");
        scanf("%s", sr1);
        if (is_valid_number(sr1) == -1) {
            printf("Надо вводить число");
            return 0;
        } else {
            r1 = atof(sr1);
            s1 = area(r1);
            p1 = perimeter(r1);
        }
        printf("Введите координаты второй окружности - ");
        scanf("%s", sx2);
        if (is_valid_number(sx2) == -1) {
            printf("Надо вводить число");
            return 0;
        }
        scanf("%s", sy1);
        if (is_valid_number(sy1) == -1) {
            printf("Надо вводить число");
            return 0;
        }
        printf("Введите радиус первой окружности: ");
        scanf("%s", sr2);
        if (is_valid_number(sr2) == -1) {
            printf("Надо вводить число");
            return 0;
        } else {
            r2 = atof(sr2);
            s2 = area(r2);
            p2 = perimeter(r2);
        }
    } else {
        printf("Доступные названия фигур: circle");
        return 0;
    }
    if (s1 == 1 || s2 == 1 || p1 == 1 || p2 == 1) {
        printf("Неверное значение радиуса");
        return 0;
    } else {
        x1 = atof(sx1);
        x2 = atof(sx2);
        y1 = atof(sy1);
        y2 = atof(sy2);
        int check = crossing(x1, x2, y1, y2, r1, r2);
        if (check != 0) {
            printf("\n<<Окружности не пересекаются>>\n");
        } else
            printf("\n<<Окружности пересекаются>>\n");
        printf("Площадь первой окружности: %d\n", s1);
        printf("Периметр первой окружности: %d\n\n", p1);
        printf("Площадь второй окружности: %d\n", s2);
        printf("Периметр второй окружности: %d\n", p2);
    }
    return 0;
}
