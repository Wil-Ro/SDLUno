#include "GameMaster.h"

// is it bad it has this many values? its a constructor so surely it will end up taking alot
GameMaster::GameMaster(Display* display, BaseEventHandler* handler, Deck* playDeck, Deck* drawDeck, int numOfCharacters)
{
	this->display = display;
	this->playDeck = playDeck;
	this->drawDeck = drawDeck;
	drawDeck->SetFuncOnEmpty([this](){OnEmptyDeck();});
	playDeck->SetFuncProcessCard([this](Card* card){ProcessCard(card);});

	drawDeck->FillDeck(display->renderer, false);
	playDeck->PlayCard(drawDeck->DrawCard());

	// unhard code this eventually
	Hand* playerHand = 0;
	characters.push_back(new PlayerCharacter(display, drawDeck, playDeck, &playerHand));
	for (int i = 0; i < numOfCharacters; i++)
	{
		characters.push_back(new Character(drawDeck, playDeck));
	}

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
}


void GameMaster::IncreaseTurn()
{
	if (characters[currentTurn]->turnTaken)
	{
		int previousTurn = currentTurn;

		currentTurn += turnChange;

		currentTurn = currentTurn % characters.size();

		characters[previousTurn]->ResetTurn();
		characters[currentTurn]->StartTurn();

		turnIndicator->setTurn(currentTurn);
		newTurnFunc(currentTurn, previousTurn);
	}
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


int GameMaster::GetTurn()
{
	return currentTurn;
}

int GameMaster::GetNumberOfPlayers()
{
	return characters.size();
}

int GameMaster::GetPlayerHandSize(int player)
{
	return characters[player]->GetHandSize();
}

void GameMaster::SetNewTurnFunc(std::function<void(int, int)> func)
{
	newTurnFunc = func;
}
void GameMaster::SetWinFunc(std::function<void(int)> func)
{
	winFunc = func;
}

void GameMaster::ChangeTurnOrder()
{
	SDL_Log("OFDHDFGD");
	if (turnChange == 1)
	{
		turnChange = -1;
	}
	else
	{
		turnChange = 1;
	}
}

void GameMaster::ProcessCard(Card* card)
{
	switch (card->GetValue())
	{
	case PLUS_TWO_CARD:
		SDL_Log("Player played plus two card");
		break;
	case PLUS_FOUR_CARD:
		SDL_Log("Player played plus four card");
		break;
	case REVERSE_CARD:
		ChangeTurnOrder();
		break;
	case WILD_CARD_CARD:
		SDL_Log("Player played wild card");
		break;
	} //TODO THIS, also make wildcards render
}

