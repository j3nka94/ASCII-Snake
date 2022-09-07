#include "Vector2Int.h"

Vector2Int::Vector2Int(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2Int::Vector2Int()
{
	x = 0;
	y = 0;
}

Vector2Int::~Vector2Int()
{
}

Vector2Int Vector2Int::add(Vector2Int other)
{
	int newX = this->x + other.x;
	int newY = this->y + other.y;

	return Vector2Int(newX, newY);
}

Vector2Int Vector2Int::subtract(Vector2Int other)
{
	int newX = this->x - other.x;
	int newY = this->y - other.y;

	return Vector2Int(newX, newY);
}

bool Vector2Int::compare(Vector2Int other)
{
	if (x == other.x && y == other.y) {
		return true;
	}

	return false;
}

Vector2Int Vector2Int::operator+(Vector2Int const& other)
{
	int newX = x + other.x;
	int newY = y + other.y;

	return Vector2Int(newX, newY);
}

bool Vector2Int::operator==(Vector2Int const& other)
{
	if (x == other.x && y == other.y) {
		return true;
	}

	return false;
}

bool Vector2Int::operator!=(Vector2Int const& other)
{
	if (x != other.x || y != other.y) {
		return true;
	}

	return false;
}

Vector2Int Vector2Int::zero()
{
	return Vector2Int(0, 0);
}
