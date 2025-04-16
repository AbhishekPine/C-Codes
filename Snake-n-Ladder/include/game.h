#ifndef GAME_H
#define GAME_H

#define MAX_PLAYERS 2

void initialize_game();
int roll_dice();
int check_snake_or_ladder(int position);
void play_turn(int player);
void display_positions();

#endif
