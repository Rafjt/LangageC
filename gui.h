#ifndef GUI_H
#define GUI_H
#include <SDL2/SDL.h>
#include "/usr/local/include/SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>
#include "card.h"

void displayGUI();
char* getHandImageFilename(carte hand);
SDL_Texture* loadHandImage(SDL_Renderer* renderer, carte hand);
void drawHand(SDL_Renderer* renderer, carte hand, int x, int y);
void displayVictory(SDL_Renderer* renderer);


#endif