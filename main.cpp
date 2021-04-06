#include "CommonFunction.h"
#include "TextObject.h"
#include "CardObject.h"

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		cout << "Can't load SDL!";
		return false;
	}
	
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
	{
		cout << "Cannot set screen!";
		return false;
	}

	if (TTF_Init() == -1)
	{
		cout << "Can't load SDL_ttf!";
		return false;
	}
	g_font_text = TTF_OpenFont("arial.ttf", 20);
	if (!g_font_text)
	{
		cout << "Can't load font text!";
		return false;
	}
	return true;
}

bool LoadData()
{
	g_background = SDLCommonFunc::LoadImage("background.png");
	if (g_background == NULL)
	{
		cout << "Can't load background image!";
		return false;

	}
	return true;
}



int main(int argc, char* argv[])
{
	bool is_quit = false;
	if (Init() == false || LoadData() == false)
	{
		return 1;
	}

	int ret_menu = SDLCommonFunc::ShowMenu(g_screen, g_font_text);
	if (ret_menu == false)
	{
		is_quit = true;
	}

	CardObject left_card;
	
	left_card.SetRect(300, 200);
	left_card.SetCard(CardObject::CARD_LEFT);
	left_card.SetCardOnOff();
	left_card.LoadImg("redcard.png");

	CardObject right_card;
	right_card.SetRect(1200, 200);
	right_card.SetCard(CardObject::CARD_RIGHT);
	right_card.SetCardOnOff();
	right_card.LoadImg("bluecard.png");

	CardObject main_card;
	main_card.SetRect(700, 400);
	main_card.LoadImg("maincard.png");



	while (!is_quit)
	{
		SDLCommonFunc::ApplySurface(g_background, g_screen, 0, 0);
		while (SDL_PollEvent(&g_even))
		{
			if (g_even.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			left_card.HandleInputAction(g_even);
			right_card.HandleInputAction(g_even);
		}


		left_card.Show(g_screen);
		right_card.Show(g_screen);
		main_card.Show(g_screen);



		if (SDL_Flip(g_screen) == -1)
		{
			cout << "Can't update screen!";
			return 1;
		}
			
	}
	SDLCommonFunc::Cleanup();
	SDL_Quit();
	return 0;
}