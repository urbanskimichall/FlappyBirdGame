#include <iostream>
#include "Bird.h"

void Bird::loadBirdFromFile()
{
    font.loadFromFile("../Fonts/Raleway-ExtraLight.ttf");
    pointsOnScreen.setFont(font);
    pointsOnScreen.setScale(2,2);
    pointsOnScreen.setPosition(30,30);
    pointsOnScreen.setCharacterSize(16);
    pointsOnScreen.setFillColor({255,2,3});
    pointsOnScreen.setOutlineColor({2,3,255});
    pointsOnScreen.setOutlineThickness(1);

    birdTexture.loadFromFile("../Pictures/bird80x52.png");
    birdSprite.setTexture(birdTexture);
    birdSprite.setPosition(xPositionOfBird, yPositionOfBird);
}

sf::Sprite Bird::getBirdSprite()
{
    return birdSprite;
}

void Bird::birdFly()
{
    if (isFalling)
    {
        updateBirdIfFalling();
    }
    else
    {
        updateBirdIfRaise();
        actualRotation = initialRotation;
    }
    changeRotation();
    updatePointsOnScreen();
}

void Bird::updateBirdIfFalling()
{
    velocity += gravity;
    yPositionOfBird += velocity;
    birdSprite.setPosition(xPositionOfBird, yPositionOfBird);
}

void Bird::updateBirdIfRaise()
{
    velocityAfterJump -= gravity;
    yPositionOfBird -= velocityAfterJump;
    birdSprite.setPosition(xPositionOfBird, yPositionOfBird);

    if (isSpacePressedDuringRaising)
    {
        velocityAfterJump = initialVelocityAfterJump;
        isSpacePressedDuringRaising = false;
    }
    if (velocityAfterJump < 0.1)
    {
        velocity = 0;
        isFalling = true;
        velocityAfterJump = initialVelocityAfterJump;
    }
}

void Bird::changeRotation()
{
    if (isFalling && velocity < velocityThresholdForRotation)
    {
        if (actualRotation < upperRotationThreshold && actualRotation > lowerRotationThreshold)
        {
            actualRotation += shiftOfRotation;
        }
    }
    else if (!isFalling && velocityAfterJump < velocityThresholdForRotation)
    {
        if (actualRotation < upperRotationThreshold && actualRotation > lowerRotationThreshold)
        {
            actualRotation -= shiftOfRotation;
        }
    }
    birdSprite.setRotation(actualRotation);

}

float Bird::getXPositionOfBird()
{
    return xPositionOfBird;
}

float Bird::getYPositionOfBird()
{
    return yPositionOfBird;
}

void Bird::setDefaultBirdPosition()
{
    xPositionOfBird = 100;
    yPositionOfBird = 400;
}

void Bird::updatePointsOnScreen()
{
    std::string stringPoints = std::to_string(points);
    pointsOnScreen.setString("Score: " + stringPoints);
}

sf::Text Bird::getTextPoints()
{
    return pointsOnScreen;
}
