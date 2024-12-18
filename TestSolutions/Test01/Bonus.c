#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    unsigned int start;
    int k;

    printf("Въведете началното число: ");
    scanf("%u", &start);
    printf("Въведете броя на елементите за генериране: ");
    scanf("%d", &k);

    int current[MAX_SIZE];
    int next[MAX_SIZE];
    int current_length = 0;
    int i, j, count;

    // Преобразуване на началното число в масив от цифри
    unsigned int temp = start;
    int digits[MAX_SIZE];
    int num_digits = 0;

    if (temp == 0) {
        digits[0] = 0;
        num_digits = 1;
    } else {
        while (temp > 0) {
            digits[num_digits++] = temp % 10;
            temp /= 10;
        }
    }

    // Обръщане на последователността от цифри
    for (i = 0; i < num_digits; i++) {
        current[i] = digits[num_digits - i - 1];
    }
    current_length = num_digits;

    // Извеждане на началното число
    for (i = 0; i < current_length; i++) {
        printf("%d", current[i]);
    }
    printf("\n");

    // Генериране на останалите k-1 елемента
    int step;
    for (step = 1; step < k; step++) {
        int next_length = 0;
        i = 0;
        while (i < current_length) {
            count = 1;
            while (i + 1 < current_length && current[i] == current[i + 1]) {
                count++;
                i++;
            }

            // Добавяне на броя към next[]
            int count_digits[MAX_SIZE];
            int count_num_digits = 0;
            int temp_count = count;
            while (temp_count > 0) {
                count_digits[count_num_digits++] = temp_count % 10;
                temp_count /= 10;
            }
            // Обръщане и добавяне на цифрите на броя
            for (j = count_num_digits - 1; j >= 0; j--) {
                next[next_length++] = count_digits[j];
            }

            // Добавяне на цифрата
            next[next_length++] = current[i];

            i++;
        }

        // Извеждане на следващия елемент
        for (i = 0; i < next_length; i++) {
            printf("%d", next[i]);
        }
        printf("\n");

        // Прехвърляне на next[] към current[]
        current_length = next_length;
        for (i = 0; i < current_length; i++) {
            current[i] = next[i];
        }
    }

    return 0;
}