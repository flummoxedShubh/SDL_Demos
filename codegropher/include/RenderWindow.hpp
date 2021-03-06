#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h); //p_* for parameters
	
	void cleanup();
	void clear();
	void render(Entity& p_entity);
	void display();

	SDL_Texture* loadTexture(const char* p_path);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};