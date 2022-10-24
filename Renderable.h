#pragma once
#include <SDL.h>

class Renderable
{
protected:
	SDL_Texture* texture;
	SDL_Rect location;
public:
	virtual void RenderCall(SDL_Renderer* renderer);
	virtual void AddTexture(SDL_Renderer* renderer, const char* fileName);
	virtual void CenterTexture(SDL_Rect rect);
	virtual SDL_Texture* GetTexture();
	virtual void SetLocation(SDL_Rect rect);
};

