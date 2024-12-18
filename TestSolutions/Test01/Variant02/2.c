#include <stdio.h>

// Функция за намиране на НОД (най-голям общ делител)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция за намиране на сумата и извеждане като смесено число
void find_sum_and_print_mixed(int a, int b, int k) {
    int numerator = 0;
    int denominator = 1;

    for (int i = 0; i <= k; i++) {
        int current_numerator = a + i;
        int current_denominator = b + i;

        numerator = numerator * current_denominator + current_numerator * denominator;
        denominator *= current_denominator;

        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

    int whole_part = numerator / denominator;
    int fractional_numerator = numerator % denominator;

    if (fractional_numerator == 0) {
        printf("%d\n", whole_part);
    } else {
        printf("%d и %d/%d\n", whole_part, fractional_numerator, denominator);
    }
}

int main() {
    int a, b, k;
    printf("Enter values for a, b, and k: ");
    scanf("%d %d %d", &a, &b, &k);

    find_sum_and_print_mixed(a, b, k);

    return 0;
}