#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool can_reach_in_one_move(int x1, int y1, int x2, int y2) {
    if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 ||
        x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        return false;
    }

    // Кон
    bool knight_move = (abs(x1 - x2) == 1 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1);

    // Офицер
    bool bishop_move = abs(x1 - x2) == abs(y1 - y2);

    // Топ
    bool rook_move = (x1 == x2) || (y1 == y2);

    return knight_move || bishop_move || rook_move;
}

int main() {
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    if (can_reach(x1, y1, x2, y2)) {
        printf("The point (%d, %d) can be reached from (%d, %d) with one move of a knight, bishop, or rook.\n", x2, y2, x1, y1);
    } else {
        printf("The point (%d, %d) cannot be reached from (%d, %d) with one move of a knight, bishop, or rook.\n", x2, y2, x1, y1);
    }

    return 0;
}