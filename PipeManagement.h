#ifndef FLAPPYBIRD_PIPEMANAGEMENT_H
#define FLAPPYBIRD_PIPEMANAGEMENT_H


#include "Pipe.h"
#include "GameOver.h"
#include "Bird.h"

class PipeManagement
{
public:
    PipeManagement();

    void isPipeBehindBird(Bird &bird,sf::RenderWindow &window);

    void updatePipesPositions();

    void drawPipes(sf::RenderWindow &window);

    int scoreUpdate(int score, float xPositionOfBird);

    std::vector<Pipe> pipes;
private:
    int pipeIndexToCheck{0};
    float newPipeShifter{2000.f};
    GameOver gameOver;
    sf::Texture pipe200x500Texture;
    sf::Texture pipe200x600Texture;
};


#endif //FLAPPYBIRD_PIPEMANAGEMENT_H
