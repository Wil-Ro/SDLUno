#include "FPSCounter.h"

void FPSCounter::IncreaseFrameCount()
{
	currentFrameCount++;
	if (SDL_GetTicks64() > (lastSecond + 1000/frequency))
	{
		lastSecond = SDL_GetTicks64();
		lastFrameCount = currentFrameCount*frequency;
		currentFrameCount = 0;
	}
}

int FPSCounter::GetFrameCount()
{
	return lastFrameCount;
}

FPSCounter::FPSCounter(int frequency)
{
	this -> frequency = frequency;
}