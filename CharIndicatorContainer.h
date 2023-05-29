#pragma once
#include "Renderable.h"
#include "CharIndicator.h"
#include "GameMaster.h"

#include <vector>

class CharIndicatorContainer : public Renderable
{
public:
	CharIndicatorContainer(GameMaster* gameMaster, SDL_Renderer* renderer, SDL_Rect rect);
	~CharIndicatorContainer();
	void RenderCall(SDL_Renderer* renderer);


	void UpdateCharIndicators(int player, int prevPlayer);

private:
	std::vector<CharIndicator*> indicators;
	GameMaster* gameMaster;
};
