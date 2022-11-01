#include "Card.h"
#include "RectMaths.h"
#include <string>


Card::Card(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color color, int value, bool facingPlayer, bool interactable)
{
	AddTexture(renderer, "textures/unoCard.png");

	location = rect;
	SDL_QueryTexture(texture, NULL, NULL, &location.w, &location.h);
	location.w = 100;
	location.h = 150;

	this->color = color;
	this->value = value;
	this->facingPlayer = facingPlayer;
	this->interactable = interactable;

	text = new Text(renderer, std::to_string(value).c_str(), 50, location, {255, 255, 255, 255});;
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
	else if (!CheckMouseOver(mousePos) && zOrder == 10)
	{
		zOrder = 0;
	}
	
	if (!facingPlayer)
	{
		SDL_Texture* cardBack = IMG_LoadTexture(renderer, "textures/unoCardBack.png");
		if (SDL_RenderCopy(renderer, cardBack, NULL, &location) != 0)
		{
			SDL_LogError(0, "Failed to Render");
		}
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
	// set text location incase card has been moved
	text->CenterTexture(location);
	text->RenderCall(renderer);
}

void Card::FlipCard()
{
	facingPlayer = !facingPlayer;
}
