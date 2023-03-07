#include "Renderable.h"


void Renderable::RenderCall(SDL_Renderer* renderer)
{
	if (SDL_RenderCopy(renderer, texture, NULL, &location) != 0)
	{
		SDL_LogError(0, "Failed to Render");
	}
}

void Renderable::AddTexture(SDL_Renderer* renderer, const char* fileName)
{
	texture = IMG_LoadTexture(renderer, fileName);
	if (!texture)
	{
		SDL_LogError(0, "Failed to load image texture");
	}
}

/*
This takes a rect representing an area and will center the current texture
in the center of that rect. Make sure you set the width and height of the image
before hand as this uses it to center it
*/
void Renderable::CenterTexture(SDL_Rect rect)
{
	location.x = (rect.x + (rect.w / 2)) - (location.w / 2);
	location.y = (rect.y + (rect.h / 2)) - (location.h / 2);
}

// will return the coordinates of the corner of a rect given rect if it was centered
SDL_Rect Renderable::GetUncenteredRect(SDL_Rect rect)
{
	return { rect.x - rect.w / 2, rect.y - rect.h / 2, rect.w, rect.h };
}

SDL_Texture* Renderable::GetTexture()
{
	return texture;
}

SDL_Rect Renderable::GetLocation()
{
	return location;
}

void Renderable::SetLocation(SDL_Rect rect)
{
	location = rect;
}

void Renderable::ShiftLocation(SDL_Rect rect)
{
	location.x += rect.x;
	location.y += rect.y;
	location.w += rect.w;
	location.h += rect.h;
}
