#pragma once
#include "Interactable.h"
#include "Text.h"

#ifdef _WIN32
#include <SDL_image.h>
#endif

#ifdef unix
#include <SDL2/SDL_image.h>
#endif

#define PLUS_TWO_CARD 10
#define PLUS_FOUR_CARD 11
#define REVERSE_CARD 12
#define WILD_CARD_CARD 13

/*
1-9 is normal values
10 - +2
11 - +4
12 - reverse
13 - wild card
*/

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

	int GetValue();
	SDL_Color GetColour();

	void OverrideColour(SDL_Color color);

	bool interactable = false;
	bool facingPlayer = true;

private:
	SDL_Color color{0, 0, 0, 0};
	int value;

	Text* text;

	SDL_Texture* cardBack;
	SDL_Texture* reverseIcon;
	SDL_Texture* colourWheelIcon;
	
};

