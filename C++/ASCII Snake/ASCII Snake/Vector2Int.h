#pragma once

struct Vector2Int {
	// Variables;
public:
	int x;
	int y;

	// Constructors
public:
	Vector2Int(int x, int y);
	Vector2Int();
	~Vector2Int();

	// Methods
public:
	Vector2Int add(Vector2Int other);
	Vector2Int subtract(Vector2Int other);
	bool compare(Vector2Int other);

	// Operator overloads
public:
	Vector2Int operator + (Vector2Int const& other);
	bool operator == (Vector2Int const& other);
	bool operator != (Vector2Int const& other);

	// Statics
public:
	static Vector2Int zero();
};