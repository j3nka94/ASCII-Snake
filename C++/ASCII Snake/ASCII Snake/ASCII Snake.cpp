#include <iostream>
#include <Windows.h>

#include "Arena.h"
#include "Snake.h"
#include "Food.h"
#include "EventSystem.h"

const int width = 10;
const int height = 10;
const int loopSpeed = 5;

Arena arena(width, height);
Snake snake(width, height);
Food *food;
int loopTime;
int score;
bool isDead;

// Methods
void initialize();
void update();
void draw();
void handleDirection();
void moveSnake();
void displayDeathScene();

int main()
{
    initialize();

    while (true) {

        update();

        if (isDead) {
            displayDeathScene();
            break;
        }

        draw();

        Sleep(loopTime);
    }
}

void initialize() {
    // Set loop time
    loopTime = 1000 - 100 * loopSpeed;

    // Set snake position in arena
    arena.setString(snake.positions[0], arena.__snakeStr);

    // Set food position in arena
    food = new Food(&arena);

    // Hide cursor
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &cursorInfo);

    
    score = 0;
    isDead = false;

    // Initialize events
    initializeEventSystem();
}

void update() {
    handleDirection();
    moveSnake();
}

void draw() {
    // Set cursor
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(handle, coord);

    // Draw
    std::cout << "Score: " << score << std::endl;
    std::cout << arena.toString() << std::endl;
}

void handleDirection() {

    if (snake.directionChar == eventChar) {
        return;
    }

    switch (eventChar)
    {
    case 'w':
        if (snake.directionChar != 's') {
            snake.directionChar = 'w';
            snake.direction = Vector2Int(0, -1);
        }
        break;

    case 'a':
        if (snake.directionChar != 'd') {
            snake.directionChar = 'a';
            snake.direction = Vector2Int(-1, 0);
        }
        break;

    case 's':
        if (snake.directionChar != 'w') {
            snake.directionChar = 's';
            snake.direction = Vector2Int(0, 1);
        }
        break;

    case 'd':
        if (snake.directionChar != 'a') {
            snake.directionChar = 'd';
            snake.direction = Vector2Int(1, 0);
        }
        break;

    default:
        break;
    }
}

void moveSnake() {
    Vector2Int nextSnakePos = snake.positions[snake.currentIndex] + snake.direction;
    Vector2Int firstSnakePos = snake.getNextIndexPosition();

    std::string nextPosString = arena.arena[nextSnakePos.x][nextSnakePos.y];
    std::string firstPosString = arena.arena[firstSnakePos.x][firstSnakePos.y];
    if (snake.direction != Vector2Int::zero() && nextSnakePos != firstSnakePos && (nextPosString == arena.__wallStr || nextPosString == arena.__snakeStr)) {
        isDead = true;
        return;
    }

    int nextSnakeIndex = snake.getNextIndex();
    if (nextSnakePos == food->position) {
        // Eat food
        score++;
        snake.insertAtIndex(&nextSnakePos, nextSnakeIndex);
        food->generateFood(&arena);
    }
    else {
        // Remove first snake pos
        arena.setString(firstSnakePos, arena.__noneStr);
    }

    snake.currentIndex = nextSnakeIndex;
    snake.positions[snake.currentIndex] = nextSnakePos;

    // Apply to arena
    arena.setString(nextSnakePos, arena.__snakeStr);
}

void displayDeathScene() {
    std::cout << "You died!" << std::endl;
}