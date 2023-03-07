#pragma once
#include "Interactable.h"
#include "Text.h"
#include <SDL_image.h>

// ###IMPORTANT INFO###
// card must always have cardBack defined before use, normally
// at the top of main before the renderloop

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

	bool HasLinkWith(Card* card);

	void RenderCall(SDL_Renderer* renderer);

	bool interactable = false;
	bool facingPlayer = true;

private:
	SDL_Color color{0, 0, 0, 0};
	int value;

	Text* text;

	SDL_Texture* cardBack;
	
};

