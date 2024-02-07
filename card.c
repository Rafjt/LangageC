#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#include <time.h>


void storeCards(struct carte pioche []) {
    FILE *file = fopen("all_cartes.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, " %c %d %d", &pioche [i].couleur, &pioche [i].nombre, &pioche [i].special) == 3) {
        i++;
    }

    fclose(file);
}



// Include this at the top of your file
void pickSevenCards(struct carte pioche[], struct carte hand[], int size) {
    srand(time(0)); // Seed the random number generator

    // Shuffle the array
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        struct carte temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }

    // Pick the first seven cards
    for (int i = 0; i < 7; i++) {
        hand[i] = pioche[i];
    }
}