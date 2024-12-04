## Сортиране

### 1. Bubble sort - O($n^2$)

```c
for(unsigned i = 0; i < SIZE - 1; ++i) {
    for(unsigned j = 0; j < SIZE - i - 1; ++j) {
        if(arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }
}
```

### Insertion sort - O($n^2$)

Алгоритъмът сравнява всеки елемент с предходния и ако е по-малък го премества на подходящо място.

<br>Стъпки:
1. Вземаме първия елемент и го считаме за сортиран.
2. Вземаме следващия елемент и го сравняваме с предходния.
3. Ако е по-малък го преместваме на подходящо място.
4. Повтаряме стъпки 2 и 3 докато стигнем края на масива.

```c
void insertionSort(int arr[], unsigned size) {
    for(unsigned i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
```

### Selection sort - O($n^2$)

Алгоритъмът сравнява всеки елемент с останалите и го разменя с най-малкия.

<br>Стъпки:
1. Намираме най-малкия елемент и го разменяме с първия.
2. Намираме следващия най-малък елемент и го разменяме с втория.
3. Повтаряме стъпки 1 и 2 докато стигнем края на масива.

```c
void selectionSort(int arr[], unsigned size) {
    for(unsigned i = 0; i < size - 1; ++i) {
        unsigned minIndex = i;
        for(unsigned j = i + 1; j < size; ++j) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
```

## Търсене

### Binary search - O(log n)

**Забележка:** Масивът трябва да е сортиран.

```c
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
```