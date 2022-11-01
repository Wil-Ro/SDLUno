#include "Hand.h"

Hand::Hand(Deck* deck)
{
	this->deck = deck;
}

void Hand::FillHand()
{
	for (int i = 0; i >= 7; i++)
	{
		DrawCard();
	}
}

void Hand::PlayCard(Card* card)
{
	deck->PlayCard(card);
}

void Hand::DrawCard()
{
	hand.push_back(deck->DrawCard());
}

void Hand::RenderCall(SDL_Renderer* renderable)
{
	// dont do anything here, this will be overridden by
	// the player 
	return;
}