#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* args[])
{

	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL Init Failed, ERROR::" << SDL_GetError() << std::endl;

	if(!IMG_Init(IMG_INIT_PNG))
		std::cout << "SDL Image Init Failed" << IMG_GetError() << std::endl;

	RenderWindow window("SDL Demo v1.0", 1024, 768);

	SDL_Texture* grassTexture = window.loadTexture("res/grass.png");
	SDL_Texture* devaTexture = window.loadTexture("res/deva.png");

/*
	Entity entity[4] = {
		Entity(400, 100, grassTexture),
		Entity(0, 100, grassTexture),
		Entity(64, 100, grassTexture),
		Entity(200, 600, grassTexture)
	};
*/
	std::vector<Entity> entities = {
		Entity(400, 100, grassTexture),
		Entity(0, 100, grassTexture),
		Entity(64, 100, grassTexture),
		Entity(200, 600, grassTexture),
		Entity(300,300, devaTexture)
	};

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
		for(Entity& e : entities)
		{
			window.render(e);
		}
		window.display();
	}

	window.cleanup();
	SDL_Quit();

	return 0;
}