/*
BaseEventHandler Class
This should do all the basic events you need to look into, namely system stuff
and ui stuff, any sort of game input should be done elsewhere
*/
#pragma once
#include <SDL.h>
#include <list>
#include "Button.h"
#include "BaseStructs.h"

class BaseEventHandler
{

	std::list<UiInteractable*> checkList;

public:
	void Handle();
	void AddInteractable(UiInteractable *toAdd);

	bool MouseStatus;

private:
	void MouseDownCheck(MousePos mousePos);
	void MouseUpCheck(MousePos mousePos);
	void RunProcess();
};

