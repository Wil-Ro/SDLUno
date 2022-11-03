#pragma once
#include "Renderable.h"
#include "Card.h"

#include <stack>
#include <algorithm>
#include <vector>
#include <random>

class Deck :public Renderable
{
public:
	Deck(SDL_Rect rect);

	Card* DrawCard(bool flipCard = true);
	void PlayCard(Card* card, bool flipCard = false);
	void FillDeck(SDL_Renderer* renderer, bool facingPlayer = true);
	void FillDeckFromDeck(Deck* sourceDeck, bool shuffle = true, bool facingPlayer = true);
	void ShuffleDeck();

	int GetDeckSize();

	void RenderCall(SDL_Renderer* renderer);
private:
	std::stack<Card*> deck;

};