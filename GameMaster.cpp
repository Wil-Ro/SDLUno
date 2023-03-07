#include "GameMaster.h"

// is it bad it has this many values? its a constructor so surely it will end up taking alot
GameMaster::GameMaster(Display* display, BaseEventHandler* handler, Deck* playDeck, Deck* drawDeck, std::function<void(int)> winFunc)
{
	this->display = display;
	this->playDeck = playDeck;
	this->drawDeck = drawDeck;
	this->winFunc = winFunc;
	drawDeck->SetFuncOnEmpty([this](){OnEmptyDeck();});

	// unhard code this eventually
	Hand* playerHand = 0;
	characters.push_back(new PlayerCharacter(display, drawDeck, playDeck, &playerHand));
	characters.push_back(new Character(drawDeck, playDeck));

	// first player set up to have their turn
	characters[0]->StartTurn();

	handler->AddInteractable(playerHand);

	turnIndicator = new TurnIndicator(display, {display->w()/2, 20, 80, 40});
}

void GameMaster::TakeTurn()
{
	// Every character can take a turn in 2 ways: passively or actively
	// an active turn is done through the TakeTurn() method. This isnt a single call, this is called
	// every frame and the turn will be taken over a long period with many calls to this
	// a passive turn is taken at a different point in the code if turn == true 
	// turn is set to true in IncreaseTurn()

	// call turn, if it gets taken, move on to next one
	characters[currentTurn]->TakeTurn();

	if (characters[currentTurn]->GetHandSize() == 0)
	{
		winFunc(currentTurn);
	}

	if (characters[currentTurn]->turnTaken)
		IncreaseTurn();
}

void GameMaster::IncreaseTurn()
{
	int previousTurn = currentTurn;

	currentTurn++;

	currentTurn = currentTurn % characters.size();

	characters[previousTurn]->ResetTurn();
	characters[currentTurn]->StartTurn();

	turnIndicator->setTurn(currentTurn);
	// we could do this without previousTurn but this feels nicer to read?
}

void GameMaster::OnEmptyDeck()
{
	SDL_Log("REFILLING DRAW DECK");
	drawDeck->FillDeckFromDeck(playDeck, true, false);
	playDeck->PlayCard(drawDeck->DrawCard());

	if (drawDeck->GetDeckSize() == 0)
		SDL_LogWarn(0, "Deck refilled but left empty after refill");
}

// this will be called externally by the draw card button
void GameMaster::GivePlayerCard()
{
	// if its the players turn
	if (currentTurn == 0) 
	{
		characters[0]->ForceDrawCard();
	}
}

/*
we give the game master a function to be called publically by the draw button???
this would check the players turn and if it is theirs it would give them a card and end their turn
*/