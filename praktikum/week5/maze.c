#include <stdio.h>

int main()
{
    int maze = 1634;
    int playerCoordsX = 0, playerCoordsY = 0;
    int isBlocked;
    char tempMove = 0;

    while(1){
        scanf("%c", &tempMove);

        switch (tempMove) {
            case 'u':
            
                // check if the next move is on a wall
                isBlocked = (maze >> (playerCoordsX + (playerCoordsY-1)*4))&1;
                if (playerCoordsY == 0){
                    puts("You have hit the top wall\n");
                } else if (isBlocked){
                    puts("Your wall is blocked\n");
                } else {
                    playerCoordsY--;
                }
            
            break;
        case 'd':
            
                // check if the next move is on a wall
                isBlocked = (maze >> (playerCoordsX + (playerCoordsY+1)*4))&1;
                if (playerCoordsY == 3){
                    puts("You have hit the bottom wall\n");
                } else if (isBlocked){
                    puts("Your wall is blocked\n");
                } else {
                    playerCoordsY++;
                }
            
            break;
        case 'l':
            
                // check if the next move is on a wall
                isBlocked = (maze >> (playerCoordsX + (playerCoordsY+1)*4))&1;
                if (playerCoordsX == 0){
                    puts("You have hit the left wall\n");
                } else if (isBlocked){
                    puts("Your wall is blocked\n");
                } else {
                        playerCoordsX--;
                }
            
            break;
        case 'r':
            
                // check if the next move is on a wall
                isBlocked = (maze >> (playerCoordsX + (playerCoordsY+1)*4))&1;
                if (playerCoordsX == 3){
                    puts("You have hit the right wall\n");
                } else if (isBlocked){
                    puts("Your wall is blocked\n");
                } else {
                    playerCoordsX++;
                }
            
            break;
        default:
            puts("Ne se prai na interesen smrudljo!\n");
        }

    }


    return 0;
}
