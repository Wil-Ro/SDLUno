#include "Uno.h"

Uno::Uno()
{
	Display::init();
	display = new Display(1200, 700, "SDL Uno");
	return;
}

Uno::~Uno()
{
	delete display;
}

void Uno::RunProgram()
{
	//RunMenu();
	RunGame();
}


void Uno::RunGame()
{
	display->ClearRenderables();

	BaseEventHandler handler;

	GameMaster gameMaster;

	/*
	Card testCard1(display->renderer, { 50, 50, 0, 0 }, Red, 3, true, true);
	Card testCard2(display->renderer, { 100, 50, 0, 0 }, Yellow, 3, true, true);
	display->AddRenderable(&testCard1);
	display->AddRenderable(&testCard2);
	*/

	CardTest(display, -30, 1);

	while (true)
	{
		display->PrepareRender();

		handler.Handle();

		display->RenderAll();
		display->ProcessRender();

		SDL_Delay(10);
	}
	return;
}

void Uno::RunMenu()
{
	display->ClearRenderables(); 
	BaseEventHandler handler;

	Text menuText(display->renderer, "SDL Uno!", 80, {0, 0, 0, 0}, {255, 255, 255, 255});
	menuText.CenterTexture({ 0, 0, display->w(), display->h()/2 });
	display->AddRenderable(&menuText);

	Button startButton({200, 200, 200, 140}, [this](){RunGame();});
	startButton.AddTexture(display->renderer, "textures/UnoPlay.png");
	startButton.CenterTexture({ 0, 0, display->w(), display->h() });
	handler.AddInteractable(&startButton);
	display->AddRenderable(&startButton);

	while (true)
	{
		display->PrepareRender();

		handler.Handle();

		display->RenderAll();

		display->ProcessRender();

		SDL_Delay(10);
	}
	return;
}

// a test function that draws out all cards
void Uno::CardTest(Display* display, int gap, int row)
{
	if (row > 4)
		row = 4;

	SDL_Color colors[4] = {Red, Green, Blue, Yellow};
	for (int j = 0; j < row; j++)
	{
		for (int i = 0; i <= 10; i++)
		{
			display->AddRenderable(new Card(
				display->renderer,
				{ 5+(i*(100 + gap)), 5+(j * (150 + gap)), 0, 0},
				colors[j],
				i,
				true,
				true
			));
		}
	}
}


// rework card to work for hand and be buttons and such
// get hand working <- big task

// you should separate the hover stuff in button and card
// from render since its not to do with rendering and it means
// you still have interactable things when not added to that
// handler

// added z-reordering but its bad because it gives renderables
// more control of themselves in the pipeline.

// I guess the question here is which is worse, circular
// dependancies or resorting the list everytime we render

// if you get rid of this, remember to fix up card