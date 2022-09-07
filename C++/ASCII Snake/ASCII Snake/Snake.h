#pragma once

#include <vector>
#include "Vector2Int.h"
#include "Arena.h"

class Snake
{
	// Variables
public:
	std::vector<Vector2Int> positions;
	int currentIndex;
	Vector2Int direction;
	char directionChar;

	// Constructors
public:
	Snake(int width, int height);
	~Snake();

	// Methods
public:
	int getNextIndex();
	Vector2Int getNextIndexPosition();
	void insertAtIndex(Vector2Int *position, int index);
};

