#include "texture_manager.hpp"

bool TextureManager::load(std::string filename, std::string id, SDL_Renderer* renderer)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, filename.c_str());
	if(texture == NULL){
		std::cout << "IMG LOADING ERRORR::" << IMG_GetError() << std::endl;
		return false;
	}

	//Adding texture to list
	m_TextureMap[id] = texture;
	return true;
}

void TextureManager::draw(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect src, dst;
	src.x = 0;
	src.y = 0;
	src.w = w;
	src.h = h;

	dst.x = x;
	dst.y = y;
	dst.w = src.w * 2;
	dst.h = src.h * 2;

	SDL_RenderCopyEx(renderer, m_TextureMap[id], &src, &dst, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int w, int h, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect src, dst;
	src.x = w * current_frame;
	src.y = h * (current_row - 1); //Row starting from 1,2,3...n
	src.w = w;
	src.h = h;

	dst.x = x;
	dst.y = y;
	dst.w = src.w * 2;
	dst.h = src.h * 2;

	SDL_RenderCopyEx(renderer, m_TextureMap[id], &src, &dst, 0, 0, flip);
}