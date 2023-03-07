#pragma once
#include "Hand.h"
#include "PlayerHand.h"

class Character
{
protected:
	Hand* hand;
	bool turn = false;
	
	


public:
	virtual void TakeTurn();
	virtual void StartTurn();
	virtual void EndTurn();

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