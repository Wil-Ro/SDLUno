#include "Display.h"
#include "Renderable.h" // including this here to avoid circular dependancies


    Display::Display(int w, int h, const char* windowTitle, SDL_Color backgroundColor)
	{
		title = windowTitle;
		this->backgroundColor = backgroundColor;

		w_ = w;
		h_ = h;


		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
		if (!window)
			SDL_LogError(0, "failed to create window");

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!renderer)
			SDL_LogError(0, "failed to create renderer");
	}

	
	void Display::init()
	{
		SDL_Init(SDL_INIT_VIDEO < 0);
		IMG_Init(IMG_INIT_PNG);
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

		TTF_Init();
	}

	void Display::exit()
	{
		TTF_Quit();
	}

	void Display::RenderAll()
	{
		for (Renderable* item : renderList)
		{
			item->RenderCall(renderer);
		}
	}

	void Display::AddRenderable(Renderable* toAdd)
	{
		/*
		create an iterator to go through the list
		then when it finds the element with a zOrder
		bigger than toAdd, move that iterator back one
		and use insert() to place the item there
		*/
		if (renderList.size() <= 0)
			renderList.push_front(toAdd);

		auto it = renderList.begin();
		for (int i = 0; i < renderList.size(); i++, it++)
		{
			if (toAdd->GetZOrder() < (*it)->GetZOrder())
			{
				renderList.insert(it, toAdd);
				break;
			}
		}
	}

	void Display::ProcessRender()
	{
		SDL_RenderPresent(renderer);
	}

	void Display::PrepareRender()
	{
		SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
		SDL_RenderClear(renderer);
	}

	void Display::ClearRenderables()
	{
		renderList.clear();
	}

	void Display::RecalculateZOrder(Renderable* toCheck)
	{
		// remove it from list, add it again, when adding it will
		// place it in the new correct order
		renderList.remove(toCheck);
		AddRenderable(toCheck);
	}


	