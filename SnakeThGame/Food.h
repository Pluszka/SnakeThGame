#pragma once

#include <raylib.h>
#include <list>
#include <raymath.h>


using namespace std;

class Food
{
public:
    Vector2 position;
    int cellCount;

    Food();

    Food(int cellCountArg, const list<Vector2>& snakeBody);

    void Draw(int cellSize, int offset, Color color);

    Vector2 GenerateRandomPosition(const list<Vector2>& snakeBody);

private:
    bool FoodInSnake(Vector2 food, const list<Vector2>& snake);

    Vector2 GenerateRandomCell();
};

