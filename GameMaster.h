#pragma once
#include "Uno.h"
#include "Deck.h"

#include <vector>

class GameMaster
{
public:
	GameMaster(Display* display);

	Deck playDeck;
	Deck drawDeck;
private:
	
};

