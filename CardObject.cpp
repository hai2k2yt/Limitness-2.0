#include"CardObject.h"

CardObject::CardObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = CARD_WIDTH;
	rect_.h = CARD_HEIGHT;
	card_type_ = CARD_NONE;
	status_ = false;
}

CardObject::~CardObject()
{

}

void CardObject::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_LEFT:
			if (card_type_ == CARD_LEFT)
			{
				status_ = true;
			}
			else
			{
				status_ = false;
			}
			break;
		case SDLK_RIGHT:
			if (card_type_ == CARD_RIGHT)
			{
				status_ = true;
			}
			else
			{
				status_ = false;
			}
			break;
		default:
			status_ = false;
			break;
		}
	}
	if (status_ == true)
	{
		rect_.y = card_on;
	}
	else
	{
		rect_.y = card_off;
	}
}
