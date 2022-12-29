#include <iostream>
#include "Pipe.h"

Pipe::Pipe(float yHoleBetweenPipes, float xPipePosition, int ind)
{
    index=ind;
    yPositionOfHole = yHoleBetweenPipes;
    xPositionOfPipes = xPipePosition;
}

void Pipe::loadTextureOfPipe(sf::Texture &pipe200x500Texture, sf::Texture &pipe200x600Texture)
{
    pipe200x500Texture.loadFromFile("../Pictures/pipe200x500.png");
    pipe200x500Sprite.setTexture(pipe200x500Texture);
    pipe200x500Sprite.setPosition(xOfpipe200x500Sprite + xPositionOfPipes, yOfpipe200x500Sprite);
    pipe200x600Texture.loadFromFile("../Pictures/pipe200x600.png");
    pipe200x600Sprite.setTexture(pipe200x600Texture);
    pipe200x600Sprite.setPosition(xOfpipe200x600Sprite + xPositionOfPipes, yOfpipe200x600Sprite);
    pipe200x600Sprite.setRotation(180);
}

void Pipe::drawPipe(sf::RenderWindow &window)
{
    window.draw(pipe200x500Sprite);
    window.draw(pipe200x600Sprite);
}

void Pipe::updatePipePosition()
{
    xOfpipe200x600Sprite = xOfpipe200x600Sprite - xPipeShift;
    xOfpipe200x500Sprite = xOfpipe200x500Sprite - xPipeShift;
    pipe200x500Sprite.setPosition(xOfpipe200x500Sprite + xPositionOfPipes + realShiftPositionOfPipe,
                                  yOfpipe200x500Sprite - yPositionOfHole);
    pipe200x600Sprite.setPosition(xOfpipe200x600Sprite + xPositionOfPipes + realShiftPositionOfPipe,
                                  yOfpipe200x600Sprite - yPositionOfHole + widthOfHole);
}

float Pipe::getxOfPipe200x600()
{
    return xOfpipe200x600Sprite + xPositionOfPipes + realShiftPositionOfPipe;
}

void Pipe::setNewPositionOfPipe(float newPipePositionShifter)
{
    realShiftPositionOfPipe += newPipePositionShifter;
}

CordsOfPipes Pipe::calculateCornersPoints()
{
    CordsOfPipes cordsOfPipes;

    cordsOfPipes.xOfLeftUpper = xOfpipe200x600Sprite + xPositionOfPipes + realShiftPositionOfPipe - 200 - 60;
    cordsOfPipes.yOfLeftUpper = 600 - yOfpipe200x600Sprite - yPositionOfHole + widthOfHole +35;
    cordsOfPipes.xOfLeftLower = xOfpipe200x600Sprite+ xPositionOfPipes + realShiftPositionOfPipe - 200 -65;
    cordsOfPipes.yOfLeftLower = yOfpipe200x600Sprite + 200;

    cordsOfPipes.xOfRightUpper = xOfpipe200x600Sprite + xPositionOfPipes + realShiftPositionOfPipe - 35;
    cordsOfPipes.yOfRightUpper = 600 - yOfpipe200x600Sprite - yPositionOfHole + widthOfHole;
    cordsOfPipes.xOfRightLower = xOfpipe200x600Sprite + xPositionOfPipes + realShiftPositionOfPipe;
    cordsOfPipes.yOfRightLower = 600 - yOfpipe200x600Sprite - yPositionOfHole + widthOfHole + 200;
    return cordsOfPipes;
}

float Pipe::getXpipeShift()
{
    return xPipeShift;
}

