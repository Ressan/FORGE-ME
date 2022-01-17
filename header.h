#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "font.h"
#include "image.h"
#include "ecran_affichage.h"

//Screen dimension constants

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 700
#define FPS_Limit 16

typedef struct forge
{
	char nom[25];
	char nomForge[25];
	int coins;
}t_forge;

typedef struct objet
{
	char nomObjet[25];
	int qteObjet;
	int prixObjet;
	char descObjet[50];
}t_objet;

void SDL_DestroyAll(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture);

void SDL_ExitWithError(const char* message);

void SDL_LimitFPS(unsigned int limit);

#endif // HEADER_H_INCLUDED