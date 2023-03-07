#include "PlayerCharacter.h"

void PlayerCharacter::TakeTurn()
{
	// deck will no longer be taking a turn if a card has been played
	if (hand->takingTurn == false)
	{
		turnTaken = true;
	}
}

void PlayerCharacter::StartTurn()
{
	turn = true;
	hand->takingTurn = true;
}

void PlayerCharacter::ResetTurn()
{
	turn = false;
	hand->takingTurn = false;
	turnTaken = false;
}

int PlayerCharacter::GetHandSize()
{
	return hand->GetHandSize();
}

void PlayerCharacter::ForceDrawCard()
{
	hand->DrawCard();
	turnTaken = true;
}

PlayerCharacter::PlayerCharacter(Display* display, Deck* drawDeck, Deck* playDeck, Hand** handReturn)
{
	hand = new PlayerHand({ 30, 700 - 200, 1200 - 30, 200 }, drawDeck, playDeck);
	display->AddRenderable(hand);
	hand->FillHand();

	// returning the hand to the gameMaster to be put in the eventHandler
	*handReturn = hand;
}
