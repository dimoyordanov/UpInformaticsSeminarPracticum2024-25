# Едномерни масиви

## Какво е масив?
Масив е структура от данни, която съдържа елементи от един и същи тип, разположени в последователен ред. Елементите на масива се достъпват чрез индекси.

## Декларация и инициализация

```c
#define SIZE 5 

int arr[SIZE]; // Декларация на масив от 5 елемента
int arr[SIZE] = {1, 2, 3, 4, 5}; // Декларация и инициализация на масив от 5 елемента
int arr[] = {1, 2, 3, 4, 5}; // Декларация на масив от 5 елемента

int arr[SIZE] = {1, 2}; // arr = {1, 2, 0, 0, 0}
int arr[SIZE] = {0}; // arr = {0, 0, 0, 0, 0}

int arr[SIZE] = {1, 2, 3, 4, 5, 6}; // Грешка
int arr[]; // Грешка

char str[] = "Hello"; // str = {'H', 'e', 'l', 'l', 'o', '\0'}
```

## Достъп до елементите на масив

```c
int arr[5] = {1, 2, 3, 4, 5};
arr[2] = 10; // arr = {1, 2, 10, 4, 5}
```

В случай, че индексът е извън границите на масива *(в случая горе ако е по-голям от 4)* в повечето случаи *(в зависимост от системата)* ще получим невалидна стойност или програмата ще се срине.

## Обхождане на масиви чрез цикли

Като инициализираща променлива в цикъл е добра практика да се използват или `unsigned int`, за да се избегнат проблеми със знаците и за да се достъпят възможно най-много елементи на масива.


## Масиви като аргументи на функции

```c
#include <stdio.h>

void print(int arr[], const size_t len) // Големината на масива не е нужно да се подава в квадратните скоби
{
    for(size_t i = 0; i < len; ++i)
    {
        std::cout << arr[i] << ' ';
    }
}

// Такава декларация е възможна, защото масивите decay-ват до указатели към първия елемент в масива, когато се подават като аргументи на функции
void modifyArray(int* arr, const size_t len)
{
    for(size_t i = 0; i < len; ++i)
    {
        arr[i] += 1; 
    }
}
```

## Добавяне на елемент към масив

```c
#include <stdio.h>

void addElement(int arr[], unsigned size, int element, int index)
{
    for(size_t i = size - 1; i > index; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    addElement(arr, 5, 10, 2); // arr = {1, 2, 10, 3, 4}
    return 0;
}
```

## Изтриване на елемент от масив

```c
#include <stdio.h>

void removeElement(int arr[], unsigned size, int index)
{
    for(size_t i = index; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    removeElement(arr, 5, 2); // arr = {1, 2, 4, 5, 5}
    return 0;
}
```


## Задачи

### Задача 1.
Напишете функция, която приема масив от цели числа и връща броя на елементите, които са по-големи от средната стойност на всички елементи в масива.

### Задача 2.
Напишете функция, която изтрива всички срещания на даден елемент в масив и принтира новия масив. Изтриването на елементите да стане без използване на допълнителен масив.

```
int arr[] = {1, 2, 3, 4, 5, 5, 6, 7, 5};
Вход: 5
Изход: {1, 2, 3, 4, 6, 7}
```

### Задача 3.
Напишете функция, която приема текст с максимална дължина 100 символа и връща броя на думите в него.

### Задача 4.
Напишете функция, която приема текст с максимална дължина 100. Текстът е в грешен формат и съдържа по няколко интервала между думите. Също така някои думи в началото на ново изречение не са написани с главни букви. Функцията трябва да премахне излишните интервали и да направи първата буква на всяка дума от ново изречение главна.

```
Вход: "  това е текст с грешен формат.  "
Изход: "Това е текст с грешен формат."

Вход: "  това е текст с грешен формат.  това е второ изречение.  "
Изход: "Това е текст с грешен формат. Това е второ изречение."
```

### Задача 5.
Да се напише функция, която изтрива всички повтарящи се елементи в сортиран масив и принтира последователно числото `n` - броя уникални елементи в масива, и резултатния масив. Решението да не използва допълнителен масив.

```
int arr[] = {1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 5};
Изход: 5 {1, 2, 3, 4, 5}
```

### Задача 6.
Да се напише функция, която принтира сечението на два масива.

```
int arr1[] = {1, 2, 3, 4, 5};
int arr2[] = {3, 4, 5, 6, 7};
Изход: {3, 4, 5}
```