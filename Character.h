#pragma once
#include "Hand.h"
#include "PlayerHand.h"

class Character
{
private:
	Uint32 waitCache = 0;
	Uint32 waitTime = 1000;

	void PlayCard();

protected:
	Hand* hand;
	bool turn = false;


public:
	virtual void TakeTurn();
	virtual void StartTurn();
	virtual void ResetTurn();
	virtual SDL_Color PickNewColour();

	virtual void ForceDrawCard(int numOfCards = 1);

	virtual int GetHandSize();

	Character(Deck* drawDeck, Deck* playDeck);
	Character();
	~Character();

	bool turnTaken = false;
};

/**
We need a StartTurn function that is called once when our turn starts,
then we also have the take turn function but I dont know if this will ever
actually be needed, its a bit like process(), its probably worth keeping though.
*/