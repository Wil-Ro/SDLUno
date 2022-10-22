#include "Text.h"

Text::Text(SDL_Renderer* renderer, const char* text, int size, SDL_Rect rect, SDL_Color fontColor, const char* fileName)
{
	location = rect;

	font = TTF_OpenFont(fileName, size);

	this->fontColor = fontColor;

	ChangeText(renderer, text);
}

void Text::RenderCall(SDL_Renderer* renderer)
{
	SDL_QueryTexture(texture, NULL, NULL, &location.w, &location.h);
	if (SDL_RenderCopy(renderer, texture, NULL, &location) > 0)
	{
		SDL_LogError(0, "failed to render text");
	}
}

void Text::ChangeText(SDL_Renderer* renderer, const char* text)
{
	SDL_Surface* tempSurface;
	tempSurface = TTF_RenderUTF8_Blended(font, text, fontColor);

	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	SDL_FreeSurface(tempSurface);

	SDL_QueryTexture(texture, NULL, NULL, &location.w, &location.h);
}

