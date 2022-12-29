#ifndef FLAPPYBIRD_PIPE_H
#define FLAPPYBIRD_PIPE_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "CordsOfPipes.h"

class Pipe
{
public:
    Pipe(float yHoleBetweenPipes, float xPositionOfPipes, int index);

    void loadTextureOfPipe(sf::Texture &pipe200x500Texture, sf::Texture &pipe200x600Texture);

    void drawPipe(sf::RenderWindow &window);

    void updatePipePosition();

    void setNewPositionOfPipe(float newPipePositionShifter);

    float getxOfPipe200x600();

    float getXpipeShift();

    CordsOfPipes calculateCornersPoints();
    int index{0};

private:
    sf::Sprite pipe200x500Sprite;

    sf::Sprite pipe200x600Sprite;

    float xOfpipe200x500Sprite{600.f};
    float xOfpipe200x600Sprite{800.f};
    float yOfpipe200x500Sprite{502.f};
    float yOfpipe200x600Sprite{350.f};
    float xPipeShift{3.f};
    float yPositionOfHole{0.f};
    float widthOfHole{50.f};
    float xPositionOfPipes{0.f};
    float realShiftPositionOfPipe{0};
};


#endif //FLAPPYBIRD_PIPE_H
