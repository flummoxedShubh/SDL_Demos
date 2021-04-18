#include "game_object.hpp"

void GameObject::load(int x, int y, int width, int height, std::string textureID)
:m_x(x), m_y(y), m_w(width), m_h(height), m_textureID(textureID)
{
	m_current_frame = 1;
	m_current_row = 1;
}

void GameObject::draw(SDL_Renderer* renderer)
{
	
}