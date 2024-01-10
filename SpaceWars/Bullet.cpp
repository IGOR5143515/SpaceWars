#include "Bullet.h"


Bullet::Bullet(std::string str):bullet(str){

	speed = 0.2;
}
Bullet::Bullet() {

	speed = 1; 
}

void Bullet::createBullet(sf::Vector2f v) {
	
	Bullet* x = new Bullet("C:/Users/IGOR/source/repos/SpaceWars/img/bullet.png");
	x->getBullets().setPosition(v.x+24, v.y);
	bullets.push_back(x);
	
}

void Bullet::renderBullets(sf::RenderWindow &w) {

	for (size_t i = 0; i < bullets.size(); i++)
	{
		w.draw(bullets[i]->getBullets());
	}

}

void Bullet::moveBullets() {
	for (auto it = bullets.begin(); it != bullets.end(); ) {
		if ((*it)->getBullets().getPosition().y < 0) {
			// Условие для удаления элемента
			it = bullets.erase(it);
			
		}
		else {
			// Условие, при котором элемент остается в векторе
			++it;
		}
	}
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i]->getBullets().move(0, -speed);
	}

}





