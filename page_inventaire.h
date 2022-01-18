#ifndef PAGE_INVENTAIRE_H_INCLUDED
#define PAGE_INVENTAIRE_H_INCLUDED
#include "header.h"
#define INV_BORD_W 300
#define INV_BORD_H 200
#define INV_CASE_W 96
#define INV_CASE_H 96
#define CASE_NBL 5
#define CASE_NBC 7

#define OBJ_POTION 0
#define OBJ_CHESTPLATE_IRON 1
#define OBJ_CHESTPLATE_DIAMOND 2
#define OBJ_AXE_IRON 3
#define OBJ_AXE_DIAMOND 4
#define OBJ_BOW 5
#define OBJ_HORSE_IRON 6
#define OBJ_HORSE_DIAMOND 7
#define NB_OBJ 8

//Type objet regroupant le nom de l'objet et sa description
//Données récupérer via la base SQL
typedef struct type_objet
{
	char nomObjet[25];
	char descObjet[50];
	SDL_Surface* img;
}t_type_objet;


//Stockage visuel de la position ans l'inventaire d'un item
typedef struct inventaire
{
	int id;
	int x, y;
}t_inventaire;


int initTypeObj(t_type_objet obj[NB_OBJ]);

void initInventaire(t_inventaire inventaire[CASE_NBL][CASE_NBC]);

void pageInventaire(SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font[NB_FONT], SDL_Renderer* renderer, SDL_Window* window);

#endif // PAGE_INVENTAIRE_H_INCLUDED