#pragma once
#include "UiElement.h"
#include "BaseStructs.h"

class UiInteractable:public UiElement
{
public:
	virtual void Click(MousePos mouse);
	virtual void MouseDown(MousePos mouse);
	virtual void MouseUp(MousePos mouse);
	virtual void Process();
};

