#include "PlayerHand.h"

PlayerHand::PlayerHand(SDL_Rect rect, Deck* drawDeck, Deck* playDeck)
{
	location = rect;
	this->drawDeck = drawDeck;
	this->playDeck = playDeck;
}

void PlayerHand::PlayCard(Card* card)
{
	card->interactable = false;
	Hand::PlayCard(card);
}

void PlayerHand::FillHand()
{
	for (int i = 0; i <= 7; i++)
	{
		DrawCard();
	}
}

void PlayerHand::DrawCard()
{
	Hand::DrawCard();
	hand.back()->interactable = true;
}

void PlayerHand::MouseDown(MousePos mouse)
{
	for (Card* card : hand)
	{
		if (card->CheckMouseOver(mouse))
		{
			PlayCard(card);
			break;
		}
	}
}

void PlayerHand::RenderCall(SDL_Renderer* renderer)
{
	// set locations
	// render all

	// x = hand.x+i*(width/number of cards)

	for (int i = 0; i < hand.size(); i++)
	{
		Card* card = hand[i];
		card->SetLocation({location.x + i * (location.w/(int)hand.size()), location.y, 100, 150});
		card->RenderCall(renderer);
	}
	
	return;
}
