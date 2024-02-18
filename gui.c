#include "gui.h"
#include <SDL2/SDL.h>
#include "/usr/local/include/SDL2/SDL_image.h"

void displayGUI() {
    SDL_Window *window;                    
    SDL_Renderer* renderer;

    SDL_Init(SDL_INIT_VIDEO);              

    window = SDL_CreateWindow(
        "An SDL2 window",                  
        SDL_WINDOWPOS_UNDEFINED,           
        SDL_WINDOWPOS_UNDEFINED,           
        640,                               
        480,                               
        SDL_WINDOW_OPENGL                  
    );

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 53, 101, 77, 255); // Set renderer color to poker green

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);


    SDL_Surface* cardImage = IMG_Load("1_b.png");
if (!cardImage) {
    printf("IMG_Load: %s\n", IMG_GetError());
    // handle error
}

// Create a texture from the image
SDL_Texture* cardTexture = SDL_CreateTextureFromSurface(renderer, cardImage);
if (!cardTexture) {
    printf("SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
    // handle error
}

// Free the loaded image. We don't need it anymore since we now have a texture
SDL_FreeSurface(cardImage);

// Define where we want to draw the card. For example, at position (50, 50) and with size (100, 150)
SDL_Rect cardRect;
cardRect.x = 50;
cardRect.y = 50;
cardRect.w = 100;
cardRect.h = 150;

// Draw the card
SDL_RenderCopy(renderer, cardTexture, NULL, &cardRect);

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}

