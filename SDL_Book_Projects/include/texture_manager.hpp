#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <map>

class TextureManager
{
public:
	TextureManager() {}
	~TextureManager() {}

	bool load(std::string filename, std::string id, SDL_Renderer* renderer);
	void draw(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int w, int h, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_TextureMap;
};