#include "TextManager.h"


TextManager::TextManager(std::string s) {

	font.loadFromFile(s);
	text.setFont(font);
//	text.setColor(sf::Color::Blue);
	text.setPosition(100, 100);

		
}


void TextManager::setStr(SpaceShip s,TextMode mode) {
	std::string str;

	if(mode==TextMode::HEALTH)
	 str = std::to_string(s.getHeslth());

	if (mode == TextMode::POINTS)
		str = std::to_string(s.getPoints());

	text.setString(str);

}