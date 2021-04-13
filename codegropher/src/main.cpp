#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char* args[])
{

	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL Init Failed, ERROR::" << SDL_GetError() << std::endl;

	if(!IMG_Init(IMG_INIT_PNG))
		std::cout << "SDL Image Init Failed" << IMG_GetError() << std::endl;

	RenderWindow window("SDL Demo v1.0", 1024, 768);

	SDL_Texture* grassTexture = window.loadTexture("res/grass.png");

	bool gameRunning = true;

	SDL_Event event;

	while(gameRunning)
	{
		//Get our control and events
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		window.render(grassTexture);
		window.display();
	}

	window.cleanup();
	SDL_Quit();

	return 0;
}