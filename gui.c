#include "gui.h"
#include <SDL2/SDL.h>
#include "/usr/local/include/SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>
#include "card.h"
#define HAND_WIDTH 50
#define HAND_HEIGHT 75

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

    // Clear the renderer with the draw color
    SDL_RenderClear(renderer);

    // Update the screen with our rendered background
    SDL_RenderPresent(renderer);

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_RETURN2) {
                        running = 0;
                    }
                    break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}




char* getHandImageFilename(carte hand) {
    char* filename = malloc(20 * sizeof(char));
    sprintf(filename, "card_img/%c_%d_%d.png", hand.couleur, hand.nombre, hand.special);
    return filename;
}

SDL_Texture* loadHandImage(SDL_Renderer* renderer, carte hand) {
    char* filename = getHandImageFilename(hand);
    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    free(filename);
    return texture;
}

void drawHand(SDL_Renderer* renderer, carte hand, int x, int y) {
    // Check if renderer is NULL
    if (renderer == NULL) {
        printf("Renderer is NULL\n");
        return;
    }

    // Create a texture for the hand
    SDL_Texture* texture = loadHandImage(renderer, hand);
    if (texture == NULL) {
        printf("Could not create texture: %s\n", SDL_GetError());
        return;
    }

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = HAND_WIDTH;  
    rect.h = HAND_HEIGHT;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}
