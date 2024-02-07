#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

int tour = 0;
int direction = 0;

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