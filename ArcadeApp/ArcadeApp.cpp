// ArcadeApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 2;

int main(int argc, const char * argv[])
{
	Screen theScreen;

	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, 2);
	Line2D line = { Vec2D(0, 0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT) };

	theScreen.Draw(line, Color::White());
	// theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());
	theScreen.SwapScreens();

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

	return 0;
}

