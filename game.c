#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

int next_tour(int tour, int direction) {
    if (direction == 1) {
        return tour - 1;
    } else {
        return tour + 1;
    }
}

int skip_tour(int tour,int direction) {
    if (direction == 1) {
        return tour - 2;
    } else {
        return tour + 2;
    }
}

int reverse_tour(int tour, int direction) {
    if (direction == 0) {
        direction = 1;
        return tour - 1;
    } else {
        direction = 0;
        return tour + 1;
    }
}

int whichPlayer(int tour) {
    if (tour % 2 == 0) {
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
