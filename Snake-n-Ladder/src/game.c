#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/game.h"

int player_positions[MAX_PLAYERS] = {0};

int snakes[] = {99, 95, 92, 89, 74, 64, 62, 49, 46, 16};
int snake_to[] = {80, 75, 88, 68, 53, 60, 19, 11, 25, 6};

int ladders[] = {2, 7, 8, 15, 21, 28, 36, 51, 71, 78, 87};
int ladder_to[] = {38, 14, 31, 26, 42, 84, 44, 67, 91, 98, 94};

void initialize_game() {
    srand((unsigned int) time(NULL));
    for (int i = 0; i < MAX_PLAYERS; i++) {
        player_positions[i] = 0;
    }
}

int roll_dice() {
    return (rand() % 6) + 1;
}

int check_snake_or_ladder(int pos) {
    for (int i = 0; i < sizeof(snakes)/sizeof(snakes[0]); i++) {
        if (pos == snakes[i]) {
            printf("Oh no! Landed on a snake 🐍! Slide down to %d\n", snake_to[i]);
            return snake_to[i];
        }
    }
    for (int i = 0; i < sizeof(ladders)/sizeof(ladders[0]); i++) {
        if (pos == ladders[i]) {
            printf("Yay! Found a ladder 🎉! Climb up to %d\n", ladder_to[i]);
            return ladder_to[i];
        }
    }
    return pos;
}

void play_turn(int player) {
    printf("\nPlayer %d's turn. Press Enter to roll the dice...", player + 1);
    getchar();

    int dice = roll_dice();
    printf("Player %d rolled a %d\n", player + 1, dice);

    int new_position = player_positions[player] + dice;

    if (new_position > 100) {
        printf("Cannot move beyond 100. Stay at position %d.\n", player_positions[player]);
        return;
    }

    new_position = check_snake_or_ladder(new_position);
    player_positions[player] = new_position;

    printf("Player %d moved to position %d\n", player + 1, new_position);
}

void display_positions() {
    printf("\n--- Current Positions ---\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: %d\n", i + 1, player_positions[i]);
    }
}
