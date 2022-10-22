#include "spaceShooter.h"

void SpaceShooter::run()
{

	initSDL();

	Entity player;
	player.x = 100;
	player.y = 100;
	player.dx = 0;
	player.dy = 0;
	player.texture = loadTexture("textures/player.png");

	Entity bullet;
	bullet.x = 0;
	bullet.y = 0;
	bullet.dx = 0;
	bullet.dy = 0;
	bullet.health = 0;
	bullet.texture = loadTexture("textures/bullet.png");


	while (1)
	{
		prepareScene();

		processInputs();
		player.y += player.dy;
		player.x += player.dx;
		player.y += (down * speed) - (up * speed);
		player.x += (right * speed) - (left * speed);

		if (fire && bullet.health == 0)
		{
			bullet.x = player.x;
			bullet.y = player.y;
			bullet.dx = 16;
			bullet.dy = 0;
			bullet.health = 1;
		}

		bullet.x += bullet.dx;
		bullet.y += bullet.dy;

		if (bullet.x > SCREEN_WIDTH)
		{
			bullet.health = 0;
		}

		if (bullet.health > 0)
		{
			blit(bullet.texture, bullet.x, bullet.y);
		}

		blit(player.texture, player.x, player.y);

		presentScene();

		SDL_Delay(16);
	}
}

void SpaceShooter::processInputs()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			processKeyDown(&event.key);
			break;

		case SDL_KEYUP:
			processKeyUp(&event.key);
			break;

		default:
			break;
		}
	}
}

void SpaceShooter::processKeyDown(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{
		switch (event->keysym.scancode)
		{
		case SDL_SCANCODE_UP:
			up = 1;
			break;
		case SDL_SCANCODE_DOWN:
			down = 1;
			break;
		case SDL_SCANCODE_LEFT:
			left = 1;
			break;
		case SDL_SCANCODE_RIGHT:
			right = 1;
			break;
		case SDL_SCANCODE_LCTRL:
			fire = 1;
			break;
		}
	}
}

void SpaceShooter::processKeyUp(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{
		switch (event->keysym.scancode)
		{
		case SDL_SCANCODE_UP:
			up = 0;
			break;
		case SDL_SCANCODE_DOWN:
			down = 0;
			break;
		case SDL_SCANCODE_LEFT:
			left = 0;
			break;
		case SDL_SCANCODE_RIGHT:
			right = 0;
			break;
		case SDL_SCANCODE_LCTRL:
			fire = 1;
			break;
		}
	}
}

void SpaceShooter::prepareScene()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void SpaceShooter::presentScene()
{
	SDL_RenderPresent(renderer);
}

SDL_Texture* SpaceShooter::loadTexture(const char* filename)
{
	SDL_Texture* texture; // what does the indirection operator do when its next to a variable name vs next to a type? Who the fuck knows!

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(renderer, filename);

	if (texture == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "FAILED TO LOAD FILE %s", filename);
	}


	return texture;
}

void SpaceShooter::blit(SDL_Texture* texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	if (SDL_RenderCopy(renderer, texture, NULL, &dest) != 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "FAILED TO BLIT IMAGE");
	}
}

bool SpaceShooter::initSDL()
{
	int rendererFlags, windowFlags;
	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO < 0))
	{
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0)
	{
		return false;
	}

	window = SDL_CreateWindow("Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!window)
	{
		return false;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	if (!renderer)
	{
		return false;
	}



	return true;
}
