#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "card.h"
#include "player.h"
#include "gui.h"

int main() {
    storeCards(pioche);
    int choix;
    int cpt_pioche = 17;
    TourDirection td = {1, 0};  

    displayGUI();

    // pour apppeler pickCard pour le joueur 1 = pickCard(pioche, &cpt_pioche, hand, &size_hand1);
    // pour apppeler pickCard pour le joueur 2 = pickCard(pioche, &cpt_pioche, hand2, &size_hand2);

    storeCards(pioche);
    pickSevenCards(pioche, hand, hand2, MAX_CARDS);
    int cpt_pile = 1;
    pile[0] = pioche[16];

    int size_hand1 = 7;
    int size_hand2 = 7;

    while (size_hand1 != 0 && size_hand2 != 0) {
        td = next_tour(td.tour, td.direction);
        printf("la derniere carte jouée est %c %d %d\n", pile[cpt_pile - 1].couleur, pile[cpt_pile - 1].nombre, pile[cpt_pile - 1].special);
        player p1 = {1};
        player p2 = {2};
        int player_turn = whichPlayer(td);
        printf("au tour du joueur n°%d\n", player_turn);
        if (player_turn == 1) {
            for (int cpt = 0; cpt < size_hand1; cpt++) {
                printf("Hand 1 - Card %d: %c %d %d\n", cpt + 1, hand[cpt].couleur, hand[cpt].nombre, hand[cpt].special);
            }
            int valid_play = 0;
            do {
                printf("Quelle carte voulez-vous jouer ? (Entrez 0 pour piocher une carte)\n");
                scanf("%d", &choix);

                if (choix == 0) {
                    pickCard(pioche, &cpt_pioche, hand, &size_hand1);
                    printf("Vous avez pioché une carte. Il vous reste %d cartes\n", size_hand1);
                    break;
                } else if (choix > size_hand1 || choix <= 0) {
                    printf("Choix invalide\n");
                } else if (hand[choix - 1].nombre == 13 || hand[choix - 1].nombre == 14 || hand[choix - 1].couleur == pile[cpt_pile - 1].couleur || hand[choix - 1].nombre == pile[cpt_pile - 1].nombre) {
                    pile[cpt_pile] = hand[choix - 1];
                    cpt_pile++;
                    for (int i = choix - 1; i < size_hand1; i++) {
                        hand[i] = hand[i + 1];
                    }
                    size_hand1--;
                    printf("la carte jouée est %c %d %d\n", pile[cpt_pile - 1].couleur, pile[cpt_pile - 1].nombre, pile[cpt_pile - 1].special);
                    // After a card has been played:
                    if (pile[cpt_pile - 1].special == 1) {
                        switch (pile[cpt_pile - 1].nombre) {
                            case 10:
                                pickTwoCards(pioche, &cpt_pioche, hand2, &size_hand2);
                                break;
                            case 11:
                                td = reverse_tour(td.tour, td.direction);
                                break;
                            case 12:
                                td = skip_tour(td.tour, td.direction);
                                break;
                            case 13:
                                changeColor(pile, &cpt_pile);
                                break;
                            case 14:
                                pickFourCards(pioche, &cpt_pioche, hand2, &size_hand2);
                                break;
                        }
                    }
                    printf("il vous reste %d cartes\n", size_hand1);
                    valid_play = 1;
                    if (size_hand1 == 1) {
                        printf("UNO !\n");
                    } else if (size_hand2 == 0) {
                        printf("Victoire du Joueur 2 !\n");
                    }
                } else {
                    printf("Choix invalide\n");
                }
            } while (!valid_play && (choix > size_hand1 || choix <= 0 || !(hand[choix - 1].nombre == 13 || hand[choix - 1].nombre == 14 || hand[choix - 1].couleur == pioche[cpt_pioche].couleur || hand[choix - 1].nombre == pioche[cpt_pioche].nombre)));
        }
        else if (player_turn == 2) {
            for (int cpt = 0; cpt < size_hand2; cpt++) {
                printf("Hand 2 - Card %d: %c %d %d\n", cpt + 1, hand2[cpt].couleur, hand2[cpt].nombre, hand2[cpt].special);
            }
            int valid_play = 0;
            do {
                printf("Quelle carte voulez-vous jouer ? (Entrez 0 pour piocher une carte)\n");
                scanf("%d", &choix);

                if (choix == 0) {
                    pickCard(pioche, &cpt_pioche, hand2, &size_hand2);
                    printf("Vous avez pioché une carte. Il vous reste %d cartes\n", size_hand2);
                    break;
                } else if (choix > size_hand2 || choix <= 0) {
                    printf("Choix invalide\n");
                } else if (hand2[choix - 1].nombre == 13 || hand2[choix - 1].nombre == 14 || hand2[choix - 1].couleur == pile[cpt_pile - 1].couleur || hand2[choix - 1].nombre == pile[cpt_pile - 1].nombre) {
                    pile[cpt_pile] = hand2[choix - 1];
                    cpt_pile++;
                    for (int i = choix - 1; i < size_hand2; i++) {
                        hand2[i] = hand2[i + 1];
                    }
                    size_hand2--;
                    printf("la carte jouée est %c %d %d\n", pile[cpt_pile - 1].couleur, pile[cpt_pile - 1].nombre, pile[cpt_pile - 1].special);
                    if (pile[cpt_pile - 1].special == 1) {
                        switch (pile[cpt_pile - 1].nombre) {
                            case 10:
                                pickTwoCards(pioche, &cpt_pioche, hand2, &size_hand2);
                                break;
                            case 11:
                                td = reverse_tour(td.tour, td.direction);
                                break;
                            case 12:
                                td = skip_tour(td.tour, td.direction);
                                break;
                            case 13:
                                changeColor(pile, &cpt_pile);
                                break;
                            case 14:
                                pickFourCards(pioche, &cpt_pioche, hand2, &size_hand2);
                                break;
                        }
                    }
                    printf("il vous reste %d cartes\n", size_hand2);
                    valid_play = 1;
                    if (size_hand2 == 1) {
                        printf("UNO !\n");
                    } else if (size_hand2 == 0) {
                        printf("Victoire du Joueur 2 !\n");
                    }
                } else {
                    printf("Choix invalide\n");
                }
            } while (!valid_play && (choix > size_hand2 || choix <= 0 || !(hand2[choix - 1].nombre == 13 || hand2[choix - 1].nombre == 14 || hand2[choix - 1].couleur == pioche[cpt_pioche].couleur || hand2[choix - 1].nombre == pioche[cpt_pioche].nombre)));
        }
        }
    }
