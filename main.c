#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "card.h"
#include "player.h"


int main(){
    storeCards(pioche);
    int choix;
    int tour = 1;
    int direction = 0;
    int cpt_pioche = 14;

    
    // for (int j = 0; j < MAX_CARDS; j++) {
    //     printf("Card %d: %c %d %d\n", j+1, pioche [j].couleur, pioche [j].nombre, pioche [j].special);
    // }

    int cpt;
    // for ( cpt = 0; cpt != 5; cpt++)
    // {
    //     tour = next_tour(tour, direction);
    //     printf("Tour: %d\n", tour);
    //     printf("compteur: %d\n", cpt);
    // }



    storeCards(pioche);
    pickSevenCards(pioche, hand, hand2, MAX_CARDS);
    // for (int i = 0; i < 7; i++) {
    //     printf("Hand 1 - Card %d: %c %d %d\n", i+1, hand[i].couleur, hand[i].nombre, hand[i].special);
    // }
    // for (int i = 0; i < 7; i++) {
    //     printf("Hand 2 - Card %d: %c %d %d\n", i+1, hand2[i].couleur, hand2[i].nombre, hand2[i].special);
    // }

    int size_hand1 = sizeof(hand) / sizeof(hand[0]);
    int size_hand2 = sizeof(hand2) / sizeof(hand2[0]);

    while (size_hand1 != 0 || size_hand2 != 0){
    tour = next_tour(tour, direction);
    printf("la derniere carte jouée est %c %d %d\n", hand[cpt_pioche].couleur, hand[cpt_pioche].nombre, hand[cpt_pioche].special);
    cpt_pioche++;
    player p1 = {1};
    player p2 = {2};
    int player_turn = whichPlayer(tour);
    printf("au tour du joueur n°%d\n", player_turn);
        if (player_turn == 1) {
            for(cpt = 0; cpt < size_hand1; cpt++){
            printf("Hand 1 - Card %d: %c %d %d\n", cpt+1, hand[cpt].couleur, hand[cpt].nombre, hand[cpt].special);
            }
            printf("quel carte voulez vous jouer ?\n");
            scanf("%d", &choix);
            if (choix > size_hand1 || choix <= 0){
                printf("choix invalide\n");
            } else if (hand[choix-1].nombre == 13 || hand[choix-1].nombre == 14 || hand[choix-1].couleur == pioche[cpt_pioche].couleur || hand[choix-1].nombre == pioche[cpt_pioche].nombre){
        hand[cpt_pioche] = hand[choix-1];
        for (int i = choix-1; i < size_hand1; i++){
            hand[i] = hand[i+1];
        }
        size_hand1--;
        printf("la carte jouée est %c %d %d\n", hand[cpt_pioche].couleur, hand[cpt_pioche].nombre, hand[cpt_pioche].special);
        printf("il vous reste %d cartes\n", size_hand1);
    } else {
        printf("choix invalide\n");
    }
    return 0;
        }else if (player_turn == 2) {
            for(cpt = 0; cpt < size_hand2; cpt++){
            printf("Hand 2 - Card %d: %c %d %d\n", cpt+1, hand2[cpt].couleur, hand2[cpt].nombre, hand2[cpt].special);
            }
            printf("quel carte voulez vous jouer ?\n");
            scanf("%d", &choix);
            if (choix > size_hand2 || choix <= 0){
                printf("choix invalide\n");
            } else if (hand2[choix-1].nombre == 13 || hand2[choix-1].nombre == 14 || hand2[choix-1].couleur == pioche[cpt_pioche].couleur || hand2[choix-1].nombre == pioche[cpt_pioche].nombre){

    }    

}
}
    return 0;
}



