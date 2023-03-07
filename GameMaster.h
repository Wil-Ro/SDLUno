#pragma once
#include "Uno.h"
#include "Display.h"
#include "Deck.h"
#include "Character.h"
#include "PlayerCharacter.h"
#include "TurnIndicator.h"

#include <vector>

/*
GameMaster
This class holds all the players and controls their turn order, players hold their hands and calls
their render function.
*/

class GameMaster
{
public:
	GameMaster(Display* display, BaseEventHandler* handler, Deck* playDeck, Deck* drawDeck);
	void TakeTurn();
	void GivePlayerCard();

private:

	void OnEmptyDeck();
	void IncreaseTurn();

	int currentTurn = 0;
	std::vector<Character*> characters;

	Deck* playDeck;
	Deck* drawDeck;

	Display* display;

	TurnIndicator* turnIndicator;
	
};

