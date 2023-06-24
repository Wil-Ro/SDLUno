
#ifdef _WIN32
#include <SDL.h>
#endif

#ifdef unix
#include <SDL2/SDL.h>
#endif

#include <math.h>
#include <string>

#include "Text.h"

class FPSCounter
{
private:
	int currentFrameCount = 0;
	int lastFrameCount = 0;
	Uint64 lastSecond = 0;
	int frequency;

	Text* text;

public:
	FPSCounter(int frequency);
	FPSCounter(SDL_Renderer* renderer, int frequency);
	~FPSCounter();
	void IncreaseFrameCount();
	int GetFrameCount();
	void DrawSelf(SDL_Renderer* renderer);
};

