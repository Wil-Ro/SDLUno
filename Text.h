#pragma once
#include "Renderable.h"
#include <SDL2/SDL_ttf.h>
class Text:public Renderable
{
public:
	// Im so sorry this is an awful constructor
	Text(SDL_Renderer* renderer, const char* text, int size, SDL_Rect rect, SDL_Color fontColor = { 0, 0, 0, 255 }, const char* fileName = "fonts/OpenSans-Regular.ttf");
	void RenderCall(SDL_Renderer* renderer);
	void ChangeText(SDL_Renderer* renderer, const char* text);
	

	SDL_Color fontColor;
private:
	TTF_Font* font;
};

