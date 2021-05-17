#pragma once
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

class MainMenu
{

	//constant value for amount of buttons
	static const int MAX_BUTTON = 2;
	//reference for font used
	sf::Font m_font;
	//reference for texture used
	sf::Texture m_buttonTexture;
	//sf::Texture m_menuTexture;
	//array of the button texts
	sf::Text m_TextOnButton[MAX_BUTTON];
	//array of the button sprites
	sf::Sprite m_buttonSprite[MAX_BUTTON];
	sf::Vector2f m_originalPos[MAX_BUTTON];
	sf::Vector2f m_pushedDownPos[MAX_BUTTON];
	sf::String m_menuTexts[MAX_BUTTON] = { "Play","Exit" };
	sf::Vector2f m_buttonOffset{ 200,200 };
	sf::SoundBuffer m_buttonBuffer;
	sf::Sound m_button;
	sf::Texture m_bgTexture;
	sf::Sprite m_bg;
	//spacing between the buttons
	float m_buttonSpacing{ 250.0f };
	
public:
	MainMenu();
	~MainMenu();

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window); //draws the sprites and texts
	int processInput(sf::Window& t_window, sf::Event t_event); //checks if buttons pressed
	void update(sf::Window& t_window);

};
