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

	FPSCounter fpsCounter(display->renderer, 2);

	GameMaster gameMaster;

	

	Deck drawDeck({0, 0, 100, 150});
	drawDeck.CenterTexture({ 0, 0, display->w(), display->h() });
	drawDeck.FillDeck(display->renderer, false);

	Deck playDeck({ 0, 0, 100, 150 });
	playDeck.CenterTexture({0, 0, display->w(), display->h()});
	playDeck.PlayCard(drawDeck.DrawCard());

	drawDeck.ShiftLocation({-52 });
	playDeck.ShiftLocation({ 52 });

	PlayerHand testHand({30, display->h()-200, display->w()-30, 200}, &drawDeck, &playDeck);
	testHand.FillHand();

	Button drawButton({ 30, display->h() - 240, 100, 30 }, [&testHand](){testHand.DrawCard(); });
	drawButton.AddTexture(display->renderer, "textures/quitButton.png");

	display->AddRenderable(&drawDeck);
	display->AddRenderable(&playDeck);
	display->AddRenderable(&testHand);
	display->AddRenderable(&drawButton);

	handler.AddInteractable(&testHand);
	handler.AddInteractable(&drawButton);


	while (true)
	{
		display->PrepareRender();

		handler.Handle();

		display->RenderAll();
		fpsCounter.IncreaseFrameCount();
		fpsCounter.DrawSelf(display->renderer);
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


// get gamemaster working, skip ai for now, just get it
// taking a players turn, waiting a bit on ai and repeating

// holy shit your code is awful, decks sizes arnt hardcoded rn
// fix that
// 100, 150

// drawcard crashes when deck is empty as it return nullpointer

// you can click through a button to click the thing beneath it, add z-priotity on clicking
