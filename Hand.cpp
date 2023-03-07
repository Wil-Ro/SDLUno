#include "Hand.h"

Hand::Hand()
{
	return;
}

Hand::Hand(Deck* drawDeck)
{
	this->drawDeck = drawDeck;
}

Hand::Hand(Deck* drawDeck, Deck* playDeck)
{
	this->drawDeck = drawDeck;
	this->playDeck = playDeck;
}

void Hand::FillHand()
{
	for (int i = 0; i <= 7; i++)
	{
		DrawCard();
	}
}

void Hand::PlayPlayableCard()
{
	for (Card* card : hand)
	{
		if (playDeck->CanTakeCard(card))
		{
			PlayCard(card);
			return;
		}
	}
	DrawCard();

}

int Hand::GetHandSize()
{
	return hand.size();
}

void Hand::PlayCard(Card* card)
{
	playDeck->PlayCard(card);

	// once card is added to deck, find and remove from hand
	auto it = std::find(hand.begin(), hand.end(), card);
	hand.erase(it);

	// also check for effect, if there is one, run it
	// e.g. reverse or wildcard
}

bool Hand::CanCardBePlayed(Card* card)
{
	return playDeck->CanTakeCard(card);
}

void Hand::DrawCard()
{
	hand.push_back(drawDeck->DrawCard());
}

void Hand::RenderCall(SDL_Renderer* renderable)
{
	// dont do anything here, this will be overridden by
	// the player
	return;
}