#include "CharIndicator.h"

CharIndicator::CharIndicator(SDL_Renderer* renderer, SDL_Rect rect)
{
	icon = IMG_LoadTexture(renderer, "textures/playerIcon.png");
	if (!icon)
		SDL_LogError(0, "Failed to load image texture");

	blankCard = IMG_LoadTexture(renderer, "textures/unoCardBack.png");
	if (!blankCard)
		SDL_LogError(0, "Failed to load image texture");

	location = GetUncenteredRect(rect);

}

void CharIndicator::SetHandSize(int size)
{
	handSize = size;
}

void CharIndicator::SetTurn(bool turn)
{
	this->turn = turn;
}

void CharIndicator::RenderCall(SDL_Renderer* renderer)
{
	if (turn)
		SDL_RenderCopyEx(renderer, icon, NULL, &location, sin(SDL_GetTicks()/100.0)*10, NULL, SDL_FLIP_NONE);
	else
		SDL_RenderCopy(renderer, icon, NULL, &location);

	SDL_Rect cardPos;
	for (int i = 0; i < handSize; i++)
	{
		cardPos = {location.x + ((location.w/handSize)*i), location.y+location.h+5, 20, 35};
		SDL_RenderCopy(renderer, blankCard, NULL, &cardPos);
	}
}