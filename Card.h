#pragma once
#include "Interactable.h"
#include "Text.h"
#include <SDL_image.h>

// temp while testing new rendercall function
#include "Display.h"

const SDL_Color Red{ 219, 96, 96, 255 };
const SDL_Color Yellow{ 219, 213, 96, 255 };
const SDL_Color Green{ 99, 219, 96, 255 };
const SDL_Color Blue{ 96, 149, 219, 255 };

class Card :public Interactable
{
public:
	Card(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color color, int value, bool facingPlayer = true, bool interactable = false);
	~Card();
	void FlipCard();

	void RenderCall(SDL_Renderer* renderer);

	bool interactable = false;
private:
	SDL_Color color{0, 0, 0, 0};
	bool facingPlayer = true;
	int value;

	Text* text;
	
};

