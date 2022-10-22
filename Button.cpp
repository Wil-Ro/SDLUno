#include "Button.h"

Button::Button(SDL_Rect rect, void(*func)())
{
	this->location = rect;
	this->func = func;
}

Button::Button(SDL_Rect rect, std::function<void()> func)
{
	this->location = rect;
	this->func = func;
}


void Button::MouseDown(MousePos mouse)
{
	if (CheckMouseOver(mouse))
	{
		func();
	}
}

bool Button::CheckMouseOver(MousePos mouse)
{
	if (location.x < mouse.x  && mouse.x < (location.x + location.w) && 
		location.y < mouse.y && mouse.y < (location.y + location.h))
	{
		return true;
	}
	return false;
}

void Button::RenderCall(SDL_Renderer* renderer)
{
	MousePos mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);


	if (CheckMouseOver(mousePos))
	{
		SDL_SetTextureColorMod(texture, 100, 100, 100);
	}
	else
	{
		SDL_SetTextureColorMod(texture, 255, 255, 255);
	}

	if (SDL_RenderCopy(renderer, texture, NULL, &location) != 0)
	{
		SDL_LogError(0, "Failed to Render");
	}
}