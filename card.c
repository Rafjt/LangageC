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


void pickCard(carte* pioche, int* cpt_pioche, carte* hand, int* size_hand) {
    // Add the card at the current cpt_pioche index to the player's hand
    hand[*size_hand] = pioche[*cpt_pioche];
    (*size_hand)++;

    // Increase cpt_pioche by 1
    (*cpt_pioche)++;
}


int pickFourCards(carte* pioche, int* cpt_pioche, carte* hand, int* size_hand) {
    // Add the card at the current cpt_pioche index to the player's hand
    for (int i = 0; i < 4; i++) {
        hand[*size_hand] = pioche[*cpt_pioche];
        (*size_hand)++;
        (*cpt_pioche)++;
    }
    return 0;
}


int pickTwoCards(carte* pioche, int* cpt_pioche, carte* hand, int* size_hand) {
    // Add the card at the current cpt_pioche index to the player's hand
    for (int i = 0; i < 2; i++) {
        hand[*size_hand] = pioche[*cpt_pioche];
        (*size_hand)++;
        (*cpt_pioche)++;
    }
    return 0;
}

int changeColor(carte* pile, int* cpt_pile) {
    char color;
    printf("\n CHANGEMENT DE COULEUR !\n");
    printf("Quelle couleur voulez-vous choisir ? (R, B, G, Y)\n");
    scanf(" %c", &color);
    pile[*cpt_pile].couleur = color;
    pile[*cpt_pile].nombre = 13;
    (*cpt_pile)++;
    return 0;
}
