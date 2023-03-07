#include "GameMaster.h"

GameMaster::GameMaster(Display* display, BaseEventHandler* handler, Deck* playDeck, Deck* drawDeck)
{
	this->display = display;
	this->playDeck = playDeck;
	this->drawDeck = drawDeck;
	drawDeck->SetFuncOnEmpty([this](){OnEmptyDeck();});

	// unhard code this eventually
	Hand* playerHand = 0;
	characters.push_back(new PlayerCharacter(display, drawDeck, playDeck, &playerHand));
	characters.push_back(new Character(drawDeck, playDeck));

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
	if (characters[currentTurn]->turnTaken)
		IncreaseTurn();
}

void GameMaster::IncreaseTurn()
{
	int previousTurn = currentTurn;

	currentTurn++;
	if (currentTurn > characters.size() - 1)
		currentTurn = 0;

	characters[previousTurn]->EndTurn();
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

void GameMaster::GivePlayerCard()
{
	SDL_Log("DGADFGJADFHADFHAR FUCKKKKSGKSD");
}

/*
we give the game master a function to be called publically by the draw button???
this would check the players turn and if it is theirs it would give them a card and end their turn
*/