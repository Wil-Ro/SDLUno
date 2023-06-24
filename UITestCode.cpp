#include "Display.h"
#include "BaseEventHandler.h"
#include "Slider.h"
#include "Text.h"
#include "FPSCounter.h"

#include <string>
#include <iostream>


void buttonTest()
{
	SDL_Log("button works");
}

int UiTest()
{
	FPSCounter fpsCounter(1);

	Display::init();
	Display display(200, 200, "testWindow", {0, 255, 0, 255});

	BaseEventHandler handler;

	SDL_Rect buttonRect = { 10, 30, 100, 50 };
	Button testButton(buttonRect, buttonTest);
	testButton.AddTexture(display.renderer, "textures/quitButton.png");
	handler.AddInteractable(&testButton);
	display.AddRenderable(&testButton);


	SDL_Rect sliderRect = { 10, 90, 180, 0 };
	Slider testSlider(sliderRect);
	testSlider.AddTexture(display.renderer, "textures/sliderNode.png");
	handler.AddInteractable(&testSlider);
	display.AddRenderable(&testSlider);

	SDL_Rect textRect = { 10, 95, 0, 0 };
	Text testText(display.renderer, "", 15, textRect);
	display.AddRenderable(&testText);

	SDL_Rect textRect2 = { 5, 5, 0, 0 };
	Text testText2(display.renderer, "This is test text", 15, textRect2);
	display.AddRenderable(&testText2);

	SDL_Rect fpsTextRect = { 145, 10, 0, 0 };
	Text fpsText(display.renderer, "0", 15, fpsTextRect);
	display.AddRenderable(&fpsText);



	while (true)
	{
		display.PrepareRender();

		testText.ChangeText(display.renderer, std::to_string(testSlider.GetValue()).c_str());
		char fpsLabel[15] = "fps: ";
		strcat(fpsLabel, std::to_string(fpsCounter.GetFrameCount()).c_str());// if this doesnt work, use strcat_s() instead
		fpsText.ChangeText(display.renderer, fpsLabel);

		handler.Handle();
		display.RenderAll();
		display.ProcessRender();

		fpsCounter.IncreaseFrameCount();
		SDL_Delay(10);
	}

	Display::exit();
	return 0;
}