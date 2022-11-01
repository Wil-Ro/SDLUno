#include "BaseEventHandler.h"

void BaseEventHandler::Handle()
{
	SDL_Event event;
	MousePos mousePos;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			exit(0);
			break;

		case SDL_MOUSEBUTTONDOWN:
			MouseStatus = true;
			SDL_GetMouseState(&mousePos.x, &mousePos.y);
			MouseDownCheck(mousePos);
			break;
		case SDL_MOUSEBUTTONUP:
			MouseStatus = false;
			SDL_GetMouseState(&mousePos.x, &mousePos.y);
			MouseUpCheck(mousePos);
			break;
		}
	}

	RunProcess();
};

void BaseEventHandler::MouseDownCheck(MousePos mousePos)
{
	for (Interactable* inter : checkList)
	{
		inter->MouseDown(mousePos);
	}
}

void BaseEventHandler::MouseUpCheck(MousePos mousePos)
{
	for (Interactable* inter : checkList)
	{
		inter->MouseUp(mousePos);
	}
}

void BaseEventHandler::RunProcess()
{
	for (Interactable* inter : checkList)
	{
		inter->Process();
	}
}

void BaseEventHandler::AddInteractable(Interactable* toAdd)
{
	checkList.push_front(toAdd);
}