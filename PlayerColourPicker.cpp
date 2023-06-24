#include "PlayerColourPicker.h"

SDL_Color PlayerColorPicker::Run()
{
	Display* display = new Display(190, 190, "Pick new colour");
	BaseEventHandler handler;

	Button* redButton = new Button({ 10, 10, 80, 80 }, [this]() {SetPickedColor(Red);});
	redButton->AddTexture(display->renderer, "textures/red.png");
	display->AddRenderable(redButton);
	handler.AddInteractable(redButton);

	Button* greenButton = new Button({ 100, 10, 80, 80 }, [this]() {SetPickedColor(Green); });
	greenButton->AddTexture(display->renderer, "textures/green.png");
	display->AddRenderable(greenButton);
	handler.AddInteractable(greenButton);

	Button* blueButton = new Button({ 10, 100, 80, 80 }, [this]() {SetPickedColor(Blue); });
	blueButton->AddTexture(display->renderer, "textures/blue.png");
	display->AddRenderable(blueButton);
	handler.AddInteractable(blueButton);

	Button* yellowButton = new Button({ 100, 100, 80, 80 }, [this]() {SetPickedColor(Yellow); });
	yellowButton->AddTexture(display->renderer, "textures/yellow.png");
	display->AddRenderable(yellowButton);
	handler.AddInteractable(yellowButton);

	while (chosenColor == NULL)
	{
		display->PrepareRender();
		handler.Handle();

		display->RenderAll();

		display->ProcessRender();
		SDL_Delay(10);
	}

	delete display;

	return *chosenColor;
}

void PlayerColorPicker::SetPickedColor(SDL_Color color)
{
	chosenColor = &color;
}
