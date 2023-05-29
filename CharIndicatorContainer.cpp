#include "CharIndicatorContainer.h"

CharIndicatorContainer::CharIndicatorContainer(GameMaster* gameMaster, SDL_Renderer* renderer, SDL_Rect rect)
{
	this->gameMaster = gameMaster;
	this->location = rect;

	// adding padding
	this->location.x += 50;
	this->location.w -= 50;

	SDL_Rect indicatorLocation; // this might cause an issue as we keep giving the same object to each 'cator
	
	for (int i = 1; i < gameMaster->GetNumberOfPlayers(); i++)
	{
		indicatorLocation = {
			location.x + ((location.w/gameMaster->GetNumberOfPlayers())*i),
			location.y + location.h/2,
			150, 150
		};
		indicators.push_back(new CharIndicator(renderer, indicatorLocation));
		indicators.back()->SetHandSize(gameMaster->GetPlayerHandSize(i));
	}
	
}


void CharIndicatorContainer::UpdateCharIndicators(int character, int prevCharacter)
{
	if (character != 0)
	{
		character--;
		indicators[character]->SetTurn(true);
	}

	if (prevCharacter != 0)
	{
		prevCharacter--;

		indicators[prevCharacter]->SetHandSize(gameMaster->GetPlayerHandSize(prevCharacter + 1));
		indicators[prevCharacter]->SetTurn(false);
	}
}

CharIndicatorContainer::~CharIndicatorContainer()
{
	for (CharIndicator* indicator : indicators)
	{
		delete indicator;
	}
}

void CharIndicatorContainer::RenderCall(SDL_Renderer* renderer)
{
	for (CharIndicator* indicator : indicators)
	{
		indicator->RenderCall(renderer);
	}
}