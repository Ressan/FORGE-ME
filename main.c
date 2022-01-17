#include "header.h"

int main(int argc, char** argv)
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	//Lancement SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("Erreur initialisation SDL");

	//Lancement Module SDL font
	if (TTF_Init() != 0)
		SDL_ExitWithError("Erreur initialisation TTF Sdl");

	//Creation de la fenetre et du rendu
	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) != 0)
		SDL_ExitWithError("Creation fenetre et rendu echouee");

	/*----------------------ECRIRE---------------------*/
	
	TTF_Font* font[NB_FONT] = { NULL, NULL,NULL };
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	
	initFont(font, window, renderer, surface, texture);

	/*----------------------BOUCLE---------------------*/
	pageAccueil(surface, texture, font, renderer, window);
	printf("finito");
	/*----------------------FIN------------------------*/

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	TTF_CloseAllFont(font);
	TTF_Quit();
	SDL_Quit();

	return EXIT_SUCCESS;
}


