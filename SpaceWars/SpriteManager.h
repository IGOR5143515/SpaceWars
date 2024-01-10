#pragma once
#include <SFML/Graphics.hpp>
class SpriteManager{
protected:
	sf::Texture t;
	sf::Sprite s;

public:
	SpriteManager(std::string str);

	void setSprite(std::string str) {
	
		sf::Texture t;
		t.loadFromFile(str);
		s.setTexture(t);
	
	}


	sf::Sprite& geSprite();

	SpriteManager(){}


};

