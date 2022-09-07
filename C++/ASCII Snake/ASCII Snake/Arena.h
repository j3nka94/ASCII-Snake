#pragma once

#include <string>
#include <vector>

#include "Vector2Int.h"

class Arena
{
	// Constants
public:
	const std::string __wallStr = "# ";
	const std::string __snakeStr = "S ";
	const std::string __foodStr = "F ";
	const std::string __noneStr = "  ";

	// Variables
public:
	int width;
	int height;
	std::vector<std::vector<std::string>> arena;

	// Constructors
public:
	Arena(int width, int height);
	~Arena();

	// Methods
public:
	void setString(Vector2Int position, std::string value);
	Vector2Int indexToVector2Int(int index);
	std::string getString(Vector2Int position);
	std::string toString();
};

