#include "FileLoader.h"
#include <iostream>
#include "Game.h"

using namespace Scroller;

SDL_Texture* FileLoader::loadTexture(std::string fileName)
{

		std::string path = "assets/" + fileName;
		SDL_Surface* temp = IMG_Load(path.c_str());

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, temp);

		if (texture == NULL)
		{
			std::cout << "Failed to load texture: " << fileName << " :E: " << IMG_GetError() << "\n";

			temp = IMG_Load("assets/default.png");
			texture = SDL_CreateTextureFromSurface(Game::renderer, temp);

			if (!texture) std::cout << "Failed to load default.png\n";
			else if (texture) std::cout << "Loaded default.png\n";
		}
		SDL_FreeSurface(temp);

		return texture;
}