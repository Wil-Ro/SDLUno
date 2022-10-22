#pragma once
#undef main
#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <algorithm>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 320

struct MousePos
{
	int x;
	int y;
};

typedef struct
{
	int x;
	int y;
	int dx;
	int dy;
	int health;
	SDL_Texture* texture;
} Entity;

typedef struct
{
	int up;
	int down;
	int left;
	int right;
} ControlScheme;

class SpaceShooter
{
public:
	SDL_Renderer *renderer;
	SDL_Window *window;

	bool initSDL();

	void processInputs();
	void processKeyDown(SDL_KeyboardEvent *event);
	void processKeyUp(SDL_KeyboardEvent *event);

	void prepareScene();
	void presentScene();

	SDL_Texture* loadTexture(const char* filename);
	void blit(SDL_Texture* texture, int x, int y);

	int up;
	int down;
	int left;
	int right;
	int fire;

	int speed = 4; // hee hee defining in .h, so cheeky

	void run();
};

