#pragma once
#include "Renderable.h"
#include "Text.h"
#include <SDL_image.h>

const SDL_Color Red{ 219, 96, 96, 255 };
const SDL_Color Yellow{ 219, 213, 96, 255 };
const SDL_Color Green{ 99, 219, 96, 255 };
const SDL_Color Blue{ 96, 149, 219, 255 };

class Card :public Renderable
{
public:
	Card(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color color, int value, bool facingPlayer = true);
	~Card();
	void FlipCard();

	void RenderCall(SDL_Renderer* renderer);
private:
	SDL_Color color{0, 0, 0, 0};
	bool facingPlayer = true;
	int value;

	Text* text;
	
};

