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



void pickSevenCards(struct carte pioche[], struct carte hand1[], struct carte hand2[], int size) {
    srand(time(0)); 

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        struct carte temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }

    // Distribute cards to two hands
    for (int i = 0; i < 7; i++) {
        hand1[i] = pioche[i];
        hand2[i] = pioche[i + 7];
    }
}


int countCards(struct carte hand[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        count++;
    }
    return count;
}


void pickCard(carte* pioche, int* size_pioche, carte* hand, int* size_hand) {
    srand(time(NULL)); // Seed the random number generator
    int index = rand() % *size_pioche; // Generate a random index

    // Add the card to the player's hand
    hand[*size_hand] = pioche[index];
    (*size_hand)++;

    // Shift all cards down by one to fill the gap
    for (int i = index; i < *size_pioche - 1; i++) {
        pioche[i] = pioche[i + 1];
    }

    // Decrease the size of the deck
    (*size_pioche)--;
}

