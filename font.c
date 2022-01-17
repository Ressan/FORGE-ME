#include "header.h"


void initFont(TTF_Font* font[NB_FONT], SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture)
{
	font[FONT_LAZY] = TTF_OpenFont("src/font/lazy.ttf", 48);
	if (font[FONT_LAZY] == NULL)
	{
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		SDL_ExitWithError("Creation font echoue");
	}
	font[FONT_ALGERIA] = TTF_OpenFont("src/font/Algeria-mZ9.ttf", 100);
	if (font[FONT_ALGERIA] == NULL)
	{
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		SDL_ExitWithError("Creation font echoue");
	}
	font[FONT_AHRONBD] = TTF_OpenFont("src/font/ahronbd.ttf", 48);
	if (font[FONT_AHRONBD] == NULL)
	{
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		SDL_ExitWithError("Creation font echoue");
	}
}

void TTF_CloseAllFont(TTF_Font* font[NB_FONT])
{
	for (int i=0;i< NB_FONT; i++)
	{
		TTF_CloseFont(font[i]);
	}
}


SDL_Texture* SDL_Text(const char* text, int x, int y, int num_font, SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Rect* rectTexture, SDL_Renderer* renderer, SDL_Window* window)
{
	//printf("\npre text : text %d rend %d\n", texture, renderer);

	SDL_Color Col_BLACK = { 0, 0, 0 };

	surface = TTF_RenderText_Solid(font[num_font], text, Col_BLACK);

	if (surface == NULL)
	{
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		SDL_ExitWithError("Creation surface echoue");
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		SDL_ExitWithError("Creation surface echoue");
	}

	if (SDL_QueryTexture(texture, NULL, NULL, &(rectTexture->w), &(rectTexture->h)) != 0)
	{
		TTF_CloseAllFont(font);
		SDL_DestroyAll(window, renderer, surface, texture);
		SDL_ExitWithError("Impossible charger texture");
	}

	if (x == CENTER)
	{
		rectTexture->x = (SCREEN_WIDTH - rectTexture->w) / 2;
	}
	else
	{
		rectTexture->x = x;
	}

	if (y == CENTER)
	{
		rectTexture->y = (SCREEN_HEIGHT - rectTexture->x) / 2;
	}
	else
	{
		rectTexture->y = y;
	}

	return texture;

}


/*
Fonction de type SDL_Texture de creation d'un bouton visuel (texte + rectangle de fond)
Renvoie la texture avec le bouton bien positionner sur celle-ci
*/
SDL_Texture* SDL_Bouton(const char* text, int x, int y, int num_font, int hover, SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Rect* rectTexture, SDL_Renderer* renderer, SDL_Window* window)
{
	//printf("\nTEST :  %d", TTF_GetFontOutline(font[num_font]));
	/*if (TTF_GetFontOutline(font[num_font]) == 0)
	{	
		printf("\n%s | Hover %d", text, hover);
		//printf("\n >> time :  % d", (SDL_GetTicks() % 2));
	}*/
	TTF_SetFontOutline(font[num_font], hover);
	texture = SDL_Text(text, x, y, num_font, surface, texture, font, rectTexture, renderer, window);

	if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible changer style font");




	//if (SDL_RenderFillRect(renderer, rectTexture) != 0)
	//SDL_ExitWithError(" Impossible dessiner Rectangle");

	return texture;
}

void fromRectToBouton(SDL_Rect rect, t_bouton* btn)
{
	btn->h = rect.h;
	btn->w = rect.w;
	btn->x = rect.x;
	btn->y = rect.y;
}

int hoverBouton(SDL_Event event,t_bouton* btn)
{
	if (btn->x <= event.motion.x && event.motion.x <= (btn->x + btn->w) && btn->y <= event.motion.y && event.motion.y <= (btn->y + btn->h))
	{
		btn->hover = HOVER_TRUE;
		//printf("\n X %d < %d < %d X+W | Y %d < %d < %d Y+H\n", btn->x, event.motion.x, (btn->x + btn->w), btn->y, event.motion.y, (btn->y + btn->h));
	}
	else
		btn->hover = HOVER_FALSE;
	return !(btn->hover);
}