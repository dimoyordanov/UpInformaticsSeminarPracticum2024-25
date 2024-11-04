#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned char strength;
    scanf("%d", &strength);
    bool hasTeleportation = (strength>>0)&1;
    bool hasTelekenises = (strength>>1)&1;
    if(hasTeleportation){
        puts("teleportaciq");
    }
    if(hasTelekenises){
        puts("telekineza");
    }
    bool isSuperPowerful = hasTeleportation & hasTelekenises;
    if(isSuperPowerful){
        puts("Super powerful");
    }
    return 0;
}
