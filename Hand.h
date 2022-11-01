#pragma once
#include "Deck.h"
#include <vector>
class Hand : public Renderable
{
public:

	Hand(Deck* deck);

	void DrawCard();
	void PlayCard(Card* card);
	void FillHand();

	void RenderCall(SDL_Renderer* renderer);
protected:
	std::vector<Card*> hand;
	Deck* deck;
};


