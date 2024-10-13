# Седмица №2
## Scanf
scanf, като функция е доста подобна на printf по параметри. Scanf приема вход от конзолата.
Анализира входа според това което сме подали като първи параметър и пази резултата в параметрите, които сме подали след 1-вия.
Параметрите, които са след първия засега приемаме, че задължително преди себе си трябва да имат амперсант(&). 

Символите, които се игнорират са шпации и табове.

```C
#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", a);
    
    int year, date, month;
    scanf("%d/%d/%d", &date, &month, &year);
    printf("%d %d %d", date, month, year);
    return 0;
}
```
## Условно изпълнение

### if
```C
#include <stdio.h>

int main() {
    // Write C code here
    int a = 4;
    if(a==3){
        printf("ABV\n");
    }else if (a == 4){
        printf("GDE\n");
    }else{
        printf("JZI\n");
    }
}
```

### ternary-operator
```C
#include <stdio.h>

int main() {
    int a = 4;
    printf((a==4)?"Az sum 4\n":"Az ne sum 4\n");
}
```
### switch
```C
#include <stdio.h>

int main(){
    char ab;
    scanf("%c", &ab);
    switch(ab){
        case 'a': printf("a");break;
        case '3': printf("easter egg = ");
        case '6': printf("42");break;
        default: printf("default path");
    }
    return 0;
}
```
### Short-circuit evaluation
```C
#include <stdio.h>

int main(){
    int orTest = 4;
    orTest || orTest++;
    printf("%d\n", orTest);
    orTest = 0;
    orTest || orTest++;
    printf("%d\n", orTest);
    int andTest = 4;
    andTest && andTest++;
    printf("%d\n", andTest);
    andTest = 0;
    andTest && andTest++;
    printf("%d\n", andTest);
    
    return 0;
}
```
