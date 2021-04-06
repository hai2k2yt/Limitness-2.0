#include"TextObject.h"

TextObject::TextObject()
{
	text_color_ = { 0,0,0 };
}

TextObject::~TextObject()
{
	;
}

void TextObject::LoadTextFile(string path,TTF_Font* font,SDL_Surface* des)
{
	ifstream file;
	file.open(path);
	while (!file.eof())
	{
		getline(file, str_val_);
		CreateGameText(font, des);
		SetRect(rect_.x, rect_.y + 30);

	}
}

void TextObject::SetColor(const int& type)
{
	if (type == WHITE_TEXT)
	{
		text_color_ = { 255,255,255 };
	}
	else if (type == BLACK_TEXT)
	{
		text_color_ = { 0,0,0 };
	}
	else if (type == RED_TEXT)
	{
		text_color_ = { 255,0,0 };
	}
	else if (type == GREEN_TEXT)
	{
		text_color_ = { 0,255,0 };
	}
	else if (type == PINK_TEXT)
	{
		text_color_ = { 255,0,255 };
	}
	else if (type == YELLOW_TEXT)
	{
		text_color_ = { 255,0,255 };
	}
}

void TextObject::CreateGameText(TTF_Font* font, SDL_Surface* des)
{
	p_object_ = TTF_RenderText_Solid(font, str_val_.c_str(), text_color_);
	Show(des);
}
