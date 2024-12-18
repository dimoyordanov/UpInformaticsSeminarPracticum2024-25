# Цикли

## Задачи

1. Да се въведе число n, след което да се въвеждат n на брой числа. Да се намери:

- a) Средно аритметично
- б) Най-голямо и най-малко

```c
In: 5 1 -2 5 9 -6
Out:
Highest: 9
Lowest: -6
Avarage: 1.40

In: 10 8 -100 -4 30 23 123 3 2 9 12
Out:
Highest: 123
Lowest: -100
Avarage: 10.60
```

2. Дадено е число. Да се провери дали е просто.

```c
89
Prime!
97
Prime!
32
Not prime!
25
Not prime!
```

3. Дадено е число n. Да се намери n-тото число от числата на Фибоначи.

- 0, 1, 1, 2, 3, 5, 8, 13, 21....
  [Числа на Фибоначи](https://bg.wikipedia.org/wiki/%D0%A7%D0%B8%D1%81%D0%BB%D0%B0_%D0%BD%D0%B0_%D0%A4%D0%B8%D0%B1%D0%BE%D0%BD%D0%B0%D1%87%D0%B8)

```c
19
Fib: 4181
0
Fib: 0
1, 2
Fib: 1
```

4. Да се намери дали едно число е палиндром

```c
12321
Palindrome!
10023532001
Palindrome!
123123
Not Palindrome!
```

5. Да се реализира функцията pow()

Благодарности на Радослав Ананиев за намерената грешка.

```c
In: 2 -4
Out: 0.0625
In: 3 4
Out: 81.00
```

6. Да се направи пирамида от числа. На всеки ред числата са толкова на брой, колкото е номера на реда

```c
In: 8
Out:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31 32 33 34 35 36
```

6. Дадени са n(ред) и m(колона) да се направи:
   а) рамка от единици
   ```c
   4 5
   1 1 1 1 1
   1 0 0 0 1
   1 0 0 0 1
   1 1 1 1 1
   ```
   б)долен триъгълник(задължително е квадрат т.е n==m)
   ```c
   6 6
   0 0 0 0 0 1
   0 0 0 0 1 1
   0 0 0 1 1 1
   0 0 1 1 1 1
   0 1 1 1 1 1
   1 1 1 1 1 1
   ```
