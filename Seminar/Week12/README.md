# Рекурсивни алгоритми, backtracking

## Пермутацции на стринг

```c
#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permuteRec(const char *a, int l, int r)
{
    if (l == r)
        printf("%s\n", a);
    else
    {
        for (size_t i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i)); // backtrack
        }
    }
}

void permute(const char *a)
{
    permuteRec(a, 0, strlen(a) - 1);
}
```
## DFS за намиране на път в лабиринт

```c
#include <stdio.h>
#include <stdbool.h>

#define N 4

bool isValidMove(const bool * const * const maze, const size_t x, const size_t y);
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

bool hasPath(bool * const * const maze, const size_t start_x, const size_t start_y, const size_t end_x, const size_t end_y)
{
    if(start_x == end_x && start_y == end_y)
    {
        return true;
    }

    if(isValidMove(maze, start_x, start_y))
    {
        maze[start_x][start_y] = true;

        if(hasPath(maze, start_x + 1, start_y, end_x, end_y) ||
           hasPath(maze, start_x - 1, start_y, end_x, end_y) ||
           hasPath(maze, start_x, start_y + 1, end_x, end_y) ||
           hasPath(maze, start_x, start_y - 1, end_x, end_y))
        {
            return true;
        }

        maze[start_x][start_y] = false;
    }

    return false;
}  
```

## N-Queen

```c
#include <stdio.h>

#define N 4

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQ()
{
    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if (solveNQUtil(board, 0) == false)
    {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}
```

## Задачи

### Задача 1:
Да се напише рекурсивна фунцкия, която решава задачата за Ханойските кули.

### Задача 2:
Да се напише рекурсивна функция, която намира дали дадена дума се среща в матрица от букви. Думата може да бъде намерена във всяка посока, както и да прави завои.

**Пример:**

```
const char[][] matrix = {
    {'m', 'o', 'y', 'd'},
    {'o', 'f', 'e', 'i'},
    {'m', 'f', 'i', 'k'},
    {'b', 'r', 'o', 's'}
    {'m', 'i', 'k', 'l'},
    {'b', 'e', 'n', 'd'}
};

Думи вътре:
yomom
mom
bend
friend
bro
broski
die
```

### Задача 3:
Да се напише функция, която намира броя на всички острови в матрица NxN. Остров е свързана група от единици, която може да се разшири във всички посоки.

**Пример:**

```
const int[][] matrix = {
    {1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1}
};

Брой на островите: 5
```
