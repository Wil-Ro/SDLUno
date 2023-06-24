#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Renderable
{
protected:

	SDL_Texture* texture;
	SDL_Rect location;
public:

	virtual void RenderCall(SDL_Renderer* renderer);

	virtual void AddTexture(SDL_Renderer* renderer, const char* fileName);
	virtual SDL_Texture* GetTexture();

	virtual void CenterTexture(SDL_Rect rect);
	virtual void SetLocation(SDL_Rect rect);
	virtual void ShiftLocation(SDL_Rect rect);
	static SDL_Rect GetUncenteredRect(SDL_Rect rect);
	SDL_Rect GetLocation();


	int zOrder = 0;
};

