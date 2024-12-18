#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Функция за изчисляване на векторното произведение на два вектора
double cross_product(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}

// Функция за проверка дали точка е вътре в триъгълник, използвайки векторни произведения
bool is_in_triangle(double x, double y, double ax, double ay, double bx, double by, double fx, double fy) {
    double v0x = fx - ax, v0y = fy - ay;
    double v1x = bx - ax, v1y = by - ay;
    double v2x = x - ax, v2y = y - ay;

    double cross0 = cross_product(v0x, v0y, v2x, v2y);
    double cross1 = cross_product(v1x, v1y, v2x, v2y);
    double cross2 = cross_product(v0x, v0y, v1x, v1y);

    return (cross0 >= 0 && cross1 <= cross2) || (cross0 <= 0 && cross1 >= cross2);
}

bool isInShadedArea(double x, double y) {
    // Кръг A с център (-2, -1) и радиус, определен от точка B(1, 5)
    double radiusA = sqrt(pow(1 + 2, 2) + pow(5 + 1, 2));
    bool inCircleA = (pow(x + 2, 2) + pow(y + 1, 2)) <= pow(radiusA, 2);

    // Кръг D с център (-1, 4) и радиус, определен от точка E(-1, 5)
    double radiusD = sqrt(pow(-1 + 1, 2) + pow(5 - 4, 2));
    bool inCircleD = (pow(x + 1, 2) + pow(y - 4, 2)) <= pow(radiusD, 2);

    // Проверка дали точката е в триъгълника, образуван от A(-2, -1), B(1, 5) и F(-5, 3)
    bool inTriangle = is_in_triangle(x, y, -2, -1, 1, 5, -5, 3);

    // Проверка дали точката е в засенчената област
    return inCircleA && !inCircleD && inTriangle;
}

int main() {
    double x, y;
    printf("Въведете координатите на точката (x, y): ");
    scanf("%lf %lf", &x, &y);

    if (isInShadedArea(x, y)) {
        printf("Точката (%.2lf, %.2lf) е в засенчената област.\n", x, y);
    } else {
        printf("Точката (%.2lf, %.2lf) не е в засенчената област.\n", x, y);
    }

    return 0;
}