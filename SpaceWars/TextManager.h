#pragma once
#include <SFML/Graphics.hpp>
#include"SpaceShip.h"

enum class TextMode {
	HEALTH,
	POINTS

};

class TextManager{
private:
	sf::Font font;
	sf::Text text;
public:

	TextManager(std::string);

	sf::Text& getText() { return text; }
	
	void setStr(SpaceShip,TextMode);

};

