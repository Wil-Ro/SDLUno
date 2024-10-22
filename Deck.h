#pragma once
#include "Renderable.h"
#include "Card.h"

#include <stack>
#include <algorithm>
#include <vector>
#include <random>
#include <functional>

class Deck :public Renderable
{
public:
	Deck(SDL_Rect rect);
	Deck(SDL_Rect rect, std::function<void()> onEmpty, std::function<void(Card* card)> processCard);


	Card* DrawCard(bool facingPlayer = true);
	void PlayCard(Card* card, bool facingPlayer = true);
	void PlayCardWithoutEffect(Card* card, bool facingPlayer = true);
	bool CanTakeCard(Card* card);


	Card* PeekTopCard();

	void FillDeck(SDL_Renderer* renderer, bool facingPlayer = true);
	void FillDeckFromDeck(Deck* sourceDeck, bool shuffle = true, bool facingPlayer = true);
	void ShuffleDeck();

	int GetDeckSize();
	void SetFuncOnEmpty(std::function<void()> onEmpty);
	void SetFuncProcessCard(std::function<void(Card* card)> processCard);

	void RenderCall(SDL_Renderer* renderer);
private:
	std::stack<Card*> deck;
	std::function<void()> funcOnEmpty;
	std::function<void(Card* card)> funcProcessCard;

};