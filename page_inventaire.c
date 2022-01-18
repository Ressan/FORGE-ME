#include "header.h"

int initTypeObj(t_type_objet obj[NB_OBJ])
{

	strcpy(obj[OBJ_POTION].nomObjet, "O la POT");
	strcpy(obj[OBJ_AXE_DIAMOND].nomObjet, "Diamond AXE");
	strcpy(obj[OBJ_AXE_IRON].nomObjet, "Iron AXE");
	strcpy(obj[OBJ_BOW].nomObjet, "Bow");
	strcpy(obj[OBJ_CHESTPLATE_IRON].nomObjet, "Iron Chestplate");
	strcpy(obj[OBJ_CHESTPLATE_DIAMOND].nomObjet, "Diamond Chestplate");
	strcpy(obj[OBJ_HORSE_DIAMOND].nomObjet, "Diamond Horse");
	strcpy(obj[OBJ_HORSE_IRON].nomObjet, "Iron Horse");

	for (int i = 0; i < NB_OBJ; i++)
	{
		strcpy(obj[i].descObjet, "Objet #%d, tah les effets",i);
		obj[i].img = IMG_Load("%d.png", i);
	}
}


void initInventaire(t_inventaire inventaire[CASE_NBL][CASE_NBC])
{
	for (int i = 0; i < CASE_NBL; i++)
	{
		for (int j = 0; j < CASE_NBC; j++)
		{
			if (rand() % 3 == 0)
				inventaire[CASE_NBL][CASE_NBC].id = (rand() % 8) + 1;
			inventaire[CASE_NBL][CASE_NBC].x = i * INV_CASE_W + INV_BORD_W;
			inventaire[CASE_NBL][CASE_NBC].y = j * INV_CASE_H + INV_BORD_H;
		}
	}
}



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

		rectTexture.x =  (SCREEN_WIDTH -(INV_CASE_W * CASE_NBC ))/ 2;
		rectTexture.y = INV_BORD_H;
		rectTexture.w = INV_CASE_W;
		rectTexture.h = INV_CASE_H;

		for (i = 0; i < CASE_NBC; i++)
		{
			rectTexture.x = i * INV_CASE_W + INV_BORD_W;
			if (SDL_RenderDrawRect(renderer, &rectTexture) != 0)
				SDL_ExitWithError(" Impossible dessiner Rectangle");
			//SDL_RenderPresent(renderer);
			for (j = 0; j < CASE_NBL; j++)
			{
				rectTexture.y = j * INV_CASE_H + INV_BORD_H;

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



