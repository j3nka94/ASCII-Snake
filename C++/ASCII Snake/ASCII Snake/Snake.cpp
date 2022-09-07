#include "Snake.h"

Snake::Snake(int width, int height)
{
	currentIndex = 0;
	positions.push_back(Vector2Int(width / 2, height / 2));
	direction = Vector2Int();
	directionChar = ' ';
}

Snake::~Snake()
{
}

int Snake::getNextIndex()
{
	int nextIndex = currentIndex + 1;
	if (nextIndex == positions.size()) {
		nextIndex = 0;
	}

	return nextIndex;
}

Vector2Int Snake::getNextIndexPosition()
{
	return positions[getNextIndex()];
}

void Snake::insertAtIndex(Vector2Int *position, int index)
{
	positions.push_back(Vector2Int::zero());
	int length = positions.size();
	for (int i = length - 1; i > index; i--)
	{
		positions[i] = positions[i - 1];
	}

	positions[index] = *position;
}
