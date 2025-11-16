#pragma once

#include <vector>
#include <memory>

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

#include "Consts.hpp"

#include "Map.hpp"
//#include "../GameEngine/World.hpp"
#include "Entity.hpp"
#include "Wall.hpp"
#include "Player.hpp"
#include "NPC.hpp"


class GameDemo {
public:
	GameDemo();
	void Run();
	void eventHandler();
	void render();

private:
	bool isRunning;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	//World m_World;
	Map m_GameMap;
	Player m_Player;
	NPC m_NPC;
	std::vector<std::unique_ptr<Entity>> m_Entities;
	
};