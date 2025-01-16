# Указатели към фунцкии и функции от по-висок ред, typedef

## Указатели към функции
- Сочи към адреса на функция, тоест клетка с машинен код.
- Решават проблема с динамичното избиране на функция, която да се изпълни в зависимост от някакво условие. 

```c
// Пример без указатели към функции
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

void addAdjecent(int * const array, const size_t size)
{
    for(size_t i = 0; i < size - 1; ++i)
    {
        array[i] = add(array[i], array[i + 1]);
    }
}

void multiplyAdjecent(int * const array, const size_t size)
{
    for(size_t i = 0; i < size - 1; ++i)
    {
        array[i] = multiply(array[i], array[i + 1]);
    }
}

// Пример с указатели към функции
void operateAdjecent(int * const array, const size_t size, int (*operation)(int, int))
{
    for(size_t i = 0; i < size - 1; ++i)
    {
        array[i] = operation(array[i], array[i + 1]);
    }
}
```

## Синтаксис

```c
// Указател към функция
<return_type> (*<pointer_name>)(<parameters>);
// Масив от указатели към функции
<return_type> (*<pointer_name>[])(<parameters>);
```

## Работа с указатели към функции

```c
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main(void) {
    int (*p)(int, int) = add;
    int result = (*p)(1, 2);
    printf("%d\n", result);
    return 0;
}
```

```c
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}

int main(void) {
    int (*operations[])(int, int) = {add, multiply, subtract};
    for(size_t i = 0; i < 3; ++i)
    {
        printf("%d\n", operations[i](1, 2));
    }
    return 0;
}
```

## Функции от по-висок ред

- Функция от по-висок ред е функция, която приема функция като аргумент.

```c
int addOne(const int x)
{
    return x + 1;
}

int double(const int x)
{
    return 2 * x;
}

void map(int * const array, const size_t size, int(*operation)(const int))
{
    for(size_t i = 0; i < size; ++i)
    {
        array[i] = operation(array[i]);
    }
}
```

## Функции, които връщат указатели към функции

```c
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int (*operationFactory(const char operation))(int, int)
{
    if(operation == '+')
    {
        return add;
    }
    else if(operation == '*')
    {
        return multiply;
    }
    return NULL;
}

// Но това не работи
int (*)(int, int) operationFactory(const char operation);
```
Как да заработи?

## typedef

Дефинира синоним на тип.

```c
typedef int (*operation)(int, int);

operation operationFactory(const char op);
```

Можем да дефинираме и други сложни типове като:

```c
typedef const int * const * const immutable_mtr;

// Така вместо
void print(const int * const * const matrix, const size_t rows, const size_t cols)
{
    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Пишем
void print(immutable_mtr matrix, const size_t rows, const size_t cols)
{
    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
``` 




