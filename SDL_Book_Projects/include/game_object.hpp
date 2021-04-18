#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "texture_manager.hpp"

class GameObject
{
public:
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* renderer);
	void update();
	void clean();

protected:
	std::string m_textureID;

	int m_current_frame;
	int m_current_row;

	int m_x;
	int m_y;

	int m_w;
	int m_h;
};