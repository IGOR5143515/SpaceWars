#pragma once
#include <SFML/Graphics.hpp>
#include"Bullet.h"
#include"SpaceShip.h"
#include"Asteroid.h"
#include"TextManager.h"
#include<iostream>


class Engine {
private:
	
	TextManager t;
	Asteroid a;
	SpriteManager backGround;
	SpaceShip ship;
	Bullet b;
public:
	Engine():backGround("C:/Users/IGOR/source/repos/SpaceWars/img/back.jpg"),
	t("C:/Users/IGOR/source/repos/SpaceWars/SpaceWars/fonts/CyrilicOld.ttf")
	{
		
	}
	void start(sf::RenderWindow&);

};

