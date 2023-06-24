/*
BaseEventHandler Class
This should do all the basic events you need to look into, namely system stuff
and ui stuff, any sort of game input should be done elsewhere
*/
#pragma once

#ifdef _WIN32
#include <SDL.h>
#endif

#ifdef unix
#include <SDL2/SDL.h>
#endif



#include <list>
#include "Button.h"
#include "BaseStructs.h"

class BaseEventHandler
{

	std::list<Interactable*> checkList;

public:
	void Handle();
	void AddInteractable(Interactable *toAdd);

	bool MouseStatus;

private:
	void MouseDownCheck(MousePos mousePos);
	void MouseUpCheck(MousePos mousePos);
	void RunProcess();
};

