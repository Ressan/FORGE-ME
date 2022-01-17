#ifndef PAGE_INVENTAIRE_H_INCLUDED
#define PAGE_INVENTAIRE_H_INCLUDED
#include "header.h"
#define BORD_W 300
#define BORD_H 200
#define CASE_W 96
#define CASE_H 96
#define CASE_NBL 5
#define CASE_NBC 7

void pageInventaire(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window);

#endif // PAGE_INVENTAIRE_H_INCLUDED