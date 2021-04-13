#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h):
window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if(window == NULL){
		std::cout << "Window Init failed, ERROR::" << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanup()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_texture)
{
	SDL_RenderCopy(renderer, p_texture, NULL, NULL);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_path)
{
	SDL_Texture* temp_texture = NULL;
	temp_texture = IMG_LoadTexture(renderer, p_path);
	if(temp_texture == NULL){
		std::cout << "Texture couldn't be loaded, ERROR::" << IMG_GetError() << std::endl;
	}

	return temp_texture;
}