#pragma once
#include "BaseEventHandler.h"
#include "Display.h"
#include "Deck.h"
#include "Character.h"
#include "PlayerCharacter.h"
#include "TurnIndicator.h"

#include <vector>

/*
GameMaster
This class holds all the players and controls their turn order, players hold their hands and calls
their render function.
*/

class GameMaster
{
public:
	GameMaster(Display* display, BaseEventHandler* handler, Deck* playDeck, Deck* drawDeck, int numOfPlayers);
	void TakeTurn();
	void IncreaseTurn();
	void GivePlayerCard();

	int GetTurn();
	int GetNumberOfPlayers();

	// possibly replace these with a GetPlayerData and PlayerDate struct
	int GetPlayerHandSize(int player);

	void SetNewTurnFunc(std::function<void(int, int)> func);
	void SetWinFunc(std::function<void(int)> func);


	void ProcessCard(Card* card);
private:
	void ChangeTurnOrder();
	void ForceCards(int numOfCards);
	void ChangeColor();

	void OnEmptyDeck();

	int currentTurn = 0;
	int turnChange = 1;
	std::vector<Character*> characters;

	std::function<void(int)> winFunc;
	std::function<void(int, int)> newTurnFunc;

	Deck* playDeck;
	Deck* drawDeck;

	Display* display;

	TurnIndicator* turnIndicator;
	
};

