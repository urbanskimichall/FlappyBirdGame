#ifndef FLAPPYBIRD_GAMEOVER_H
#define FLAPPYBIRD_GAMEOVER_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "Pipe.h"
#include "Bird.h"

class GameOver
{
public:
    bool isGameOver(Bird &bird, Pipe &pipe,sf::RenderWindow &window);
private:
    void loadGameOverWindow(sf::RenderWindow &window);
    sf::RectangleShape playAgain;
    sf::Font fontPlayAgain;
    sf::Text textPlayAgain;
};


#endif //FLAPPYBIRD_GAMEOVER_H
