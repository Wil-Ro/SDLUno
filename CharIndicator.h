#pragma once
#include "Renderable.h"

/*
This represents a single enemy character, it should be kept within CharacterIndicatorContainer
its purpose is to give a visual representation of a character playing the game, showing
their hand size and when they're taking their turn
*/

class CharIndicator : public Renderable
{
public:
	CharIndicator(SDL_Renderer* renderer, SDL_Rect rect);
	void RenderCall(SDL_Renderer* renderer);

	void SetHandSize(int size);
	void SetTurn(bool turn);

private:
	bool turn = false;
	int handSize = 0;

	SDL_Texture* blankCard;
	SDL_Texture* icon;


};

