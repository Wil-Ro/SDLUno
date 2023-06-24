#pragma once
#include <SDL2/SDL.h>

namespace RectMaths
{
	SDL_Rect getRectCenter(SDL_Rect rect)
	{
		SDL_Rect tempRect
		{
			rect.x + (rect.w / 2),
			rect.y + (rect.h / 2),
			0,
			0,
		};
		return tempRect;
	}

	SDL_Rect getRectCenterWidth(SDL_Rect rect, SDL_Rect widthRect)
	{
		SDL_Rect tempRect
		{
			(rect.x + (rect.w / 2)) - (widthRect.w / 2),
			(rect.y + (rect.h / 2)) - (widthRect.h / 2),
			widthRect.w,
			widthRect.h,
		};
		return tempRect;
	}

}