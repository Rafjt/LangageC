#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARDS 60


typedef struct carte {
    char couleur;
    int nombre;
    int special;
} carte;

carte pioche [MAX_CARDS];
carte pile [MAX_CARDS];
void storeCards(carte pioche[]);
void pickSevenCards(carte pioche[],carte hand[],carte hand2[], int size);
int countCards(carte hand[], int size);
void pickCard(carte* pioche, int* cpt_pioche, carte* hand, int* size_hand);
int pickFourCards(carte* pioche, int* cpt_pioche, carte* hand, int* size_hand);
int pickTwoCards(carte* pioche, int* cpt_pioche, carte* hand, int* size_hand);
int changeColor(carte* pioche, int* cpt_pioche);
#endif 