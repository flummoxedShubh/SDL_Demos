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

void RenderWindow::render(Entity& p_entity)
{
	SDL_Rect src, dst;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	dst.x = p_entity.getX();
	dst.y = p_entity.getY();
	dst.w = p_entity.getCurrentFrame().w * 2;
	dst.h = p_entity.getCurrentFrame().h * 2;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
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