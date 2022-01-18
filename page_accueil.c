#include "header.h"

void pageAccueil(SDL_Surface* surface, SDL_Texture* ohlatext, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window)
{
	t_bouton btn_inventaire = { 0,0,0,0,HOVER_TRUE };
	t_bouton btn_vitrine = { 0,0,0,0,HOVER_TRUE };
	t_bouton btn_aide = { 0,0,0,0,HOVER_TRUE };
	t_bouton btn_deconnexion = { 0,0,0,0,HOVER_TRUE };
	t_bouton btn_quitter = { 0,0,0,0,HOVER_TRUE };
	SDL_Texture *texture[12];
	SDL_Rect rectTexture[7];
	SDL_Rect rectBye;


	rectTexture[0].x = 0;
	rectTexture[0].y = 0;
	rectTexture[0].h = AUTO_DEF_COO;

	/*----------------------BOUCLE---------------------*/
	SDL_bool program_launched = SDL_TRUE;
	unsigned int frame_limit = 0;
	SDL_Event event;


	//chargement fond d'eccran
	texture[0] = SDL_TextureBmp("src/img/bg.bmp", surface, texture[0], font, &rectTexture[0], renderer, window);
	SDL_RenderCopySecure(surface, texture[0], font, &rectTexture[0], renderer, window);
	
	//Chargement texte entete
	texture[1] = SDL_Text("THE FORGE", CENTER, 50, FONT_ALGERIA, surface, texture[1], font, &rectTexture[1], renderer, window);
	SDL_RenderCopySecure(surface, texture[1], font, &rectTexture[1], renderer, window);
	//printf("test");


	//Chargement bouton pleins (quand on passe dessus)
	//printf("\n V %d | A %d | I %d ", btn_vitrine.hover, btn_inventaire.hover, btn_aide.hover);

	texture[2] = SDL_Bouton("VITRINE", CENTER, 200, FONT_AHRONBD, btn_vitrine.hover, surface, texture[2], font, &rectTexture[2], renderer, window);
	SDL_RenderCopySecure(surface, texture[2], font, &rectTexture[2], renderer, window);
	fromRectToBouton(rectTexture[2], &btn_vitrine);

	texture[3] = SDL_Bouton("INVENTAIRE", CENTER, 270, FONT_AHRONBD, btn_inventaire.hover, surface, texture[3], font, &rectTexture[3], renderer, window);
	SDL_RenderCopySecure(surface, texture[3], font, &rectTexture[3], renderer, window);
	fromRectToBouton(rectTexture[3], &btn_inventaire);

	texture[4] = SDL_Bouton("AIDE", CENTER, 340, FONT_AHRONBD, btn_aide.hover, surface, texture[4], font, &rectTexture[4], renderer, window);
	SDL_RenderCopySecure(surface, texture[4], font, &rectTexture[4], renderer, window);
	fromRectToBouton(rectTexture[4], &btn_aide);

	texture[5] = SDL_Bouton("DECONNEXION", CENTER, 520, FONT_AHRONBD, btn_deconnexion.hover, surface, texture[5], font, &rectTexture[5], renderer, window);
	SDL_RenderCopySecure(surface, texture[5], font, &rectTexture[5], renderer, window);
	fromRectToBouton(rectTexture[5], &btn_deconnexion);


	texture[6] = SDL_Bouton("QUITTER", CENTER, 580, FONT_AHRONBD, btn_quitter.hover, surface, texture[6], font, &rectTexture[6], renderer, window);
	SDL_RenderCopySecure(surface, texture[6], font, &rectTexture[6], renderer, window);
	fromRectToBouton(rectTexture[6], &btn_quitter);


	//Chargement bouton quand on passe pas dessus
	btn_aide.hover = HOVER_FALSE;
	btn_deconnexion.hover = HOVER_FALSE;
	btn_inventaire.hover = HOVER_FALSE;
	btn_quitter.hover = HOVER_FALSE;
	btn_vitrine.hover = HOVER_FALSE;

	texture[7] = 	SDL_Bouton("VITRINE", CENTER, 200, FONT_AHRONBD, btn_vitrine.hover, surface, texture[7], font, &rectTexture[2], renderer, window);
	SDL_RenderCopySecure(surface, texture[7], font, &rectTexture[2], renderer, window);

	texture[8] = SDL_Bouton("INVENTAIRE", CENTER, 270, FONT_AHRONBD, btn_inventaire.hover, surface, texture[8], font, &rectTexture[3], renderer, window);
	SDL_RenderCopySecure(surface, texture[8], font, &rectTexture[3], renderer, window);

	texture[9] = SDL_Bouton("AIDE", CENTER, 340, FONT_AHRONBD, btn_aide.hover, surface, texture[9], font, &rectTexture[4], renderer, window);
	SDL_RenderCopySecure(surface, texture[9], font, &rectTexture[4], renderer, window);

	texture[10] = SDL_Bouton("DECONNEXION", CENTER, 520, FONT_AHRONBD, btn_deconnexion.hover, surface, texture[10], font, &rectTexture[5], renderer, window);
	SDL_RenderCopySecure(surface, texture[10], font, &rectTexture[5], renderer, window);


	texture[11] = SDL_Bouton("QUITTER", CENTER, 580, FONT_AHRONBD, btn_quitter.hover, surface, texture[11], font, &rectTexture[6], renderer, window);
	SDL_RenderCopySecure(surface, texture[11], font, &rectTexture[6], renderer, window);
	
	while (program_launched)
	{
		frame_limit = SDL_GetTicks() + FPS_Limit;

		SDL_RenderClear(renderer);
		
		rectTexture[0].x = 0;
		rectTexture[0].y = 0;
		rectTexture[0].h = AUTO_DEF_COO;
		for (int i = 0; i < 12; i++)
		{
			SDL_RenderCopySecure(surface, texture[i], font, &rectTexture[i], renderer, window);
		}


		while (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
			case SDL_QUIT:
				program_launched = SDL_FALSE;

				/*
				
				SDL_RenderClear(renderer);
				texture = SDL_Text("BYE", CENTER, CENTER, FONT_LAZY, surface, texture, font, &rectBye, renderer, window);

				rectBye.w = 500;
				rectBye.h = 500;
				rectBye.x = (SCREEN_WIDTH - rectBye.w) / 2;
				rectBye.y = (SCREEN_HEIGHT - rectBye.h) / 2;;
				SDL_RenderCopySecure(surface, texture, font, &rectBye, renderer, window);
				SDL_RenderPresent(renderer);
				SDL_Delay(500);
				*/
				break;
			case SDL_MOUSEMOTION:
				//	printf("%d / %d\n", event.motion.x, event.motion.y);
				if (hoverBouton(event, &btn_vitrine))
				{
					//printf("\nOn vitrine\n");
					break;
				}
				else if (hoverBouton(event, &btn_inventaire))
				{
					//printf("\nOn inv\n");
					break;
				}
				else if (hoverBouton(event, &btn_aide))
				{
					//printf("\nOn aide\n");
					break;
				}
				else if (hoverBouton(event, &btn_deconnexion))
				{
					//printf("\nOn aide\n");
					break;
				}
				else if (hoverBouton(event, &btn_quitter))
				{
					//printf("\nOn aide\n");
					break;
				}
				continue;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					SDL_Delay(20); // petit input lag (sensation de click)
					if (hoverBouton(event, &btn_vitrine))
					{
						//vitrine(surface, texture, font, renderer, window);
						//printf("\nOn vitrine\n"); break;
					}
					else if (hoverBouton(event, &btn_inventaire))
					{
						pageInventaire(surface, texture, font, renderer, window);
						//inventaire(surface, texture, font, renderer, window);
						//printf("\nOn inv\n");	break;
					}
					else if (hoverBouton(event, &btn_aide))
					{	
						pageAide(surface, texture, font, renderer, window);
						//printf("\nOn aide\n"); break;
					}
					else if (hoverBouton(event, &btn_deconnexion))
					{
						//printf("\nOn aide\n");
						break;
					}
					else if (hoverBouton(event, &btn_quitter))
					{
						program_launched = SDL_FALSE;
						/*
						SDL_RenderClear(renderer);
						texture = SDL_Text("BYE", CENTER, CENTER, FONT_LAZY, surface, texture, font, &rectBye, renderer, window);

						rectBye.w = 500;
						rectBye.h = 500;
						rectBye.x = (SCREEN_WIDTH - rectBye.w) / 2;
						rectBye.y = (SCREEN_HEIGHT - rectBye.h) / 2;;
						SDL_RenderCopySecure(surface, texture, font, &rectBye, renderer, window);
						SDL_RenderPresent(renderer);
						SDL_Delay(500);
						*/
						
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

