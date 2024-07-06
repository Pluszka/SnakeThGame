#include "Food.h"

Food::Food() : position({ 0.0f, 0.0f }), cellCount(70)
{
}

Food::Food(int cellCountArg, const list<Vector2>& snakeBody)
{
    this->cellCount = cellCountArg;
    GenerateRandomPosition(snakeBody);
}


void Food::Draw(int cellSize, int offset, Color color)
{
    float posX = offset + position.x * cellSize + cellSize / 2;
    float posY = offset + position.y * cellSize + cellSize / 2;

    DrawCircle(posX, posY, cellSize / 2, color);
}

Vector2 Food::GenerateRandomPosition(const list<Vector2>& snakeBody)
{
    Vector2 newPosition;
    do {
        newPosition = GenerateRandomCell();
    } while (FoodInSnake(newPosition, snakeBody));

    this->position = newPosition;
    return newPosition;
}

bool Food::FoodInSnake(Vector2 food, const list<Vector2>& snake)
{
    for (auto it = snake.begin(); it != snake.end(); ++it) {
        if (Vector2Equals(*it, food)) {
            return true;
        }
    }
    return false;
}

Vector2 Food::GenerateRandomCell()
{
    float x = GetRandomValue(0, this->cellCount - 1);
    float y = GetRandomValue(0, this->cellCount - 1);
    return Vector2{ x, y };
}
