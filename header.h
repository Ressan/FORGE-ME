#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "font.h"
#include "image.h"
#include "page_accueil.h"
#include "page_inventaire.h"
#include "page_aide.h"

//Screen dimension constants

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 700
#define FPS_Limit 16




//Stockage visuel de la position dans la vitrine d'un item
typedef struct vitrine
{
	int id;
	int x, y;
}t_vitrine;

typedef struct forge
{
	char nom[25];
	char nomForge[25];
	int coins;
}t_forge;


void SDL_DestroyAll(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture);

void SDL_ExitWithError(const char* message);

void SDL_LimitFPS(unsigned int limit);

#endif // HEADER_H_INCLUDED