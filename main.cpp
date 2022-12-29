#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "Bird.h"
#include "Pipe.h"
#include "PipeManagement.h"

int main()
{
    int windowWidth{1024};
    int windowHeight{720};
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "FlappyBird");
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    backgroundTexture.loadFromFile("../Pictures/background.png");
    backgroundSprite.setTexture(backgroundTexture);
    Bird bird;

    bird.loadBirdFromFile();

    PipeManagement pipeManagement;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) ||
                (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Left)))
            {
                bird.isFalling = false;
                bird.isSpacePressedDuringRaising = true;
            }
        }
        pipeManagement.updatePipesPositions();
        bird.points = pipeManagement.scoreUpdate(bird.points, 100);
        pipeManagement.isPipeBehindBird(bird,window);
        bird.birdFly();
        window.clear();
        window.draw(backgroundSprite);
        window.draw(bird.getBirdSprite());
        pipeManagement.drawPipes(window);
        window.draw(bird.getTextPoints());
        window.display();
        std::chrono::milliseconds timespan(1);

        std::this_thread::sleep_for(timespan);
    }
}
