#include "TurnIndicator.h"

TurnIndicator::TurnIndicator(Display* display, SDL_Rect location)
{
	this->location = location;
	text = new Text(display->renderer, "Turn: you", 40, Renderable::GetUncenteredRect(location), {255, 255, 255, 255});

	this->display = display;

	display->AddRenderable(text);
}

void TurnIndicator::setTurn(int turn)
{
	this->turn = turn;
	if (turn == 0)
	{
		this->text->ChangeText(display->renderer, "Turn: you");
		this->text->SetLocation(Renderable::GetUncenteredRect({ location.x, location.y, text->GetLocation().w, text->GetLocation().h }));
	}
	else
	{
		this->text->ChangeText(display->renderer, ("Turn: " + std::to_string(turn)).c_str());
		this->text->SetLocation(Renderable::GetUncenteredRect({ location.x, location.y, text->GetLocation().w, text->GetLocation().h }));
	}
}
