#include"CommonFunction.h"
#include"TextObject.h"


SDL_Surface* SDLCommonFunc::LoadImage(string file_name)
{
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;
	load_image = IMG_Load(file_name.c_str());
	if (load_image != NULL)
	{
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);
	}

	return optimize_image;
}



SDL_Rect SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
	return offset;
}

void SDLCommonFunc::Cleanup()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_background);
}

bool SDLCommonFunc::ShowMenu(SDL_Surface* des, TTF_Font* font)
{
	g_imagemenu = LoadImage("menu.png");
	if (g_imagemenu == NULL)
	{
		cout << "Can't load menu image!";
		return false;
	}

	TextObject text_menu;
	text_menu.SetColor(TextObject::WHITE_TEXT);
	
	text_menu.LoadTextFile("Menu.txt", font, des);

	SDL_Event menu_event;

	while (true)
	{
		SDLCommonFunc::ApplySurface(g_imagemenu, des, 0, 0);
		text_menu.SetRect(100, 100);
		text_menu.LoadTextFile("Menu.txt", font, des);
		while (SDL_PollEvent(&menu_event))
		{
			switch (menu_event.type)
			{
			case SDL_KEYDOWN:

			case SDL_QUIT:
				return 1;
			}
		}
		SDL_Flip(des);
	}
	
	return true;
}