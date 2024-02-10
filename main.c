#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "card.h"
#include "player.h"


int main(){
    storeCards(pioche);
    int tour = 1;
    int direction = 0;
    int cpt_pioche = 14;

    
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
    pickSevenCards(pioche, hand, hand2, MAX_CARDS);
    for (int i = 0; i < 7; i++) {
        printf("Hand 1 - Card %d: %c %d %d\n", i+1, hand[i].couleur, hand[i].nombre, hand[i].special);
    }
    for (int i = 0; i < 7; i++) {
        printf("Hand 2 - Card %d: %c %d %d\n", i+1, hand2[i].couleur, hand2[i].nombre, hand2[i].special);
    }

    int size_hand1 = sizeof(hand) / sizeof(hand[0]);
    int size_hand2 = sizeof(hand2) / sizeof(hand2[0]);

    while(size_hand1 > 0 || size_hand2 > 0){
    printf("Au tour du joueur %d\n", whichPlayer(tour));
    
}
}


