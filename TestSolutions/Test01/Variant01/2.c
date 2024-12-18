#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    int numerator = 0, denominator = 1;
    while (1) {
        scanf("%d", &a);
        if (a == 0)
            break;
        scanf("%d", &b);
        if (b == 0)
            break;
        numerator = numerator * b + a * denominator;
        denominator *= b;
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }
    int whole = numerator / denominator;
    numerator = numerator % denominator;
    if (numerator == 0) {
        printf("%d\n", whole);
    } else {
        printf("%d и %d/%d\n", whole, numerator, denominator);
    }
    return 0;
}