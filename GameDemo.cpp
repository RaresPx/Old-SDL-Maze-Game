#include <iostream>
#include <vector>
#include <format>

#include "GameDemo.hpp"




GameDemo::GameDemo()
	: isRunning(true),
	m_Window(nullptr),
	m_Renderer(nullptr),
	m_Player(PLAYER_START_X,PLAYER_START_Y,m_GameMap),
	m_NPC(NPC_START_X,NPC_START_Y,m_GameMap)
{

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init error:"<<SDL_GetError()<<std::endl;
		return;
	}

	m_Window = SDL_CreateWindow(WINDOW_NAME, WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT, SDL_WINDOW_RESIZABLE);

	if (!m_Window) {
		std::cerr << "SDL_CreateWindow error:" << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, NULL);
	if (m_Renderer == nullptr) {
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
		return;
	}
}

void GameDemo::Run() {


	if (!m_GameMap.getFromFile(MAP_FILE)) {
		std::cerr << "Error getting Map from file : " << MAP_FILE << std::endl;
	}
	int n = (int)m_GameMap.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m_GameMap.isWall(i * n + j))
				m_Entities.push_back(std::make_unique<Wall>( i*WALL_WIDTH + OFFSET_X,
																j*WALL_HEIGHT+ OFFSET_Y,
																WALL_WIDTH, 
																WALL_HEIGHT)
																);
		}
	}
	
	//m_Entities.push_back(std::make_unique<Player>(PLAYER_START_X, PLAYER_START_Y));
	Uint32 lastTime = SDL_GetTicks();
	double deltaTime = 0.0;
	Uint32 currentTime;
	while (isRunning) {
		eventHandler();
		//m_World.updateWorld();
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - lastTime) / 1000. ;
		lastTime = currentTime;
		m_NPC.stepSolver(deltaTime,NPC_SPEED);
		render();
		SDL_Delay(16);
	}

}

void GameDemo::eventHandler() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {

			case SDL_EVENT_QUIT: 
				isRunning = false;
				SDL_DestroyWindow(m_Window);
				SDL_DestroyRenderer(m_Renderer);
				SDL_Quit();
				break;
			case SDL_EVENT_KEY_DOWN:
				if (event.key.key == SDLK_W) {
					m_Player.updatePosition(MOVE_UP);
				}
				else if (event.key.key == SDLK_A) {
					m_Player.updatePosition(MOVE_LEFT);
				}
				else if (event.key.key == SDLK_S) {
					m_Player.updatePosition(MOVE_DOWN);
				}
				else if (event.key.key == SDLK_D) {
					m_Player.updatePosition(MOVE_RIGHT);
				}
				else if(event.key.key == SDLK_R) {
					m_NPC.resetClock();
					m_NPC.setMapCoords(NPC_START_X, NPC_START_Y);
					m_NPC.updateGlobalPosition(NPC_START_X, NPC_START_Y);
				}else if (event.key.key == SDLK_ESCAPE) {
					isRunning = false;
					SDL_DestroyRenderer(m_Renderer);
					SDL_DestroyWindow(m_Window);
					SDL_Quit();
				}
				break;
			default:
				break;
		}
	}
}

void GameDemo::render() {

	
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255); // Black background
	SDL_RenderClear(m_Renderer);
	
	m_Player.render(m_Renderer);
	m_NPC.render(m_Renderer);
	for (auto& entity : m_Entities) {
		entity->render(m_Renderer);
	}

	SDL_RenderPresent(m_Renderer);

	
}