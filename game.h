#include <stdio.h>
#ifndef GAME_H
#define GAME_H
#include <stdlib.h>
#include <string.h>

typedef struct {
    int tour;
    int direction;
} TourDirection;

TourDirection next_tour(int tour, int direction);
TourDirection skip_tour(int tour, int direction);
TourDirection reverse_tour(int tour, int direction);
int whichPlayer(TourDirection td);
int checkWin(int size_hand1, int size_hand2);

#endif