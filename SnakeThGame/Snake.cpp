#include "Snake.h"

Snake::Snake() : startBody({ Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} }),
body(startBody),
startDirection({ 1, 0 }),
direction(startDirection),
grow(false)
{
}

void Snake::Draw(float cellSize, int offset, Color mainColor, Color secondaryColor)
{
    int index = 0;
    for (auto it = body.begin(); it != body.end(); ++it, ++index) {
        float x = it->x;
        float y = it->y;
        Rectangle segment = Rectangle{ offset + x * cellSize, offset + y * cellSize, cellSize, cellSize };
        DrawRectangleRounded(segment, 0.5, 6, mainColor);
        float halfSize = cellSize / 3;
        Rectangle skinPattern = { segment.x + (segment.width - halfSize) / 2, segment.y + (segment.height - halfSize) / 2, halfSize, halfSize };
        DrawRectangleRec(skinPattern, secondaryColor);
    }
}

void Snake::Update()
{
    if (!this->grow) {
        body.pop_back();
    }
    else {
        this->grow = false;
    }
    Vector2 newHead = { body.front().x + direction.x, body.front().y + direction.y };
    body.push_front(newHead);
}

void Snake::Reset()
{
    body = startBody;
    direction = startDirection;
}
