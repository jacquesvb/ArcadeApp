// ArcadeApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Color.h"
#include "ScreenBuffer.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

int main(int argc, const char * argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Error SDL_Init Failed" << std::endl;
		return 1;
	}

	SDL_Window* optrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (optrWindow == nullptr)
	{
		std::cout << "Could not create window, got error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Surface* noptrWindowSurface = SDL_GetWindowSurface(optrWindow);

	SDL_PixelFormat* pixelFormat = noptrWindowSurface->format;

	Color::InitColorFormat(pixelFormat);

	ScreenBuffer screenBuffer;

	screenBuffer.Init(pixelFormat->format, noptrWindowSurface->w, noptrWindowSurface->h);

	Color color = Color(255, 0, 0, 255);
	// Color rd = Color::Red;

	screenBuffer.SetPixel(color, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	SDL_BlitSurface(screenBuffer.GetSurface(), nullptr, noptrWindowSurface, nullptr);

	SDL_UpdateWindowSurface(optrWindow);

	SDL_Event sdlEvent;
	bool running = true;

	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}
	}

	SDL_DestroyWindow(optrWindow);
	SDL_Quit();

	return 0;
}

