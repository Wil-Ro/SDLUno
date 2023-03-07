#pragma once
#include "Deck.h"
#include <vector>
/*
This class represents the hand of a character, it should only hold data on cards and render them
For the player there is a subclass called playerHand which also allows cards to be played

Any gameplay stuff such as turn taking is managed by the character class
*/

class Hand : public Interactable
{
public:

	Hand();
	Hand(Deck* drawDeck);
	Hand(Deck* drawDeck, Deck* playDeck);

	void DrawCard();
	void PlayCard(Card* card);
	void FillHand();
	bool CanCardBePlayed(Card* card);

	void PlayPlayableCard();

	virtual int GetHandSize();

	void RenderCall(SDL_Renderer* renderer);
protected:
	std::vector<Card*> hand;
	Deck* drawDeck = 0;
	Deck* playDeck = 0;
};


