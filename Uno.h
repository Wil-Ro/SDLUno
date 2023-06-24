#pragma once
#include "Display.h"
#include "BaseEventHandler.h"
#include "Text.h"
#include "Button.h"
#include "GameMaster.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "PlayerHand.h"
#include "CharIndicator.h"
#include "CharIndicatorContainer.h"

#include "FPSCounter.h"

#include <SDL2/SDL.h>

#include <string>
#include <iostream>

class Uno
{
public:
	Uno();
	~Uno();

	void RunProgram();
	void RunMenu();
	void RunGame();
	void RunWinScreen(int winner = 0);

	void CardTest(Display* display, int gap = 5, int row = 4);


private:
	Display* display = NULL;

};

