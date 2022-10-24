#pragma once
#include "Display.h"
#include "BaseEventHandler.h"
#include "Text.h"
#include "Button.h"
#include "GameMaster.h"
#include "Card.h"
#include "Deck.h"

#include <SDL.h>

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

	void CardTest(Display* display);

private:
	Display* display = NULL;

};

