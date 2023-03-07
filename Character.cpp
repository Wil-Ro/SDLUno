#include "Character.h"

void Character::TakeTurn()
{
	if (SDL_GetTicks() > waitTime + 3000)
	{
		hand->PlayPlayableCard();
		turnTaken = true;
	}
}


void Character::StartTurn()
{
	waitTime = SDL_GetTicks();
	turn = true;
}

void Character::ResetTurn()
{
	turn = false;
	turnTaken = false;
}

void Character::ForceDrawCard()
{
	// just here to be overriden
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
