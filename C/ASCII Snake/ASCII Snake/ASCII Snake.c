#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "OxymoronEvents.h"

// Constants

#define width 12
#define height 12

#define snakeChar 'S'
#define wallChar '#'
#define foodChar 'F'
#define noneChar ' '

// Variables

int gameSpeed = 8;
int gameLoopDelay = 1000;
int snakeLength = 1;

char arena[width*height];
int snakeIndices [width*height];
int currentSnakeIndex;
int foodIndex;

int currentDirection = 0;

bool isAlive = true;

// Methods

void initialize();
bool update();
void draw();
void setFoodIndex();
void onDeath();
void onEatFood();
void mapInput();

// Main
int main() {
	// Initialize events
	initializeEventSystem();

	// Initialize game
	initialize();

	// Gameloop
	while (true)
	{
		if (!isAlive || !update()) {
			continue;
		}

		draw();

		Sleep(gameLoopDelay);
	}
}

// Method implementations

void initialize() {
	// Set update speed
	gameLoopDelay = 1000 - 100 * (gameSpeed - 1);

	// Set arena
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			int index = width * h + w;
			if (w == 0 || w == width - 1 || h == 0 || h == height - 1) {
				arena[index] = wallChar;
			}
			else {
				arena[index] = noneChar;
			}
		}
	}

	// Set snake
	snakeIndices[0] = width * height / 2 + width / 2;
	currentSnakeIndex = 0;
	for (int i = 1; i < (height - 1) * (width - 1); i++)
	{
		snakeIndices[i] = 0;
	}

	// Set food
	setFoodIndex(arena);
}

bool update() {

	// Update direction
	mapInput();

	// Calculate next position
	int nextArenaIndex = snakeIndices[currentSnakeIndex];
	switch (currentDirection)
	{
	case 1:
		nextArenaIndex++;
		break;

	case 2:
		nextArenaIndex--;
		break;

	case 3:
		nextArenaIndex -= width;
		break;

	case 4:
		nextArenaIndex += width;
		break;

	default:
		break;
	}

	// Check if next position is possible
	if (currentDirection != 0 && (arena[nextArenaIndex] == snakeChar || arena[nextArenaIndex] == wallChar)) {
		onDeath();
		return false;
	}

	// Check if next position is on the food
	bool willEat = false;
	if (nextArenaIndex == foodIndex) {
		willEat = true;
	}

	// Update arena
	int nextSnakeIndex = currentSnakeIndex + 1;
	if (!willEat) {
		if (nextSnakeIndex == snakeLength) {
			nextSnakeIndex = 0;
		}

		arena[snakeIndices[nextSnakeIndex]] = noneChar;
	}
	else {
		for (int i = snakeLength; i > nextSnakeIndex; i--)
		{
			snakeIndices[i] = snakeIndices[i - 1];
		}

		onEatFood();
	}

	// Apply changes
	snakeIndices[nextSnakeIndex] = nextArenaIndex;
	arena[nextArenaIndex] = snakeChar;
	currentSnakeIndex = nextSnakeIndex;

	return true;
}

void draw() {
	// Clear screen
	system("cls");

	// Print score
	printf("Score : %i\n", snakeLength - 1);

	// Print arena
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			int index = width * h + w;
			printf("%c", arena[index]);
		}

		printf("\n");
	}
}

void setFoodIndex() {

	while (true)
	{
		int rnd = rand() % (height * width);

		if (arena[rnd] == noneChar) {
			foodIndex = rnd;
			arena[rnd] = foodChar;
			break;
		}
	}
}

void onDeath() {
	isAlive = false;
	printf("You died!");
}

void onEatFood() {
	snakeLength++;
	setFoodIndex();
}

void mapInput() {
	switch (eventChar)
	{
	case 'w':
		if (currentDirection != 4) {
			currentDirection = 3;
		}
		break;

	case 'a':
		if (currentDirection != 1) {
			currentDirection = 2;
		}
		break;

	case 's':
		if (currentDirection != 3) {
			currentDirection = 4;
		}
		break;

	case 'd':
		if (currentDirection != 2) {
			currentDirection = 1;
		}
		break;

	default:
		break;
	}
}