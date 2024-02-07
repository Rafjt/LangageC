#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARDS 60

struct carte{
    char couleur;
    int nombre;
    int special;
};
struct carte pioche [MAX_CARDS];
void storeCards(struct carte pioche[]);

#endif 