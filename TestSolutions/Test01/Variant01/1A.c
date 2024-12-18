#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_point_in_colored_area(double x, double y) {
    // Център на големия кръг
    const double A_x = -4, A_y = -1;

    const double B_x = -5, B_y = 5;
    const double C_x = 2,  C_y = 0;

    // Радиус на големия кръг (на квадрат)
    double R_squared = (pow(B_x - A_x, 2) + pow(B_y - A_y, 2));
    
    // Център на малкия кръг
    double D_x = -3, D_y = -5;

    double E_x = -3, E_y = -4;

    // Радиус на малкия кръг (на квадрат)
    double r_squared = (pow(E_x - D_x, 2) + pow(E_y - D_y, 2));
    
    // Проверка дали точката е вътре в големия кръг
    bool in_big_circle = (pow(x - A_x, 2) + pow(y - A_y, 2)) <= R_squared;
    
    // Проверка дали точката е извън малкия кръг
    bool out_small_circle = (pow(x - D_x, 2) + pow(y - D_y, 2)) >= r_squared;
    
    // Изчисляване на f_AB и f_AC
    double f_AB = (x - A_x)*(B_y - A_y) - (y - A_y)*(B_x - A_x);
    double f_AC = (x - A_x)*(C_y - A_y) - (y - A_y)*(C_x - A_x);
    
    // Проверка дали точката е извън отрязаната част
    bool outside_cutoff = (f_AB * f_AC) > 0;
    
    return in_big_circle && out_small_circle && outside_cutoff;
}

int main() {
    double x = -4, y = 0;
    if (is_point_in_colored_area(x, y)) {
        printf("Точката (%.2f, %.2f) принадлежи на оцветената област.\n", x, y);
    } else {
        printf("Точката (%.2f, %.2f) не принадлежи на оцветената област.\n", x, y);
    }
    return 0;
}