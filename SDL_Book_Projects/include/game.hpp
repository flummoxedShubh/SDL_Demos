#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "texture_manager.hpp" 

class Game
{
public:
	Game() {}
	~Game() {}

	void init(const char* title, int pos_x, int pos_y, int w, int h, int flags);

	void render();
	void update();
	void handle_events();
	void clean();

	bool is_running() {return m_running;}

private:
	bool m_running;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	int m_current_frame;
	TextureManager m_texture_manager;
};