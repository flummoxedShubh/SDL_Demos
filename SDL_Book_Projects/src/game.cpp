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

	TheTextureManager()::Instance->load("res/gfx/gabe-idle-run.png", "gabe", m_renderer);
	m_current_frame = 0;

	m_running = true;
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	TheTextureManager()::Instance->draw("gabe", 0, 0, 24, 24, m_renderer);
	TheTextureManager()::Instance->drawFrame("gabe", 100, 100, 24, 24, 1, m_current_frame, m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Game::update()
{
	m_current_frame = int(((SDL_GetTicks() / 100) % 7)); 
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