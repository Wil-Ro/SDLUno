#pragma once
#include "Renderable.h"
#include "Card.h"

#include <stack>

class Deck :Renderable
{
public:
	Deck(SDL_Rect rect);

	Card* DrawCard();
	void PlayCard(Card* card, bool flipCard = true);
	void FillDeck(SDL_Renderer* renderer);
private:
	std::stack<Card*> deck;

	void RefreshTopTexture();
};