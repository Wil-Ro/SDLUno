#include "Card.h"
#include "RectMaths.h"
#include <string>


Card::Card(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color color, int value, bool facingPlayer, bool interactable)
{
	AddTexture(renderer, "textures/unoCard.png");
	cardBack = IMG_LoadTexture(renderer, "textures/unoCardBack.png");
	reverseIcon = IMG_LoadTexture(renderer, "textures/unoIconReverse.png");
	colourWheelIcon = IMG_LoadTexture(renderer, "textures/unoIconColourWheel.png");

	location = rect;
	SDL_QueryTexture(texture, NULL, NULL, &location.w, &location.h);
	location.w = 100;
	location.h = 150;

	this->color = color;
	this->value = value;
	this->facingPlayer = facingPlayer;
	this->interactable = interactable;

	std::string cardVal = std::to_string(value).c_str();
	switch (value)
	{
	case 10:
		cardVal = "+2";
		break;
	case 11:
		cardVal = "+4";
		break;
	}

	text = new Text(renderer, cardVal.c_str(), 50, location, {255, 255, 255, 255});
	text->CenterTexture(location);
}

Card::~Card()
{
	delete text;
}

void Card::RenderCall(SDL_Renderer* renderer)
{
	SDL_Rect location = this->location;

	MousePos mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	if (interactable && CheckMouseOver(mousePos))
	{
		location.y -= 30;
		zOrder = 10;
	}
	else if (CheckMouseOver(mousePos) && zOrder == 10)
	{
		zOrder = 0;
	}
	
	if (!facingPlayer)
	{
		SDL_RenderCopy(renderer, cardBack, NULL, &location);
		return;
	}


	// I think this is fine to hardcode
	SDL_Rect colorBacking = location;
	colorBacking.w -= 6;
	colorBacking.h -= 6;
	colorBacking.x += 3;
	colorBacking.y += 3;

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &colorBacking);

	if (SDL_RenderCopy(renderer, texture, NULL, &location) != 0)
	{
		SDL_LogError(0, "Failed to Render");
	}

	if (value == 12)
	{
		SDL_Rect iconLocation = {
			location.x + location.w / 8,
			location.y + location.h / 4,
			location.h / 2,
			location.h / 2
		};

		SDL_RenderCopy(renderer, reverseIcon, NULL, &iconLocation);
	}
	else
	{
		// set text location incase card has been moved
		text->CenterTexture(location);
		text->RenderCall(renderer);
	}
}

void Card::FlipCard()
{
	facingPlayer = !facingPlayer;
}

bool Card::HasLinkWith(Card* card)
{
	bool colorMatch = card->color.r == color.r && 
		card->color.g == color.g&&
		card->color.b == color.b&&
		card->color.a == color.a;

	bool valueMatch = card->value == value;
	
	return colorMatch || valueMatch;
}

int Card::GetValue()
{
	return value;
}
