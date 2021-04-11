#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h); //p_* for parameters
	void cleanup();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};