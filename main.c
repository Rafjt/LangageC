#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "card.h"
#include "player.h"
#include "gui.h"
#define HAND_WIDTH 50
#define HAND_HEIGHT 75


int main() {
    SDL_Window* window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1500, 800, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        printf("Could not create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set the color for drawing operations (RGBA: 53, 101, 77, 255)
    SDL_SetRenderDrawColor(renderer, 53, 101, 77, 255);

    // Clear the current rendering target with the drawing color
    SDL_RenderClear(renderer);

    // Update the screen with any rendering performed since the previous call
    SDL_RenderPresent(renderer);

    storeCards(pioche);
    int choix;
    int cpt_pioche = 17;
    TourDirection td = {1, 0};  
    int valid_play = 0;

    displayGUI();

    storeCards(pioche);
    pickSevenCards(pioche, hand, hand2, MAX_CARDS);
    int cpt_pile = 1;
    pile[0] = pioche[16];

    int size_hand1 = 7;
    int size_hand2 = 7;
    int mult = 0;

     while (size_hand1 != 0 && size_hand2 != 0) {
        SDL_RenderClear(renderer);
        printf("la derniere carte jouée est %c %d %d\n", pile[cpt_pile - 1].couleur, pile[cpt_pile - 1].nombre, pile[cpt_pile - 1].special);
        player p1 = {1};
        player p2 = {2}; 
        int player_turn = whichPlayer(td);
        printf("au tour du joueur n°%d\n", player_turn);
        if (player_turn == 1) {
            int valid_play = 0;
            int window_width, window_height;
            SDL_GetRendererOutputSize(renderer, &window_width, &window_height);
            int card_height = HAND_HEIGHT;
            int card_y = window_height - card_height;  // position at the bottom
            for (int cpt = 0; cpt < size_hand1; cpt++) {
                drawHand(renderer, hand[cpt], cpt * HAND_WIDTH, card_y);
            }
        SDL_RenderPresent(renderer);
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
                        printf("hand[%d] = %c %d %d\n", i+1, hand[i].couleur, hand[i].nombre, hand[i].special);
                        hand[i] = hand[i + 1];
                    }
                    size_hand1--;
                    printf("la carte jouée est %c %d %d\n", pile[cpt_pile - 1].couleur, pile[cpt_pile - 1].nombre, pile[cpt_pile - 1].special);
                    printf("\ntour avant = %d\n", td.tour);
                    // After a card has been played:
                    if (pile[cpt_pile - 1].special == 1) {
                        switch (pile[cpt_pile - 1].nombre) {
                            case 10:
                                pickTwoCards(pioche, &cpt_pioche, hand2, &size_hand2);
                                break;
                            case 11:
                                td = reverse_tour(td.tour,td.direction);
                                break;
                            case 12:
                                td = skip_tour(td.tour,td.direction);
                                break;
                            case 13:
                                changeColor(pile, &cpt_pile);
                                break;
                            case 14:
                                pickFourCards(pioche, &cpt_pioche, hand2, &size_hand2);
                                changeColor(pile, &cpt_pile);
                                break;
                        }
                        printf("\ntour après = %d\n", td.tour);
                    }
                    printf("il vous reste %d cartes\n", size_hand1);
                    valid_play = 1;
                    // int card_x = (window_width - HAND_WIDTH) / 2;
                    // int card_y = (window_height - HAND_HEIGHT) / 2;
                    // drawHand(renderer, pile[cpt_pile - 1], card_x, card_y);
                    // SDL_RenderPresent(renderer);
                    if (size_hand1 == 1) {
                        printf("UNO !\n");
                    } else if (size_hand2 == 0) {
                        printf("Victoire du Joueur 2 !\n");
                    }
                } else {
                    printf("Choix invalide\n");
                }
            } while (!valid_play && (choix > size_hand1 || choix <= 0 || !(hand[choix - 1].nombre == 13 || hand[choix - 1].nombre == 14 || hand[choix - 1].couleur == pioche[cpt_pioche].couleur || hand[choix - 1].nombre == pioche[cpt_pioche].nombre)));
            player_turn = whichPlayer(td);
       } else if (player_turn == 2) {
            int valid_play = 0;
            // mult = 0;
            for (int cpt = 0; cpt < size_hand2; cpt++) {
                drawHand(renderer, hand2[cpt], cpt * HAND_WIDTH, 0);
                // mult += 2;
            }
            SDL_RenderPresent(renderer);
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
                        printf("hand2[%d] = %c %d %d\n", i+1, hand2[i].couleur, hand2[i].nombre, hand2[i].special);
                    }
                    size_hand2--;
                    printf("la carte jouée est %c %d %d\n", pile[cpt_pile - 1].couleur, pile[cpt_pile - 1].nombre, pile[cpt_pile - 1].special);
                    printf("\ntour avant = %d\n", td.tour);
                    if (pile[cpt_pile - 1].special == 1) {
                        switch (pile[cpt_pile - 1].nombre) {
                            case 10:
                                pickTwoCards(pioche, &cpt_pioche, hand, &size_hand1);
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
                                pickFourCards(pioche, &cpt_pioche, hand, &size_hand1);
                                changeColor(pile, &cpt_pile);
                                break;
                        }
                        printf("\ntour après = %d\n", td.tour);
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
       td = next_tour(td.tour, td.direction);
     }
    checkWin(size_hand1, size_hand2);
    displayVictory(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

    