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

void Renderable::CenterTexture(SDL_Rect rect)
{
	location.x = (rect.x + (rect.w / 2)) - (location.w / 2);
	location.y = (rect.y + (rect.h / 2)) - (location.h / 2);
}

SDL_Texture* Renderable::GetTexture()
{
	return texture;
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
