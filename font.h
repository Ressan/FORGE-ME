#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED
#include "header.h"

#define FONT_LAZY 0
#define FONT_ALGERIA 1
#define FONT_AHRONBD 2
#define NB_FONT 3
#define AUTO_DEF_COO -1
#define CENTER -2

#define HOVER_FALSE 1
#define HOVER_TRUE 0

typedef struct bouton {
	int x;
	int y;
	int w;
	int h;
	int hover;
}t_bouton;

void initFont(TTF_Font* font[NB_FONT], SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture);

void TTF_CloseAllFont(TTF_Font* font[NB_FONT]);

SDL_Texture* SDL_Text(const char* text, int x, int y, int num_font, SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Rect* rectTexture, SDL_Renderer* renderer, SDL_Window* window);

SDL_Texture* SDL_Bouton(const char* text, int x, int y, int num_font, int hover,SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Rect* rectTexture, SDL_Renderer* renderer, SDL_Window* window);

void fromRectToBouton(SDL_Rect rect, t_bouton* btn);

int onBouton(SDL_Event event, t_bouton* btn);

#endif // FONT_INCLUDED