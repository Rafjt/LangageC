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

    storeCards(pioche);
    pickSevenCards(pioche, hand, hand2, MAX_CARDS);

    int size_hand1 = 7; 
    int size_hand2 = 7; 

    while (size_hand1 != 0 && size_hand2 != 0){
        tour = next_tour(tour, direction);
        printf("la derniere carte jouée est %c %d %d\n", pioche[cpt_pioche].couleur, pioche[cpt_pioche].nombre, pioche[cpt_pioche].special);
        player p1 = {1};
        player p2 = {2};
        int player_turn = whichPlayer(tour);
        printf("au tour du joueur n°%d\n", player_turn);
        if (player_turn == 1) {
            for(int cpt = 0; cpt < size_hand1; cpt++){
                printf("Hand 1 - Card %d: %c %d %d\n", cpt+1, hand[cpt].couleur, hand[cpt].nombre, hand[cpt].special);
            }
            int valid_play = 0; 
            do {
                printf("quel carte voulez vous jouer ?\n");
                scanf("%d", &choix);
                if (choix > size_hand1 || choix <= 0){
                    printf("choix invalide\n");
                } else if (hand[choix-1].nombre == 13 || hand[choix-1].nombre == 14 || hand[choix-1].couleur == pioche[cpt_pioche].couleur || hand[choix-1].nombre == pioche[cpt_pioche].nombre){
                    pioche[cpt_pioche] = hand[choix-1]; 
                    for (int i = choix-1; i < size_hand1; i++){
                        hand[i] = hand[i+1];
                    }
                    size_hand1--;
                    printf("la carte jouée est %c %d %d\n", pioche[cpt_pioche].couleur, pioche[cpt_pioche].nombre, pioche[cpt_pioche].special);
                    printf("il vous reste %d cartes\n", size_hand1);
                    valid_play = 1; 
                } else {
                    printf("choix invalide\n");
                }
            } while (!valid_play && (choix > size_hand1 || choix <= 0 || !(hand[choix-1].nombre == 13 || hand[choix-1].nombre == 14 || hand[choix-1].couleur == pioche[cpt_pioche].couleur || hand[choix-1].nombre == pioche[cpt_pioche].nombre)));
        }else if (player_turn == 2) {
        for (int cpt = 0; cpt < size_hand2; cpt++) {
            printf("Hand 2 - Card %d: %c %d %d\n", cpt+1, hand2[cpt].couleur, hand2[cpt].nombre, hand2[cpt].special);
        }

        int valid_play = 0; 
        do {
            printf("Quelle carte voulez-vous jouer ?\n");
            scanf("%d", &choix);

            if (choix > size_hand2 || choix <= 0) {
                printf("Choix invalide\n");
            } else if (hand2[choix-1].nombre == 13 || hand2[choix-1].nombre == 14 || hand2[choix-1].couleur == pioche[cpt_pioche].couleur || hand2[choix-1].nombre == pioche[cpt_pioche].nombre) {
                pioche[cpt_pioche] = hand2[choix-1]; 

                for (int i = choix-1; i < size_hand2; i++) {
                    hand2[i] = hand2[i+1];
                }

                size_hand2--;

                printf("La carte jouée est %c %d %d\n", pioche[cpt_pioche].couleur, pioche[cpt_pioche].nombre, pioche[cpt_pioche].special);
                printf("Il vous reste %d cartes\n", size_hand2);
                valid_play = 1; 
            } else {
                printf("Choix invalide\n");
            }
        } while (!valid_play && (choix > size_hand2 || choix <= 0 || !(hand2[choix-1].nombre == 13 || hand2[choix-1].nombre == 14 || hand2[choix-1].couleur == pioche[cpt_pioche].couleur || hand2[choix-1].nombre == pioche[cpt_pioche].nombre)));
    }

}

}