#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "game.hpp"
#include "texture_manager.hpp"

int main(int argc, char* args[])
{

	Game* game = new Game();
	game->init("v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);

	while(game->is_running())
	{
		game->handle_events();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}