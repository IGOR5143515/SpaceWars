#include <SFML/Graphics.hpp>
#include"Engine.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Wars");
  
    Engine e;
    e.start(window);



   
}