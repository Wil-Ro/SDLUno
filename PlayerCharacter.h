#pragma once
#include "Character.h"
#include "Display.h"
#include "PlayerColourPicker.h"

class PlayerCharacter : public Character
{
private:
	PlayerHand* hand;

public:
	void TakeTurn();
	void StartTurn();
	void ResetTurn();

	void ForceDrawCard(int numOfCards = 1);

	SDL_Color PickNewColour();

	int GetHandSize();

	PlayerCharacter(Display* display, Deck* drawDeck, Deck* playDeck, Hand** handReturn);
};
