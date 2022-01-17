#include "header.h"

void pageInventaire(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window)
{
	SDL_Rect rectTexture;
	t_bouton btn_retour = { 0,0,0,0,HOVER_FALSE };
	int i = 0, j = 0;

	/*----------------------BOUCLE---------------------*/
	SDL_bool inventaire_launched = SDL_TRUE;
	unsigned int frame_limit = 0;
	SDL_Event event;

	while (inventaire_launched)
	{
		frame_limit = SDL_GetTicks() + FPS_Limit;
		SDL_RenderClear(renderer);
		rectTexture.x = 0;
		rectTexture.y = 0;
		rectTexture.h = AUTO_DEF_COO;
		texture = SDL_TextureBmp("src/img/bg.bmp", surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);


		texture = SDL_Text("INVENTAIRE", CENTER, 50, FONT_ALGERIA, surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);

		rectTexture.x =  (SCREEN_WIDTH -(CASE_W * CASE_NBC ))/ 2;
		rectTexture.y = BORD_H;
		rectTexture.w = CASE_W;
		rectTexture.h = CASE_H;

		for (i = 0; i < CASE_NBC; i++)
		{
			rectTexture.x = i * CASE_W + BORD_W;
			if (SDL_RenderDrawRect(renderer, &rectTexture) != 0)
				SDL_ExitWithError(" Impossible dessiner Rectangle");
			//SDL_RenderPresent(renderer);
			for (j = 0; j < CASE_NBL; j++)
			{
				rectTexture.y = j * CASE_H + BORD_H;

				if (SDL_RenderDrawRect(renderer, &rectTexture) != 0)
					SDL_ExitWithError(" Impossible dessiner Rectangle");
				//SDL_RenderPresent(renderer);
			}
		}

		//printf("\n V %d | A %d | I %d ", btn_vitrine.hover, btn_inventaire.hover, btn_aide.hover);
		texture = SDL_Bouton("< RETOUR", 50, 50, FONT_AHRONBD, btn_retour.hover, surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);
		fromRectToBouton(rectTexture, &btn_retour);

		while (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
			case SDL_QUIT:
				inventaire_launched = SDL_FALSE;
				SDL_RenderClear(renderer);
				texture = SDL_Text("BYE", CENTER, CENTER, FONT_LAZY, surface, texture, font, &rectTexture, renderer, window);

				rectTexture.w = 500;
				rectTexture.h = 500;
				rectTexture.x = (SCREEN_WIDTH - rectTexture.w) / 2;
				rectTexture.y = (SCREEN_HEIGHT - rectTexture.h) / 2;;
				SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);
				SDL_RenderPresent(renderer);
				SDL_Delay(500);
				break;
			case SDL_MOUSEMOTION:
				if (hoverBouton(event, &btn_retour))
				{
					break;
				}
				/*
				else if (hoverBouton(event, &btn_inventaire))
				{
					//printf("\nOn inv\n");
					break;
				}
				
				*/
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					SDL_Delay(20); // petit input lag (sensation de click)
					
					if (hoverBouton(event, &btn_retour))
					{
						inventaire_launched = SDL_FALSE;
						break;
					}
				}
				break;
			default:
				break;
			}
		}

		SDL_RenderPresent(renderer);
		SDL_LimitFPS(frame_limit);
	}

}