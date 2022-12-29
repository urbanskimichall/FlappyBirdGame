#ifndef FLAPPYBIRD_BIRD_H
#define FLAPPYBIRD_BIRD_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>

class Bird
{
public:
    void loadBirdFromFile();

    sf::Sprite getBirdSprite();

    void birdFly();

    float getXPositionOfBird();

    float getYPositionOfBird();

    void setDefaultBirdPosition();

    sf::Text getTextPoints();
void updatePointsOnScreen();
    bool isFalling{true};
    bool isSpacePressedDuringRaising{false};
    int points{0};
    float velocity{0};

private:
    int xSizeOfBird{80};
    int ySizeOfBird{52};
    float xPositionOfBird{100};
    float yPositionOfBird{400};
    sf::Sprite birdSprite;
    sf::Texture birdTexture;

    float gravity{0.5f};
    float velocityAfterJump{5};
    float actualRotation{0};
    float initialRotation{-18.f};
    float initialVelocityAfterJump{10.f};
    float velocityThresholdForRotation{12.f};
    float shiftOfRotation{1.5f};
    float lowerRotationThreshold{-20.f};
    float upperRotationThreshold{20.f};
    sf::Text pointsOnScreen;
    sf::Font font;
    void updateBirdIfFalling();

    void updateBirdIfRaise();

    void changeRotation();
};


#endif //FLAPPYBIRD_BIRD_H
