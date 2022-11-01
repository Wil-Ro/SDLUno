#pragma once
#include "Deck.h"
#include <vector>
class Hand : public Interactable
{
public:

	Hand();
	Hand(Deck* drawDeck);
	Hand(Deck* drawDeck, Deck* playDeck);

	void DrawCard();
	void PlayCard(Card* card);
	void FillHand();

	void RenderCall(SDL_Renderer* renderer);
protected:
	std::vector<Card*> hand;
	Deck* drawDeck = 0;
	Deck* playDeck = 0;
};


