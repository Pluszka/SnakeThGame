#include <raylib.h>
#include <iostream>
#include "Game.h"

using namespace std;

const Color orange = { 255, 188, 141, 255 };
const Color purple = { 98, 50, 164, 255 };
const Color yellow = { 243, 201, 85, 255 };
const Color darkPurple = { 131, 19, 110, 255 };

const int cellSize = 30;
const int cellCount = 25;
int offset = 75;

double lastUpdateTime = 0;

bool eventTrigger(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	cout << "Starting the game..." << endl;
	InitWindow(2*offset + cellSize*cellCount, 2 * offset + cellSize * cellCount, "Snake The Game");
	SetTargetFPS(60);

	Game game = Game(cellCount, cellSize, offset, purple, darkPurple, yellow);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		if (eventTrigger(0.2)) {
			game.Update();
		}

		if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
			game.snake.direction = { 0, -1 };
		}
		if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
			game.snake.direction = { 0, 1 };
		}
		if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
			game.snake.direction = { -1, 0 };
		}
		if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
			game.snake.direction = { 1, 0 };
		}
		if (IsKeyPressed(KEY_SPACE) && game.freeze) {
			game.Reset();
		}

		ClearBackground(orange);
		DrawRectangleLinesEx(Rectangle{(float)offset-5, (float)offset - 5, (float)cellSize*cellCount+10, (float)cellSize * cellCount + 10}, 5, purple);
		DrawText("Snake the Game", offset - 5, 20, 40, purple);
		DrawText(TextFormat("Score: %i", game.score), offset - 5,offset+cellSize*cellCount+10, 40, purple);
		game.Draw();
		EndDrawing();

	}

	CloseWindow();
	return 0;
}
