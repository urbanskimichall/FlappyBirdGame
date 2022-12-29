#include <iostream>
#include "PipeManagement.h"
#include "Bird.h"

PipeManagement::PipeManagement()
{
    Pipe pipe1{-50, 0, 0};
    Pipe pipe2{50, 500, 1};
    Pipe pipe3{-50, 1000, 2};
    Pipe pipe4{50, 1500, 3};
    pipe1.loadTextureOfPipe(pipe200x500Texture, pipe200x600Texture);
    pipe2.loadTextureOfPipe(pipe200x500Texture, pipe200x600Texture);
    pipe3.loadTextureOfPipe(pipe200x500Texture, pipe200x600Texture);
    pipe4.loadTextureOfPipe(pipe200x500Texture, pipe200x600Texture);
    pipes.push_back(pipe1);
    pipes.push_back(pipe2);
    pipes.push_back(pipe3);
    pipes.push_back(pipe4);
}

void PipeManagement::isPipeBehindBird(Bird &bird, sf::RenderWindow &window)
{
    if (bird.getXPositionOfBird() > pipes[pipeIndexToCheck].getxOfPipe200x600() + 100)
    {
        pipes[pipeIndexToCheck].setNewPositionOfPipe(newPipeShifter);
        pipeIndexToCheck++;
        if (pipeIndexToCheck == 4)
        {
            pipeIndexToCheck = 0;
        }
        std::cout << "rury nie ma" << pipeIndexToCheck << "komunikat " << pipes[pipeIndexToCheck].getxOfPipe200x600()
                  << std::endl;
    }

    if (gameOver.isGameOver(bird, pipes[pipeIndexToCheck], window))
    {
        pipes.clear();
        bird.points = 0;
        bird.velocity = 0.f;
        bird.setDefaultBirdPosition();
        pipeIndexToCheck = 0;
        Pipe pipe1{-50, 0, 0};
        Pipe pipe2{50, 500, 1};
        Pipe pipe3{-50, 1000, 2};
        Pipe pipe4{50, 1500, 3};
        pipe1.loadTextureOfPipe(pipe200x500Texture, pipe200x600Texture);
        pipe2.loadTextureOfPipe(pipe200x500Texture, pipe200x600Texture);
        pipe3.loadTextureOfPipe(pipe200x500Texture, pipe200x600Texture);
        pipe4.loadTextureOfPipe(pipe200x500Texture, pipe200x600Texture);
        pipes.push_back(pipe1);
        pipes.push_back(pipe2);
        pipes.push_back(pipe3);
        pipes.push_back(pipe4);
    }
}

void PipeManagement::updatePipesPositions()
{
    for (int i = 0; i < pipes.size(); ++i)
    {
        pipes[i].updatePipePosition();
    }
}

void PipeManagement::drawPipes(sf::RenderWindow &window)
{
    for (int i = 0; i < pipes.size(); ++i)
    {
        pipes[i].drawPipe(window);
    }
}

int PipeManagement::scoreUpdate(int score, float xPositionOfBird)
{
    if (xPositionOfBird >= pipes[pipeIndexToCheck].getxOfPipe200x600() &&
        xPositionOfBird < pipes[pipeIndexToCheck].getXpipeShift() + pipes[pipeIndexToCheck].getxOfPipe200x600())
    {
        score++;
        std::cout << "Punkty " << score << std::endl;
    }
    return score;
}



