#pragma once
#include "Renderable.h"
#include "BaseStructs.h"

class Interactable:public Renderable
{
public:
	virtual void Click(MousePos mouse);
	virtual void MouseDown(MousePos mouse);
	virtual void MouseUp(MousePos mouse);
	virtual void Process();

	virtual bool CheckMouseOver(MousePos mouse);

protected:
	
};

