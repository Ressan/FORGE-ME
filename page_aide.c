#include "header.h"
void chargerTextAide(char* texteAide,SDL_Rect* rectTexture, SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window)
{
	char le_caractere;
	FILE* fichier = NULL;
	errno_t err;
	int i = 0;
	err = fopen_s(&fichier, "src/aide.txt", "r");
	if (err != 0)
	{
		printf("probleme d'ouverture\n");
	}
	else
	{
		le_caractere = fgetc(fichier);
		rewind(fichier);
		do
		{
			//puts(texteAide);
			texture = SDL_Text(texteAide, BORD_W, BORD_H+i*30, FONT_AHRONBD, surface, texture, font, rectTexture, renderer, window);
			SDL_RenderCopySecure(surface, texture, font, rectTexture, renderer, window);
			i++;
		} while (fgets(texteAide, TEXTE_AIDE_LENGHT, fichier) != NULL);
	}
	fclose(fichier);
}
void pageAide(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window)
{
	char texteAide[TEXTE_AIDE_LENGHT];
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


		texture = SDL_Text("AIDE", CENTER, 50, FONT_ALGERIA, surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);

		TTF_SetFontSize(font[FONT_AHRONBD], 24);
		TTF_SetFontOutline(font[FONT_AHRONBD], NULL);
		chargerTextAide(texteAide,&rectTexture, surface, texture, font, renderer, window);

		texture = SDL_Text(texteAide, BORD_W, BORD_H, FONT_AHRONBD, surface, texture, font, &rectTexture, renderer, window);
		SDL_RenderCopySecure(surface, texture, font, &rectTexture, renderer, window);
		TTF_SetFontSize(font[FONT_AHRONBD], 48);

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