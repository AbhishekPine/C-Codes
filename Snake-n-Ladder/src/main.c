#include <stdio.h>
#include <stdlib.h>
#include "../include/game.h"

int main() {
    initialize_game();

    int winner = -1;
    int turn = 0;

    printf("=== Welcome to Snake and Ladder Game ===\n");

    while (winner == -1) {
        play_turn(turn);
        display_positions();

        if (player_positions[turn] == 100) {
            winner = turn;
            break;
        }

        turn = (turn + 1) % MAX_PLAYERS;
    }

    printf("\n🎉🎉 Player %d wins the game! 🎉🎉\n", winner + 1);
    return 0;
}
