#pragma once
#include "Hand.h"
class PlayerHand :public Hand
{
private:

public:
	bool takingTurn;

	void PlayCard(Card* card);
	void DrawCard();
	void FillHand();

	int GetHandSize();

	PlayerHand(SDL_Rect rect, Deck* drawDeck, Deck* playDeck);
	void RenderCall(SDL_Renderer* renderer);
	void MouseDown(MousePos mouse);
};

