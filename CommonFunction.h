#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<SDL.h>
#include<Windows.h>
#include<iostream>
#include<string>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

using namespace std;

#undef main

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define SCREEN_BPP 32

#define CARD_WIDTH 160
#define CARD_HEIGHT 100

#define RED_CARD_X 300
#define RED_CARD_Y 200
#define BLUE_CARD_X 1200
#define BLUE_CARD_Y 200

#define MAIN_CARD_X 800
#define MAIN_CARD_Y 400

#define CARD_PICK -50

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_background = NULL;

static SDL_Surface* g_imagemenu = NULL;
static SDL_Surface* g_instruction = NULL;

static SDL_Event g_even;

static TTF_Font* g_font_text = NULL;


namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(string file_name);
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void Cleanup();
	bool ShowMenu(SDL_Surface* des, TTF_Font* font);
}


#endif

