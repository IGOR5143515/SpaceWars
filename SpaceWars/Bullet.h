#pragma once
#include"vector"
#include"SpriteManager.h"
class Bullet
{
protected:
	
	
	SpriteManager bullet;
	float speed;
	
public:

	std::vector <Bullet*> bullets;
	Bullet(std::string);
	Bullet();
	
	sf::Sprite& getBullets() {
		return bullet.geSprite();
	}
	void createBullet(sf::Vector2f);
	
	void renderBullets(sf::RenderWindow&);

	virtual void moveBullets();
};

