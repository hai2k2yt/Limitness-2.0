#ifndef CARD_OBJECT_H_
#define CARD_OBJECT_H_

#include"BaseObject.h"
#include"CommonFunction.h"

class CardObject :public BaseObject
{
public:
	enum CardStatus
	{
		CARD_NONE = 0,
		CARD_MAIN = 1,
		CARD_LEFT = 2,
		CARD_RIGHT = 3,
	};
	CardObject();
	~CardObject();
	void HandleInputAction(SDL_Event events);
	void SetCard(int CardType) { card_type_ = CardType; }
	void SetCardOnOff() { card_on = rect_.y - 100, card_off = rect_.y; }
	int GetCard(){ return card_type_; }
private:
	int card_on;
	int card_off;

	int card_type_;
	bool status_;
};

#endif
