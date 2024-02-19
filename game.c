#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"


TourDirection next_tour(int tour, int direction) {
    TourDirection td;
    td.direction = direction;  // direction doesn't change in next_tour
    if (direction == 1) {
        td.tour = tour - 1;
    } else {
        td.tour = tour + 1;
    }
    return td;
}

TourDirection skip_tour(int tour, int direction) {
    TourDirection td;
    td.direction = direction;  // direction doesn't change in skip_tour
    if (direction == 1) {
        td.tour = tour - 2;
    } else {
        td.tour = tour + 2;
    }
    return td;
}

TourDirection reverse_tour(int tour, int direction) {
    TourDirection td;
    if (direction == 0) {
        td.direction = 1;
        td.tour = tour - 1;
    } else {
        td.direction = 0;
        td.tour = tour + 1;
    }
    return td;
}

int whichPlayer(TourDirection td) {
    if (td.tour % 2 == 0) {
        return 1; 
    } else {
        return 2; 
    }
}

int checkWin(int size_hand1, int size_hand2) {
    if (size_hand1 == 0) {
        printf("Player 1 wins\n");
    } else if (size_hand2 == 0) {
        printf("Player 2 wins\n");
    }
}

