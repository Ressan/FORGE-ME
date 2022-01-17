#include "header.h"




void accueil(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window)
{
	SDL_Rect rectTexture;
	t_bouton btn_inventaire = { 0,0,0,0,HOVER_FALSE };
	t_bouton btn_vitrine = { 0,0,0,0,HOVER_FALSE };
	t_bouton btn_aide = { 0,0,0,0,HOVER_FALSE };

	rectTexture.x = 0;
	rectTexture.y = 0;
	rectTexture.h = AUTO_DEF_COO;


	/*----------------------BOUCLE---------------------*/
	SDL_bool program_launched = SDL_TRUE;
	unsigned int frame_limit = 0;
	SDL_Event event;
	
	while (program_launched)
	{
		frame_limit = SDL_GetTicks() + FPS_Limit;

		SDL_RenderClear(renderer);
		rectTexture.x = 0;
		rectTexture.y = 0;
		rectTexture.h = AUTO_DEF_COO;
		texture = SDL_TextureBmp("src/img/bg.bmp", surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderPresent(renderer);

		texture = SDL_Text("THE FORGE", CENTER, 50, FONT_ALGERIA, surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);

		//printf("\n V %d | A %d | I %d ", btn_vitrine.hover, btn_inventaire.hover, btn_aide.hover);
		texture = SDL_Bouton("VITRINE", CENTER, 200, FONT_AHRONBD, btn_vitrine.hover, surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);
		fromRectToBouton(rectTexture, &btn_vitrine);

		texture = SDL_Bouton("INVENTAIRE", CENTER, 300, FONT_AHRONBD, btn_inventaire.hover, surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);
		fromRectToBouton(rectTexture, &btn_inventaire);

		texture = SDL_Bouton("AIDE", CENTER, 400, FONT_AHRONBD, btn_aide.hover, surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);
		fromRectToBouton(rectTexture, &btn_aide);


		while (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
			case SDL_QUIT:
				program_launched = SDL_FALSE;
				SDL_RenderClear(renderer);
				SDL_Text("BYE", CENTER, CENTER, FONT_LAZY, surface, texture, font, &rectTexture, renderer, window);

				rectTexture.w = 500;
				rectTexture.h = 500;
				rectTexture.x = (SCREEN_WIDTH - rectTexture.w) / 2;
				rectTexture.y = (SCREEN_HEIGHT - rectTexture.h) / 2;;
				//SDL_RenderCopySecure(surface, texture, font, rectTexture, renderer, window);
				SDL_RenderPresent(renderer);
				SDL_Delay(500);
				break;
			case SDL_MOUSEMOTION:
				//	printf("%d / %d\n", event.motion.x, event.motion.y);
				if (onBouton(event, &btn_vitrine))
				{
					//printf("\nOn vitrine\n");
					break;
				}
				else if (onBouton(event, &btn_inventaire))
				{
					//printf("\nOn inv\n");
					break;
				}
				else if (onBouton(event, &btn_aide))
				{
					//printf("\nOn aide\n");
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					/*
					if (//co du bouton vitrine)
					{
						//vitrine(surface, texture, font, renderer, window);
					}
					else if (//co du bouton inventaire)
					{
						//inventaire(surface, texture, font, renderer, window);
					}
					else if (//co du bouton aide)
					{
						//aide(surface, texture, font, renderer, window);
					}*/
				}
				break;
			default:
				break;
			}
		}

		SDL_RenderPresent(renderer);
		SDL_LimitFPS(frame_limit);
	}

	/*----------------------FIN------------------------*/
	
}