#ifndef PAGE_AIDE_H_INCLUDED
#define PAGE_AIDE_H_INCLUDED
#include "header.h"
#define TEXTE_AIDE_LENGHT 106

void chargerTextAide(char* texteAide);
void pageAide(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window);

#endif // PAGE_AIDE_H_INCLUDED