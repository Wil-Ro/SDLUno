#pragma once
#include "Character.h"
#include "Display.h"
class PlayerCharacter : public Character
{
private:
	PlayerHand* hand;

public:
	void TakeTurn();
	void StartTurn();
	void EndTurn();
	PlayerCharacter(Display* display, Deck* drawDeck, Deck* playDeck, Hand** handReturn);
};

