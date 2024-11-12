# Проверка на коректност на вход и генериране на случайни числа

## Начини за прекъсване на програмата

### Използване на return

```c
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input\n");
        return 1;
    }
    printf("You entered: %d\n", n);
    return 0;
}
```

### Използване на exit

```c
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input\n");
        exit(1);
    }
    printf("You entered: %d\n", n);
    return 0;
}
```

Разликата между `return` и `exit` е, че `return` се използва за прекратяване на функция, докато `exit` се използва за прекратяване на цялата програма. **Винаги** използвайте `return` в `main` функцията.

## Проверки с if

### Проверка за правилно въведен тип

```c
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) == 1)
    {
        printf("You entered: %d\n", n);
    }
    else
    {
        printf("Invalid input\n");
        return 1;
    }
    return 0;
}
```


## Проверки с цикли

### Проверка за правилно въведен тип

```c
#include <stdio.h>

int main()
{
    int n;
    while (1) // Въвеждаме стойности, докато не въведем валидна
    {
        printf("Enter a number: ");
        if (scanf("%d", &n) == 1) // Проверяваме дали функцията връща код за успешно прочетено число
        {
            break;
        }
        else
        {
            printf("Invalid input\n");
            while (getchar() != '\n'); // Ако не е, изчистваме буфера
        }
    }
    printf("You entered: %d\n", n);
    return 0;
}
```

## Функция rand()

Функцията генерира псевдо-случайно число в някакъв интервал. Ако искате да разберете защо числото е псевдо-случайно, може да прочетете имплементацията [тук](https://github.com/openbsd/src/blob/master/lib/libc/stdlib/random.c).

### Генериране на случайно число

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = rand() % 100; // Генерира число в интервала [0, 99]
    int x = rand() % 100 + 1; // Генерира число в интервала [1, 100]
    printf("Random number: %d\n", n);
    printf("Random number: %d\n", x);
    return 0;
}
```

Забележете как при всяко изпълнение на програмата, генерираните числа са еднакви.

### Сийдване на rand()

Сийд наричаме стойност, която случайния генератор приема като начална стойност и генерира следващите стойности като се базира на нея. Ако сийдваме rand() с текущото време, ще получим различни стойности при всяко изпълнение на програмата.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Сийдваме rand() с текущото време
    int n = rand() % 100; // Генерира число в интервала [0, 99]
    int x = rand() % 100 + 1; // Генерира число в интервала [1, 100]
    printf("Random number: %d\n", n);
    printf("Random number: %d\n", x);
    return 0;
}
```