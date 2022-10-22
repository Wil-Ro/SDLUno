#include <SDL.h>
#include <math.h>

class FPSCounter
{
private:
	int currentFrameCount = 0;
	int lastFrameCount = 0;
	Uint64 lastSecond = 0;
	int frequency;

public:
	FPSCounter(int frequency);
	void IncreaseFrameCount();
	int GetFrameCount();
};

