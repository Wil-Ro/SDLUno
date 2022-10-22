#include "Slider.h"
#include <iostream>
#include <string>

Slider::Slider(SDL_Rect rect)
{
	this->location = rect;
	this->sliderNodePos = { location.x, location.y - 2, 10, 10 };
}

bool Slider::CheckMouseOver(MousePos mouse)
{
	if (sliderNodePos.x < mouse.x && mouse.x < (sliderNodePos.x + sliderNodePos.w) &&
		sliderNodePos.y < mouse.y && mouse.y < (sliderNodePos.y + sliderNodePos.h))
	{
		return true;
	}
	return false;
}

void Slider::RenderCall(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 90, 90, 90, 255);
	SDL_Rect drawRect = {location.x, location.y, location.w, 5};
	SDL_RenderFillRect(renderer, &drawRect);
;
	
	if (SDL_RenderCopy(renderer, texture, NULL, &sliderNodePos))
	{
		SDL_LogError(0, "Failed to render slider node");
	}
}

void Slider::MouseDown(MousePos mouse)
{
	if (CheckMouseOver(mouse))
		sliding = true;
}

void Slider::MouseUp(MousePos mouse)
{
	sliding = false;
}

void Slider::Process()
{
	if (sliding)
	{
		SDL_GetMouseState(&sliderNodePos.x, 0);
		sliderNodePos.x = SDL_clamp(sliderNodePos.x, location.x, location.x + location.w);
		float valueCache = (float)(sliderNodePos.x - location.x) / (float)location.w;
		value = valueCache * 100;
	}
}

int Slider::GetValue()
{
	return value;
}

const char* Slider::GetValueAsString()
{
	//fuck this man this is hard
	const char* tempChar = "woooblydoobly";
	return tempChar;
}