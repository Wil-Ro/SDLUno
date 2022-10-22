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
	RunMenu();
	//RunGame();
}

void Uno::RunGame()
{
	display->ClearRenderables();

	BaseEventHandler handler;

	GameMaster gameMaster;


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
void Uno::CardTest(Display* display)
{
	SDL_Color colors[4] = {Red, Green, Blue, Yellow};
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i <= 10; i++)
		{
			display->AddRenderable(new Card(
				display->renderer,
				{ 5+(i*105), 5+(j * 155), 0, 0},
				colors[j],
				i,
				true
			));
		}
	}
}
