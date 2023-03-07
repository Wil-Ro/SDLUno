#include "Character.h"

void Character::TakeTurn()
{
	// will return true when turn has been taken

	turnTaken = true;
}

void Character::StartTurn()
{
	turn = true;
}

void Character::EndTurn()
{
	turn = false;
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
