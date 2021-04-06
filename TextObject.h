#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_
#include"BaseObject.h"
#include<fstream>
#include<string>
#include<SDL_ttf.h>
#include<vector>

using namespace std;

class TextObject :public BaseObject
{
public:
	enum TextColor
	{
		WHITE_TEXT = 0,
		BLACK_TEXT = 1,
		RED_TEXT = 2,
		GREEN_TEXT = 3,
		PINK_TEXT = 4,
		YELLOW_TEXT = 5,

	};
	TextObject();
	~TextObject();
	void LoadTextFile(string path,TTF_Font* font,SDL_Surface* des);
	void SetText(const string& text) { str_val_ = text; }
	void SetColor(const int& type);
	void CreateGameText(TTF_Font* font, SDL_Surface* des);

private:
	string str_val_;
	SDL_Color text_color_;

};



#endif // !TEXT_OBJECT_H_

