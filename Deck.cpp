#include "Deck.h"

Deck::Deck(SDL_Rect rect)
{
	location = rect;
}

Card* Deck::DrawCard()
{
	if (deck.size() <= 0)
		return 0;
	Card* tempCard = deck.top();
	deck.pop();
	return tempCard;
}

void Deck::PlayCard(Card* card, bool flipCard)
{
	if (flipCard)
		card->FlipCard();
	deck.push(card);
}

// this is where we are rn
void Deck::RenderCall(SDL_Renderer* renderer)
{
	if (deck.size() <= 0)
		return;

	deck.top()->SetLocation(location);
	deck.top()->RenderCall(renderer);
}

// this will need redoing at somepoint, it doesnt give the correct cards rn
void Deck::FillDeck(SDL_Renderer* renderer)
{
	SDL_Color colors[4] = { Red, Green, Blue, Yellow };
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i <= 10; i++)
		{
			PlayCard(new Card(
				renderer,
				{ 5 + (i * 105), 5 + (j * 155), 0, 0 },
				colors[j],
				i,
				true
			));
		}
	}
}