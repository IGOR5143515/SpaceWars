#include "SpaceShip.h"

SpaceShip::SpaceShip() :SpriteManager("C:/Users/IGOR/source/repos/SpaceWars/img/ship.png") {

	speed = 0.3;
	health = 100;
	damege = 5;

	s.setPosition(500, 500);

}

double SpaceShip::getSpeed() {
	return speed;
}

bool SpaceShip::CollisionWithAsteroid(Asteroid &a) {


	for (auto it=a.getAterVector().begin();it!=a.getAterVector().end();)
	{
		if (this->geSprite().getGlobalBounds().intersects((*it)->geSprite().getGlobalBounds()))
		{
			it = a.getAterVector().erase(it);
			health -= 10;
			a.MinusCounterAsteroid();
			return false;
		}
		else
			it++;
	}



}