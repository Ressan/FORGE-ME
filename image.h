#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include "header.h"

SDL_Texture*  SDL_TextureBmp(const char* img, SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Rect *rectTexture,SDL_Renderer* renderer, SDL_Window* window);

void SDL_RenderCopySecure(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Rect *rectTexture, SDL_Renderer* renderer, SDL_Window* window);


#endif // IMAGE_INCLUDED