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

void FPSCounter::DrawSelf(SDL_Renderer* renderer)
{
	text->ChangeText(renderer, std::to_string(lastFrameCount).c_str());
	text->RenderCall(renderer);
}

FPSCounter::FPSCounter(SDL_Renderer* renderer, int frequency)
{
	this -> frequency = frequency;
	text = new Text(renderer, "0", 20, {5, 0, 0, 0}, {255, 255, 255, 255});
}

FPSCounter::FPSCounter(int frequency)
{
	this->frequency = frequency;
	text = 0;
}

FPSCounter::~FPSCounter()
{
	delete text;
}