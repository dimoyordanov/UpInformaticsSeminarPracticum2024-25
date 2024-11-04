#include <stdio.h>
#include <stdbool.h>

int main(){
    short int field = 0;
    const int spaces = 15;
    short int cordX, cordY;

    scanf("%hd %hd", &cordX, &cordY);

    field = field | (1 << (cordX+cordY*4));
    
    for(int i = 0; i < spaces; i++){
        puts("\n");
    }
    for (size_t i = 0; i < 3; i++)
    {
        scanf("%hd %hd", &cordX, &cordY);

        int isFieldOccupied = field & (1 << (cordX + 4*cordY));
        if(isFieldOccupied){
            printf("suffering from success\n");
            break;
        }else{
            printf("Greshno\n");
        }
    }
}