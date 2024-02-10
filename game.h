#include <stdio.h>
#ifndef GAME_H
#define GAME_H
#include <stdlib.h>
#include <string.h>


int next_tour(int tour, int direction);
int skip_tour(int tour, int direction);
int reverse_tour(int tour, int direction);
int whichPlayer(int tour);

#endif 