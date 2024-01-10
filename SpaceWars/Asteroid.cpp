#include "Asteroid.h"
#include <iostream>
#include <random>
Asteroid::Asteroid():
	SpriteManager("C:/Users/IGOR/source/repos/SpaceWars/img/Asteroid.png") {}


void Asteroid::SpawnAsteroid() {
    if (CounterAsteroid<5) {
        Asteroid* ptr = new Asteroid;
        
        int y = generateRandomNumber(0, 1100);
        ptr->geSprite().setPosition(y, -100);
        aster.push_back(ptr);
        CounterAsteroid++;
    }
}

void Asteroid::DeleteRemainingAsteroid() {

    for (auto it = aster.begin(); it != aster.end();) {

        if ((*it)->geSprite().getPosition().y >800) {

            it = aster.erase(it);
            CounterAsteroid--;
            CounterOfLosing++;
        }
        else
            it++;
        
    }
   
}

void Asteroid::MoveAsteroid() {
    
    for (size_t i = 0; i < aster.size(); i++)
    {
        aster[i]->geSprite().move(0, 0.1);
    }

}

void Asteroid::RenderAsteroid(sf::RenderWindow& w) {


    for (size_t i = 0; i < aster.size(); i++)
    {
        w.draw(aster[i]->geSprite());
    }
   
}

int Asteroid::generateRandomNumber(int min, int max) {

   
    std::random_device rd;
    std::mt19937 mt(rd());

 
    std::uniform_int_distribution<int> dist(min, max);

    
    return dist(mt);
}

void Asteroid::DeleteAsteroidAferShooting(std::vector<Asteroid*>::iterator it) {
    for (auto del = aster.begin(); del != aster.end();) {
        if (del == it)
            del = aster.erase(del);
        else
            del++;

    }


}

void Asteroid::Collision(Bullet& b) {
    
    SpeedAsteroid += 0.1;

    for (auto it = b.bullets.begin(); it != b.bullets.end();)
    {
        bool removedBullet = false;

        for (auto it2 = aster.begin(); it2 != aster.end();)
        {
            if ((*it)->getBullets().getGlobalBounds().intersects((*it2)->geSprite().getGlobalBounds()))
            {
                // Если есть столкновение, удаляем астероид и помечаем пулю для удаления
                it2 = aster.erase(it2);
                removedBullet = true;
                CounterAsteroid--;
                
              
            }
            else
            {
                ++it2;
            }
        }

        if (removedBullet)
        {
            // Удаляем пулю только если она столкнулась
            it = b.bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
    

}