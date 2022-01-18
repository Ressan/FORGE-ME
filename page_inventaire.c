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



void pageInventaire(SDL_Surface* surface, SDL_Texture* ohLaText, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window)
{
	t_bouton btn_retour = { 0,0,0,0,HOVER_FALSE };
	SDL_Texture* texture[5];
	SDL_Rect rectTexture[4];
	SDL_Rect grille;
	SDL_Rect rectBye;
	int i = 0, j = 0;

	/*----------------------BOUCLE---------------------*/
	SDL_bool inventaire_launched = SDL_TRUE;
	unsigned int frame_limit = 0;
	SDL_Event event;

	for (i = 0; i < 5; i++)
	{
		texture[i] = NULL;

	}

	rectTexture[0].x = 0;
	rectTexture[0].y = 0;
	rectTexture[0].h = AUTO_DEF_COO;
	//chargement fond d'eccran
	texture[0] = SDL_TextureBmp("src/img/bg.bmp", surface, texture[0], font, &rectTexture[0], renderer, window);
	SDL_RenderCopySecure(surface, texture[0], font, &rectTexture[0], renderer, window);

	//Chargement texte entete
	texture[1] = SDL_Text("INVENTAIRE", CENTER, 50, FONT_ALGERIA, surface, texture[1], font, &rectTexture[1], renderer, window);
	SDL_RenderCopySecure(surface, texture[1], font, &rectTexture[1], renderer, window);

	texture[2] = SDL_Bouton("< RETOUR", 50, 50, FONT_AHRONBD, btn_retour.hover, surface, texture[2], font, &rectTexture[2], renderer, window);
	SDL_RenderCopySecure(surface, texture[2], font, &rectTexture[2], renderer, window);
	fromRectToBouton(rectTexture[2], &btn_retour);

	btn_retour.hover = HOVER_TRUE;

	texture[3] = SDL_Bouton("< RETOUR", 50, 50, FONT_AHRONBD, btn_retour.hover, surface, texture[3], font, &rectTexture[3], renderer, window);
	SDL_RenderCopySecure(surface, texture[3], font, &rectTexture[3], renderer, window);
	fromRectToBouton(rectTexture[3], &btn_retour);

	rectBye.w = 500;
	rectBye.h = 500;
	rectBye.x = (SCREEN_WIDTH - rectBye.w) / 2;
	rectBye.y = (SCREEN_HEIGHT - rectBye.h) / 2;
	texture[4] = SDL_Text("BYE", CENTER, CENTER, FONT_LAZY, surface, texture[4], font, &rectBye, renderer, window);


	while (inventaire_launched)
	{
		frame_limit = SDL_GetTicks() + FPS_Limit;
		SDL_RenderClear(renderer);


		grille.x =  (SCREEN_WIDTH -(INV_CASE_W * CASE_NBC ))/ 2;
		grille.y = INV_BORD_H;
		grille.w = INV_CASE_W;
		grille.h = INV_CASE_H;

		for (i = 0; i < CASE_NBC; i++)
		{
			grille.x = i * INV_CASE_W + INV_BORD_W;
			if (SDL_RenderDrawRect(renderer, &grille) != 0)
				SDL_ExitWithError(" Impossible dessiner Rectangle");
			//SDL_RenderPresent(renderer);
			for (j = 0; j < CASE_NBL; j++)
			{
				grille.y = j * INV_CASE_H + INV_BORD_H;

				if (SDL_RenderDrawRect(renderer, &grille) != 0)
					SDL_ExitWithError(" Impossible dessiner Rectangle");
				//SDL_RenderPresent(renderer);
			}
		}

		for (i = 0; i < 2; i++)
		{
			SDL_RenderCopySecure(surface, texture[i], font, &rectTexture[i], renderer, window);
		}


		if (btn_retour.hover == HOVER_FALSE)
		{
			SDL_RenderCopySecure(surface, texture[2], font, &rectTexture[2], renderer, window);
		}
		else
		{
			SDL_RenderCopySecure(surface, texture[3], font, &rectTexture[2], renderer, window);
		}

		while (SDL_PollEvent(&event))
		{


			switch (event.type)
			{
			case SDL_QUIT:

				SDL_RenderClear(renderer);

				SDL_RenderCopySecure(surface, texture[4], font, &rectBye, renderer, window);
				SDL_RenderPresent(renderer);
				SDL_Delay(500);

				inventaire_launched = SDL_FALSE;
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
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					
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

	for ( i = 0; i < 5; i++)
	{
		SDL_DestroyTexture(texture[i]);

	}

}



