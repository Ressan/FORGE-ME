#include "header.h"

void SDL_DestroyAll(SDL_Window* window, SDL_Renderer* renderer,SDL_Surface* surface, SDL_Texture *texture)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void SDL_ExitWithError(const char* message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    TTF_Quit();
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void SDL_LimitFPS(unsigned int limit)
{
    unsigned int ticks = SDL_GetTicks();

    if (limit < ticks)
        return;
    else if (limit > ticks + FPS_Limit)
        SDL_Delay(FPS_Limit);
    else
        SDL_Delay(limit - ticks);

}