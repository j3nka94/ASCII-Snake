#pragma once

#include "Vector2Int.h"
#include "Arena.h"

class Food
{
public:
	Vector2Int position;

	// Constructors
public:
	Food(Arena *arena);
	~Food();

	// Methods
public:
	void generateFood(Arena *arena);
};

