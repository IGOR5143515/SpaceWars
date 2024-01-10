#pragma once
#include"SpriteManager.h"
#include<vector>
#include"Bullet.h"





class Asteroid:public SpriteManager
{
private:
	std::vector<Asteroid*>aster;
	int CounterAsteroid{};
	float SpeedAsteroid{};
	int CounterOfLosing{};
public:
	
	Asteroid();
	void MinusCounterAsteroid() {  CounterAsteroid--; }
	std::vector<Asteroid*>& getAterVector() { return aster; }
	int GetCounterOfLosing() { return CounterOfLosing; }
	void SpawnAsteroid();
	void Collision(Bullet&);
	void RenderAsteroid(sf::RenderWindow&);
	void MoveAsteroid();
	void DeleteAsteroidAferShooting(std::vector<Asteroid*>::iterator);
	void DeleteRemainingAsteroid();
	int generateRandomNumber(int min, int max);
};

