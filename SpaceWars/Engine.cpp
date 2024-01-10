#include "Engine.h"

void Engine::start(sf::RenderWindow& window) {
    sf::Clock clock;
    float AsteroidTimer{};
    float bulletTimer{};
 
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        bulletTimer += time;            //timer
        AsteroidTimer += time;

        {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                ship.geSprite().move(ship.getSpeed()* time, 0);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                ship.geSprite().move(-ship.getSpeed() * time, 0);
                            
            //Moving
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                ship.geSprite().move(0, -ship.getSpeed() * time);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                ship.geSprite().move(0, ship.getSpeed() * time);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                if (bulletTimer > 200) {                                // shooting every bulletTimer second
                    sf::Vector2f vec(ship.geSprite().getPosition().x, ship.geSprite().getPosition().y);
                    b.createBullet(vec);
                    bulletTimer = 0;
                }
            }

            if (AsteroidTimer > 1000) {     
                a.SpawnAsteroid();
                AsteroidTimer = 0;
                
            }

            {
                if (ship.geSprite().getPosition().y < 0)
                    ship.geSprite().move(0, 1);

                if (ship.geSprite().getPosition().y >640 )
                    ship.geSprite().move(0, -1);
                                                                    //Move limit
                if (ship.geSprite().getPosition().x < 0)
                    ship.geSprite().move(1, 0);

                if (ship.geSprite().getPosition().x > 1200)
                    ship.geSprite().move(-1, 0);
            
            }
           
        }
        if (a.GetCounterOfLosing() >=5)         //lose game after sceep asteroid
            break;
        if (ship.CollisionWithAsteroid(a) == false && ship.getHeslth()==0) //lose after collision with asteroid
            break;                                  

        a.Collision(b);

        a.DeleteRemainingAsteroid(); //Delete Remaining Asteroids
       
        //move bullet sprite
        b.moveBullets();  
        a.MoveAsteroid();

        t.setStr(ship,TextMode::HEALTH);   //SetTextFormat
       
        
        window.clear();
        window.draw(backGround.geSprite());
        window.draw(t.getText());
        
        a.RenderAsteroid(window);
        window.draw(ship.geSprite());
        b.renderBullets(window);
        window.display();

    







       
    }

}
