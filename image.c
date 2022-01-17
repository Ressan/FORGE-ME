#include "header.h"


/*
Fonction de type SDL_Texture d'affichage d'un fichier BMP

Charge une image au format BMP et la copie sur une texture qui est renvoy�
*/
SDL_Texture* SDL_TextureBmp(const char* img, SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Rect* rectTexture, SDL_Renderer* renderer, SDL_Window* window)
{
	//On charge l'image sur une surface
	surface = SDL_LoadBMP(img);
	//Si le chargement a �chou�
	if (surface == NULL)
	{
		//D�sallocation des font de la fen�tre(window) du renderer, de la surface et de la texture
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		//Affichage du message d'erreur
		SDL_ExitWithError("Creation surface echoue");
	}
	
	//On cr�er une texture � partir de la surface comprenant l'image
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	//Si la cr�ation a �chou�
	if (texture == NULL)
	{
		//D�sallocation des font de la fen�tre(window) du renderer, de la surface et de la texture
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		//Affichage du message d'erreur
		SDL_ExitWithError("Creation texture echoue");
	}

	//Si on choisit de definir 
	//rectTexture->h != AUTO_DEF_COO || 
	if (rectTexture->h == AUTO_DEF_COO && SDL_QueryTexture(texture, NULL, NULL, &(rectTexture->w), &(rectTexture->h)) != 0)
	{
		//D�sallocation des font de la fen�tre(window) du renderer, de la surface et de la texture
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		//Affichage du message d'erreur
		SDL_ExitWithError("Creation surface echoue");
	}

	
	return texture;
}


void SDL_RenderCopySecure(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[], SDL_Rect *rectTexture, SDL_Renderer* renderer, SDL_Window* window)
{
	if (SDL_RenderCopy(renderer, texture, NULL, rectTexture) != 0)
	{
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		SDL_ExitWithError("Impossible de Render Copy ");
	}
}
