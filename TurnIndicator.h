#pragma once
#include <string>

#include "Text.h"
#include "Display.h"
class TurnIndicator
{
private:
	int turn = 0;
	Text* text;
	Display* display;
	SDL_Rect location;

public:
	TurnIndicator(Display* display, SDL_Rect rect);
	void setTurn(int turn);
};

