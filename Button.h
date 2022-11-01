#pragma once
#include <SDL.h>
#include <functional>
#include "BaseStructs.h"
#include "Interactable.h"

class Button: public Interactable
{

public:
	virtual void MouseDown(MousePos mouse);
	bool CheckMouseOver(MousePos mouse);
	Button(SDL_Rect rect, void(*func)());
	Button(SDL_Rect rect, std::function<void()> func);
	void RenderCall(SDL_Renderer* renderer);

private:
	std::function<void()> func;

	
};

