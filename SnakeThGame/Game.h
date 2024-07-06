#pragma once

#include "Food.h"
#include "Snake.h"

class Game {
public:
    int cellSize;
    int cellCount;
    int offset;
    bool freeze = false;
    Color foodColor;
    Color snakeMainColor;
    Color snakeSecondaryColor;
    Snake snake;
    Food food;
    int score = 0;

    Game(int cellCount, int cellSize, int offset, Color foodColor, Color snakeMainColor, Color snakeSecondaryColor);

    void Draw();

    void Update();

    void Reset();

private:
    void CheckCollisionWithFood();

    void CheckCollisionWithEdges();

    void CheckCollisionWithTail();
};

