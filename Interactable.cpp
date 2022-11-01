#include "Interactable.h"

// hopefully these will get optimised out in compilation
void Interactable::Click(MousePos mouse)
{
	return;
}

void Interactable::MouseDown(MousePos mouse)
{
	return;
}

void Interactable::MouseUp(MousePos mouse)
{
	return;
}

// general code to be run every frame
void Interactable::Process()
{
	return;
}

bool Interactable::CheckMouseOver(MousePos mouse)
{
	if (location.x < mouse.x && mouse.x < (location.x + location.w) &&
		location.y < mouse.y && mouse.y < (location.y + location.h))
	{
		return true;
	}
	return false;
}