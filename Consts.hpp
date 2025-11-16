#pragma once

constexpr char WINDOW_NAME[] = "MySDLGameDemo";
constexpr int WINDOW_DEFAULT_HEIGHT = 1080;
constexpr int WINDOW_DEFAULT_WIDTH = 1980;
constexpr int WINDOW_SCALE = 100;

constexpr char MAP_FILE[] = "Map.txt";

constexpr int OFFSET_X = 100;
constexpr int OFFSET_Y = 100;
constexpr int SCALE = 100;

constexpr int WALL_WIDTH = WINDOW_DEFAULT_WIDTH / WINDOW_SCALE;
constexpr int WALL_HEIGHT = WALL_WIDTH;

constexpr int PLAYER_START_X = 0;
constexpr int PLAYER_START_Y = 0;

constexpr int PLAYER_SIZE = WALL_HEIGHT / 2;

constexpr int MOVE_UP = 1;
constexpr int MOVE_RIGHT = 2;
constexpr int MOVE_DOWN = -1;
constexpr int MOVE_LEFT = -2;

constexpr int NPC_START_X = 1;
constexpr int NPC_START_Y = 1;
constexpr double NPC_SPEED = 15;