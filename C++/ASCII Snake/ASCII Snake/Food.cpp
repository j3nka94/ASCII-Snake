#include "Food.h"

Food::Food(Arena *arena)
{
	position = Vector2Int();
	generateFood(arena);
}

Food::~Food()
{
}

void Food::generateFood(Arena* arena)
{
	int maxIndex = arena->width * arena->height - 1;
	int index = rand() % maxIndex;
	Vector2Int newPos = arena->indexToVector2Int(index);

	while (arena->arena[newPos.x][newPos.y] != arena->__noneStr)
	{
		index = rand() % maxIndex;
		newPos = arena->indexToVector2Int(index);
	}

	position = newPos;
	arena->setString(newPos, arena->__foodStr);
}
