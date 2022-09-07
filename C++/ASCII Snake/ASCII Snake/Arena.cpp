#include "Arena.h"

Arena::Arena(int width, int height)
{
	this->width = width;
	this->height = height;

	for (size_t h = 0; h < height; h++)
	{
		std::vector<std::string> row;
		for (size_t w = 0; w < width; w++)
		{
			if (h == 0 || w == 0 || h == height - 1 || w == width - 1) {
				row.push_back(__wallStr);
			}
			else
			{
				row.push_back(__noneStr);
			}
		}

		arena.push_back(row);
	}
}

Arena::~Arena()
{
}

void Arena::setString(Vector2Int position, std::string value)
{
	arena[position.x][position.y] = value;
}

Vector2Int Arena::indexToVector2Int(int index)
{
	int x = index / width;
	int y = index - x * width;
	return Vector2Int(x, y);
}

std::string Arena::getString(Vector2Int position)
{
	return arena[position.x][position.y];
}

std::string Arena::toString()
{
	std::string result = "";
	for (size_t h = 0; h < height; h++)
	{
		for (size_t w = 0; w < width; w++)
		{
			result += arena[w][h];
		}

		result += "\n";
	}

	return result;
}
