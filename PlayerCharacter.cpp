#include "PlayerCharacter.h"

void PlayerCharacter::TakeTurn()
{
	// will return true when turn taken
	turnTaken = true;
}

void PlayerCharacter::StartTurn()
{
	turn = true;
	hand->takingTurn = true;
}

void PlayerCharacter::EndTurn()
{
	turn = false;
	hand->takingTurn = false;
}

PlayerCharacter::PlayerCharacter(Display* display, Deck* drawDeck, Deck* playDeck, Hand** handReturn)
{
	hand = new PlayerHand({ 30, 700 - 200, 1200 - 30, 200 }, drawDeck, playDeck);
	display->AddRenderable(hand);
	hand->FillHand();

	// returning the hand to the gameMaster to be put in the eventHandler
	*handReturn = hand;
}
