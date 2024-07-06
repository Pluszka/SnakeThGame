#include "Game.h"

Game::Game(int cellCount, int cellSize, int offset, Color foodColor, Color snakeMainColor, Color snakeSecondaryColor)
    : cellCount(cellCount), cellSize(cellSize), offset(offset), foodColor(foodColor), snakeMainColor(snakeMainColor), snakeSecondaryColor(snakeSecondaryColor), snake(), food(cellCount, snake.body) {
}

void Game::Draw() {
    food.Draw(cellSize, offset, foodColor);
    snake.Draw(cellSize, offset, snakeMainColor, snakeSecondaryColor);
}

void Game::Update() {
    if (!freeze) {
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
}

void Game::Reset() {
    snake.Reset();
    food.position = food.GenerateRandomPosition(snake.body);
    score = 0;
    freeze = false;
}

void Game::CheckCollisionWithFood() {
    if (Vector2Equals(snake.body.front(), food.position)) {
        snake.grow = true;
        food.position = food.GenerateRandomPosition(snake.body);
        score++;
    }
}

void Game::CheckCollisionWithEdges() {
    Vector2 snakeHead = snake.body.front();
    if (snakeHead.x == cellCount || snakeHead.x == -1 || snakeHead.y == cellCount || snakeHead.y == -1) {
        freeze = true;
    }
}

void Game::CheckCollisionWithTail() {
    list<Vector2> headless = snake.body;
    headless.pop_front();
    for (const auto& segment : headless) {
        if (segment.x == snake.body.front().x && segment.y == snake.body.front().y) {
            freeze = true;
            return;
        }
    }
}
