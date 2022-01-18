#ifndef PAGE_INVENTAIRE_H_INCLUDED
#define PAGE_INVENTAIRE_H_INCLUDED
#include "header.h"
#define VITR_BORD_W 300
#define VITR_BORD_H 200
#define VITR_CASE_W 96
#define VITR_CASE_H 96



void pageVitrine(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window);

#endif // PAGE_INVENTAIRE_H_INCLUDED