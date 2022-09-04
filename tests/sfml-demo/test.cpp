#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(400, 600);
    sf::RectangleShape rectangle(sf::Vector2f(250.f, 20.f));
    rectangle.setPosition(400, 850);
    
    float xPos = 5;
    float yPos = 5;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(rectangle);
        window.display();
        shape.move(xPos, yPos);
        if(shape.getPosition().x <= 0) {            
            xPos = .8f;
        } 
        else if(shape.getPosition().x >= 950) {            
            xPos -= .8f;
        } 
        else if(shape.getPosition().y <= 0) {            
            yPos = .8f;
        } 
        else if(shape.getPosition().y >= 850) {            
            yPos -= .8f;
        }      
    }

    return 0;
}