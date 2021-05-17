#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include "MainMenu.h"
#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GameObject.h>

using namespace std;
using namespace sf;
using namespace glm;

enum class GameState
{
	Menu,
	Game,
	EndScreen
};

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
	void checkCollision();
	void initSound();
private:
	static const int MAX_OBSTACLES = 10;
	static const int MAX_GOALLENGTH = 30;
	float offsetPosX[MAX_OBSTACLES];
	float offsetPosZ[MAX_OBSTACLES];
	float moveX;
	float moveY;
	float goalMoving = 0;
	bool isAlive = true;
	bool moving = false;
	int gameLength = 0;
	int score = 0;
	bool extraScore = false;
	static const int MAX_GAMELENGTH = 250;
	string hud;
	Text text;
	GameState currentState = GameState::Menu;
	GameObject* game_object[3];
	RenderWindow window;
	Clock clock;
	Time time;
	bool animate = false;
	vec3 animation = vec3(0.0f);
	float rotation = 0.0f;
	bool isRunning = false;
	MainMenu menu;
	sf::SoundBuffer m_jumpBuffer;
	sf::Sound m_jump;
	sf::SoundBuffer m_hitBuffer;
	sf::Sound m_hit;
	sf::SoundBuffer m_songBuffer;
	sf::Sound m_song;
	sf::SoundBuffer m_winBuffer;
	sf::Sound m_win;
	bool m_playSong = true;
	sf::Texture m_bgTexture;
	sf::Sprite m_bg;
	void initialize();
	void update();
	void render();
	void unload();
};

#endif  // ! GAME_H