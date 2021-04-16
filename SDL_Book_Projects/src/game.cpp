#include "game.hpp"

void Game::init(const char* title, int pos_x, int pos_y, int w, int h, int flags)
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL INIT ERROR::" << SDL_GetError() << std::endl;

	if(!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG INIT ERROR::" << IMG_GetError() << std::endl;

	m_window = SDL_CreateWindow(title, pos_x, pos_y, w, h, flags);
	if(m_window == NULL)
		std::cout << "WINDOW CREATION FAILED, ERROR::" << SDL_GetError() << std::endl;

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if(m_renderer == NULL)
		std::cout << "RENDERER CREATION FAILED, ERROR::" << SDL_GetError() << std::endl;

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);


	//-----------
	temp_tex = IMG_LoadTexture(m_renderer, "res/gfx/gabe-idle-run.png");
	if(temp_tex == NULL)
		std::cout << "TEXTURE LOAD ERROR::" << SDL_GetError() << std::endl;


	m_running = true;
}

void Game::render()
{
	SDL_Rect src, dst;
	src.x = 0;
	src.y = 0;
	src.w = 24;
	src. h = 24;

	dst.x = 0;
	dst.y = 0;
	dst.w = src.w * 2;
	dst.h = src.h * 2;

	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, temp_tex, &src, &dst);
	SDL_RenderPresent(m_renderer);
}

void Game::update()
{

}

void Game::handle_events()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT: 
				m_running = false;
				break;

			default:
				break;
		}
	}
}

void Game::clean()
{	
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}