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





#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Window *window;                    // Declare a window
    SDL_Renderer *renderer;                // Declare a renderer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow("Game Window",                     // window title
                              SDL_WINDOWPOS_UNDEFINED,           // initial x position
                              SDL_WINDOWPOS_UNDEFINED,           // initial y position
                              640,                               // width, in pixels
                              480,                               // height, in pixels
                              0                                  // flags
                              );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // The window is open: enter program loop (see SDL_PollEvent)
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            // Add more event types here as your game requires (keyboard input, mouse movement, etc)
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "card.h"
#include "player.h"
#include <SDL2/SDL.h>

void playGame() {

    storeCards(pioche);
    int tour = 1;
    int direction = 0;
    int cpt_pioche = 14;

    int cpt;
    for (cpt = 0; cpt != 5; cpt++) {
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

int main(int argc, char* argv[]) {
    SDL_Window *window;                    // Declare a window
    SDL_Renderer *renderer;                // Declare a renderer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow("Game Window",                     // window title
                              SDL_WINDOWPOS_UNDEFINED,           // initial x position
                              SDL_WINDOWPOS_UNDEFINED,           // initial y position
                              640,                               // width, in pixels
                              480,                               // height, in pixels
                              0                                  // flags
                              );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // The window is open: enter program loop (see SDL_PollEvent)
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            // Add more event types here as your game requires (keyboard input, mouse movement, etc)
        }

        SDL_RenderClear(renderer);
        // Add your game's render calls here
        playGame(); // Call your game logic here
        SDL_RenderPresent(renderer);
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Clean up
    SDL_Quit();
    return 0;
}