#include "Deck.h"

Deck::Deck(SDL_Rect rect)
{
	location = rect;
}

Deck::Deck(SDL_Rect rect, std::function<void()> onEmpty, std::function<void(Card* card)> processCard)
{
	location = rect;
	this->funcOnEmpty = onEmpty;
	this->funcProcessCard = processCard;
}

Card* Deck::DrawCard(bool facingPlayer)
{
	if (deck.size() <= 0)
		funcOnEmpty();
	Card* tempCard = deck.top();
	deck.pop();

	tempCard->facingPlayer = facingPlayer;

	return tempCard;
}

void Deck::PlayCard(Card* card, bool facingPlayer)
{
	card->facingPlayer = facingPlayer;
	deck.push(card);

	// any card above 9 is a special card, GameMaster deals with these
	//TODO make sure card effects done trigger when deck is first filled using this method
	if (funcProcessCard != NULL &&  card->GetValue() > 9)
		funcProcessCard(card);
}

bool Deck::CanTakeCard(Card* card)
{
	return deck.top()->HasLinkWith(card);
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
		for (int i = 0; i <= 12; i++)
		{
			PlayCard(new Card(
				renderer,
				{ 5 + (i * 105), 5 + (j * 155), 0, 0 },
				colors[j],
				i+1,
				facingPlayer
			), facingPlayer);
		}
	}
	ShuffleDeck();
}

int Deck::GetDeckSize()
{
	return deck.size();
}

void Deck::SetFuncOnEmpty(std::function<void()> onEmpty)
{
	this->funcOnEmpty = onEmpty;
}

void Deck::SetFuncProcessCard(std::function<void(Card* card)> processCard)
{
	this->funcProcessCard = processCard;
}

void Deck::FillDeckFromDeck(Deck* sourceDeck, bool shuffle, bool facingPlayer)
{
	for (int i = 0; i < sourceDeck->GetDeckSize(); i++)
	{
		deck.push(sourceDeck->DrawCard());
		deck.top()->facingPlayer = facingPlayer;
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
