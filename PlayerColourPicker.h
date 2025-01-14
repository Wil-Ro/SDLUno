#pragma once

#ifdef _WIN32
#include <SDL.h>
#endif

#ifdef unix
#include <SDL2/SDL.h>
#endif

#include "Display.h"
#include "Renderable.h"
#include "BaseEventHandler.h"
#include "Card.h"

// this class pauses the game and opens a colour picker window
// its hacky but I'm not sure of another solution rn

class PlayerColorPicker
{
public:
	SDL_Color Run();

private:
	SDL_Color* chosenColor = NULL;

	void SetPickedColor(SDL_Color color);
};

