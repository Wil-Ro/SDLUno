#include "Character.h"

void Character::TakeTurn()
{
	if (SDL_GetTicks() > waitCache + waitTime)
	{
		hand->PlayPlayableCard();
		turnTaken = true;
	}
}


void Character::StartTurn()
{
	waitCache = SDL_GetTicks();
	turn = true;
}

void Character::ResetTurn()
{
	turn = false;
	turnTaken = false;
}

void Character::ForceDrawCard(int numOfCards)
{
	for (int i = 0; i < numOfCards; i++)
	{
		hand->DrawCard();
	}
	turnTaken = true;
}

SDL_Color Character::PickNewColour()
{
	return hand->GetPlayableCard()->GetColour();
}

int Character::GetHandSize()
{
	return hand->GetHandSize();
}

Character::Character(Deck* drawDeck, Deck* playDeck)
{
	this->hand = new Hand(drawDeck, playDeck);
	hand->FillHand();
}

// this should not be called by anything other than child classes when they're being instantiated
Character::Character()
{
	return;
}

Character::~Character()
{
	delete hand;
}
