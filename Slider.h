#pragma once
#include "Interactable.h"
#include "BaseEventHandler.h"
class Slider:public Interactable
{
public:
	Slider(SDL_Rect rect);
	bool CheckMouseOver(MousePos mouse);
	void RenderCall(SDL_Renderer* renderer);
	void MouseDown(MousePos mouse);
	void MouseUp(MousePos mouse);
	void Process();
	int GetValue();
	const char* GetValueAsString();

private:
	int value = 0;
	bool sliding = false;
	SDL_Rect sliderNodePos = {0, 0, 0, 0};
};

// this needs finishing
// check baseEventHandler, didnt finish MouseDownCheck stuff