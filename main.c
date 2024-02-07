#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "card.h"
#include "player.h"


int main(){
    storeCards(pioche);
    int tour = 0;
    int direction = 0;

    
    
    // for (int j = 0; j < MAX_CARDS; j++) {
    //     printf("Card %d: %c %d %d\n", j+1, pioche [j].couleur, pioche [j].nombre, pioche [j].special);
    // }
    int cpt;
    for ( cpt = 0; cpt != 5; cpt++)
    {
        tour = next_tour(tour, direction);
        printf("Tour: %d\n", tour);
        printf("compteur: %d\n", cpt);
    }



    storeCards(pioche);
    pickSevenCards(pioche, hand, MAX_CARDS);
    for (int i = 0; i < 7; i++) {
        printf("Card %d: %c %d %d\n", i+1, hand[i].couleur, hand[i].nombre, hand[i].special);
    }
    

    return 0;
}