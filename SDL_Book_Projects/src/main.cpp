#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL INIT ERROR::" << SDL_GetError() << std::endl;

	if(!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG INIT ERROR::" << IMG_GetError() << std::endl;

	SDL_Window* window = SDL_CreateWindow("SDL_Demo v1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN);
	if(window == NULL)
		std::cout << "WINDOW CREATION FAILED, ERROR::" << SDL_GetError() << std::endl;

	bool isRunning = true;

	SDL_Event event;

	while(isRunning)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				isRunning = false;
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}