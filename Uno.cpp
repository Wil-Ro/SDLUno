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
	//RunWinScreen(0);
}


void Uno::RunGame()
{
	display->ClearRenderables();

	BaseEventHandler handler;

	FPSCounter fpsCounter(display->renderer, 2);

	Deck drawDeck({0, 0, 100, 150});
	drawDeck.CenterTexture({ 0, 0, display->w(), display->h() });

	Deck playDeck({ 0, 0, 100, 150 });
	playDeck.CenterTexture({0, 0, display->w(), display->h()});

	drawDeck.ShiftLocation({-52 });
	playDeck.ShiftLocation({ 52 });

	display->AddRenderable(&drawDeck);
	display->AddRenderable(&playDeck);

	GameMaster gameMaster(display, &handler, &playDeck, &drawDeck, 4);
	gameMaster.SetWinFunc([this](int winner) {this->RunWinScreen(winner); });
	

	CharIndicatorContainer enemies(&gameMaster, display->renderer, { 0, 0, display->w(), display->h()/3});
	display->AddRenderable(&enemies);

	gameMaster.SetNewTurnFunc([&enemies](int character, int prevCharacter) {enemies.UpdateCharIndicators(character, prevCharacter);});

	Button drawButton({ 20, 300, 150, 150 }, [&gameMaster]() {gameMaster.GivePlayerCard();});
	drawButton.AddTexture(display->renderer, "textures/drawButton.png");
	display->AddRenderable(&drawButton);
	handler.AddInteractable(&drawButton);


	while (true)
	{
		display->PrepareRender();

		
		gameMaster.TakeTurn();
		gameMaster.IncreaseTurn();
		

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

void Uno::RunWinScreen(int winner)
{
	display->ClearRenderables();
	BaseEventHandler handler;

	std::string winTextContent = winner == 0 ? "You Win!" : "You Lost!";

	Text winText(display->renderer, winTextContent.c_str(), 80, {0, 0, 0, 0}, {255, 255, 255, 255});
	winText.CenterTexture({ 0, 0, display->w(), display->h() });
	display->AddRenderable(&winText);

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

// holy shit your code is awful, decks sizes are hardcoded rn
// fix that
// 100, 150

// you can click through a button to click the thing beneath it, add z-priotity on clicking

// I feel like this code needs cleaning up, once gamemaster is
// working, do that

/*
// get gamemaster working, skip ai for now, just get it
// taking a players turn, waiting a bit on ai and repeating


*/


/*
I've realised Im misusing inheritance completely but fuck you future me, look back on this and cringe
*/