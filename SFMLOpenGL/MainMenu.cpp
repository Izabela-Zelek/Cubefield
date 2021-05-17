#include <iostream> 
#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

//gets reference for the texture and sets properties for the buttons
void MainMenu::initialise(sf::Font& t_font)
{
	m_font = t_font;

	if (!m_bgTexture.loadFromFile(".//Assets//Textures//geometricbg.png"))
	{
		std::cout << "Error with menu bg texture";
	}

	m_bg.setTexture(m_bgTexture);
	m_bg.setPosition(0, 0);
	m_bg.setColor(sf::Color(255, 255, 255, 192));

	if (!m_buttonTexture.loadFromFile(".//Assets//Textures//button.png"))
	{
		std::cout << "Error with button texture";
	}

	if (!m_buttonBuffer.loadFromFile("./Assets/Sound/button.wav"))
	{
		std::cout << "Problem with hit sound file" << std::endl;
	}

	m_button.setBuffer(m_buttonBuffer);
	m_button.setVolume(37);


	for (int index = 0; index < MAX_BUTTON; index++)
	{
		m_buttonSprite[index].setTexture(m_buttonTexture);
		m_originalPos[index].x = m_buttonSprite[index].getGlobalBounds().width / 2 + m_buttonSprite[index].getGlobalBounds().height;
		m_originalPos[index].y = m_originalPos[index].x  / 2.5 + (m_buttonSpacing * index);

		m_buttonSprite[index].setPosition(m_originalPos[index]);
		m_pushedDownPos[index] = { m_buttonSprite[index].getPosition().x, m_buttonSprite[index].getPosition().y + 10 };

		m_buttonSprite[index].setOrigin(m_buttonSprite[index].getGlobalBounds().width / 2, m_buttonSprite[index].getGlobalBounds().height / 2);

		m_TextOnButton[index].setFont(m_font);
		m_TextOnButton[index].setString(m_menuTexts[index]);
		m_TextOnButton[index].setFillColor(sf::Color::White);
		m_TextOnButton[index].setCharacterSize(50u);

		m_TextOnButton[index].setOrigin(m_TextOnButton[index].getGlobalBounds().width / 2, m_TextOnButton[index].getGlobalBounds().height / 2);
	}


}
//draws the button sprites and text
void MainMenu::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_bg);
	for (int index = 0; index < MAX_BUTTON; index++)
	{
		t_window.draw(m_buttonSprite[index]);
		t_window.draw(m_TextOnButton[index]);
	}

}
//checks if mouseclick is within button boundary, changes gamestate if true
int MainMenu::processInput(sf::Window& t_window, sf::Event t_event)
{
	int changeState = 0;
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(t_window);
	for (int i = 0; i < MAX_BUTTON; i++)
	{
		if (mousePos.x > m_buttonSprite[i].getGlobalBounds().left && mousePos.x < m_buttonSprite[i].getGlobalBounds().left + m_buttonSprite[i].getGlobalBounds().width &&
			mousePos.y > m_buttonSprite[i].getGlobalBounds().top && mousePos.y < m_buttonSprite[i].getGlobalBounds().top + m_buttonSprite[i].getGlobalBounds().height)
		{
			if (t_event.type == sf::Event::MouseButtonReleased)
			{
				changeState = i + 1;
				if (sf::Sound::Playing != m_button.getStatus())
				{
					m_button.play();
				}
				
			}
		}
	}

	return changeState;
}

void MainMenu::update(sf::Window& t_window)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(t_window);
	/// <summary>
	/// changes position and colour slightly to show which button is being pressed
	/// </summary>
	/// <param name="t_window"></param>
	/// <param name="t_player"></param>
	/// <returns></returns>
	for (int i = 0; i < MAX_BUTTON; i++)
	{
		if (mousePos.x > m_buttonSprite[i].getGlobalBounds().left && mousePos.x < m_buttonSprite[i].getGlobalBounds().left + m_buttonSprite[i].getGlobalBounds().width &&
			mousePos.y > m_buttonSprite[i].getGlobalBounds().top && mousePos.y < m_buttonSprite[i].getGlobalBounds().top + m_buttonSprite[i].getGlobalBounds().height)
		{
			m_buttonSprite[i].setPosition(m_pushedDownPos[i]);
			m_buttonSprite[i].setColor(sf::Color(135, 130, 189));

		}

		else
		{
			m_buttonSprite[i].setPosition(m_originalPos[i]);
			m_buttonSprite[i].setColor(sf::Color::White);
		}
		m_TextOnButton[i].setPosition(m_buttonSprite[i].getPosition().x, m_buttonSprite[i].getPosition().y - 10);
	}
}
