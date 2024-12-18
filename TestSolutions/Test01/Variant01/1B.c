#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool can_reach_in_one_move(int x1, int y1, int x2, int y2) {
    // Проверка за валидност на позициите
    if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 ||
        x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        return false;
    }

    // Топ
    bool rook_move = (x1 == x2) || (y1 == y2);
    
    // Цар
    bool king_move = (abs(x1 - x2) <= 1) && (abs(y1 - y2) <= 1);
    
    // Царица
    bool queen_move = rook_move || (abs(x1 - x2) == abs(y1 - y2));
    
    // Проверка дали поне едно от условията е изпълнено
    return rook_move || king_move || queen_move;
}

int main() {
    int x1 = 4, y1 = 4; // Първа точка
    int x2 = 6, y2 = 6; // Втора точка

    if (can_reach_in_one_move(x1, y1, x2, y2)) {
        printf("Може да се достигне от (%d, %d) до (%d, %d) с един ход на топ, цар или царица.\n", x1, y1, x2, y2);
    } else {
        printf("НЕ може да се достигне от (%d, %d) до (%d, %d) с един ход на топ, цар или царица.\n", x1, y1, x2, y2);
    }

    return 0;
}