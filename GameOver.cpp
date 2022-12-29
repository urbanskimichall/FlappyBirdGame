
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "GameOver.h"

bool GameOver::isGameOver(Bird &bird, Pipe &pipe, sf::RenderWindow &window)
{
    CordsOfPipes cordsOfPipes = pipe.calculateCornersPoints();
    if ((bird.getXPositionOfBird() > cordsOfPipes.xOfLeftUpper &&
         bird.getXPositionOfBird() < cordsOfPipes.xOfRightUpper &&
         bird.getYPositionOfBird() < cordsOfPipes.yOfLeftUpper) ||
        (bird.getXPositionOfBird() > cordsOfPipes.xOfLeftLower &&
         bird.getXPositionOfBird() < cordsOfPipes.xOfRightLower &&
         bird.getYPositionOfBird() > cordsOfPipes.yOfRightLower &&
         bird.getYPositionOfBird() > cordsOfPipes.yOfLeftLower))
    {
        loadGameOverWindow(window);
        std::cout << "game over  \n bird's cordsX " << bird.getXPositionOfBird() << "__________"
                  << bird.getYPositionOfBird() << std::endl;

        return true;
    }
    return false;
}

void GameOver::loadGameOverWindow(sf::RenderWindow &window)
{
    playAgain.setPosition(362, 260);
    playAgain.setSize({300, 200});
    playAgain.setFillColor({3, 100, 250});
    playAgain.setOutlineThickness(3);
    fontPlayAgain.loadFromFile("../Fonts/Raleway-ExtraLight.ttf");
    textPlayAgain.setFont(fontPlayAgain);
    textPlayAgain.setOutlineThickness(2);
    textPlayAgain.setString("Play Again");
    textPlayAgain.setPosition(440, 340);
    bool isPlayAgainClicked = false;
    while (1)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x > 362 && event.mouseButton.x < 662 &&
                 event.mouseButton.y > 260 &&  event.mouseButton.y < 460)
            {

                isPlayAgainClicked = true;
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(playAgain);
        window.draw(textPlayAgain);
        window.display();

        if (isPlayAgainClicked)
        {
            break;
        }
    }
}
