#include "GameMaster.h"

GameMaster::GameMaster(Display* display)
{
	playDeck.FillDeck(display->renderer);

	// this might be a bad idea or not be allowed
	display->AddRenderable(&playDeck);
	display->AddRenderable(&drawDeck);
}
