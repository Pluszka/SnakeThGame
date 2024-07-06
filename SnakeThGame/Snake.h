#pragma once

#include <list>
#include <raylib.h>
#include <raymath.h>

using namespace std;

class Snake {
public:
    list<Vector2> startBody;
    list<Vector2> body;
    Vector2 startDirection;
    Vector2 direction;
    bool grow;

    Snake();

    void Draw(float cellSize, int offset, Color mainColor, Color secondaryColor);

    void Update();

    void Reset();
};

