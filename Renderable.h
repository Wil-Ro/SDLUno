#pragma once
#include "display.h"

#include <SDL.h>
#include <SDL_image.h>

#pragma message("compiled renderable")

class Display;

class Renderable
{
protected:
	int zOrder = 0;

	SDL_Texture* texture;
	SDL_Rect location;
public:
	
	virtual void ChangeZOrder(Display* display, int zOrder);
	virtual int GetZOrder();

	virtual void RenderCall(SDL_Renderer* renderer);
	virtual void AddTexture(SDL_Renderer* renderer, const char* fileName);
	virtual void CenterTexture(SDL_Rect rect);
	virtual SDL_Texture* GetTexture();
	virtual void SetLocation(SDL_Rect rect);
};

