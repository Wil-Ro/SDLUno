#pragma once
#include "Hand.h"
class PlayerHand :public Hand
{
public:
	void RenderCall(SDL_Renderer* renderer);
};

