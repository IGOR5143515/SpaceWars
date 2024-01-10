#pragma once
#include"Asteroid.h"
#include"SpriteManager.h"
class SpaceShip :
    public SpriteManager
{
private:
    int points{};
    double speed;
    int health;
    int damege;
public:
    SpaceShip();
    int getPoints() { return points; }
    void setPoints(int p) { points += p; }
    bool CollisionWithAsteroid(Asteroid&);
    double getSpeed();
    int getHeslth() { return health; }
};

