#include "Deck.h"

Deck::Deck(SDL_Rect rect)
{
	location = rect;
}

Card* Deck::DrawCard(bool flipCard)
{
	if (deck.size() <= 0)
		return 0;
	Card* tempCard = deck.top();
	deck.pop();

	if (flipCard)
		tempCard->FlipCard();

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
void Deck::FillDeck(SDL_Renderer* renderer, bool facingPlayer)
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
				facingPlayer
			));
		}
	}
	ShuffleDeck();
}

int Deck::GetDeckSize()
{
	return deck.size();
}

void Deck::FillDeckFromDeck(Deck* sourceDeck, bool shuffle, bool facingPlayer)
{
	for (int i = 0; i < sourceDeck->GetDeckSize(); i++)
	{
		deck.push(sourceDeck->DrawCard());
		if (facingPlayer)
			deck.top()->facingPlayer = true;
	}

	if (shuffle)
		ShuffleDeck();
}


void Deck::ShuffleDeck()
{
	// copy stack into vector
	// this can be done more efficiently but my understanding
	// of container adapters is severely lacking
	std::vector<Card*> buffer;
	// deck size changes when we pop so this stores 
	// the original value
	int deckSize = deck.size();
	for (int i = 0; i < deckSize; i++)
	{
		buffer.push_back(deck.top());
		deck.pop();
	}
	
	// shuffle vector
	std::random_device randomDevice;
	std::mt19937 gen(randomDevice());
	std::shuffle(buffer.begin(), buffer.end(), gen);

	// copy back into stack
	for (Card* item : buffer)
		deck.push(item);
	
}
