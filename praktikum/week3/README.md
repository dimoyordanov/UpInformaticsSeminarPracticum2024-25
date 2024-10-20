# Побитови операции

![operators](img/operators.png)

## Quiz

```C
    int num, n;
    scanf("%d", &num);
    printf("Enter the bit position to set: ");
    scanf("%d", &n);
    num |= (1 << n);
    printf("The new number is: %d", num);
    return 0;
```

- а обратното?

```c
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("The new number is: %d", (num1 ^ num2) >= 0);
```
