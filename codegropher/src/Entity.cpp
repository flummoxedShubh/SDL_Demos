#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
:pos_x(p_x), pos_y(p_y), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}
