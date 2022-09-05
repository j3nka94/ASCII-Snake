using System;
using System.Threading;

namespace ASCII_Snake
{
    class Program
    {
        // Consts.
        const int __width = 10;
        const int __height = 10;
        const int __loopSpeed = 6;

        // Variables.
        static Arena _arena;
        static Snake _snake;
        static Vector2Int _foodPosition;
        static int _score;

        static bool isDead = false;

        static Vector2Int _snakeDirection;

        static Random _foodRNG;

        static EventSystem _eventSystem;

        static void Main()
        {
            Initialize();

            while (true)
            {
                Update();

                if (isDead)
                    break;

                Draw();

                Thread.Sleep(1000 - 100 * __loopSpeed);
            }


            Console.ReadKey();
        }

        // Methods

        static void Initialize()
        {
            _arena = new Arena(__width, __height);
            _snake = new Snake(new Vector2Int(__width / 2, __height / 2));

            _score = 0;

            _snakeDirection = Vector2Int.Zero();

            _foodRNG = new Random();
            _foodPosition = new Vector2Int(1, 1);
            GenerateFood();

            _eventSystem = new EventSystem();
            _eventSystem.Initialize();
        }

        static void Update()
        {
            // Update direction
            switch (_eventSystem.LastKeyPressed)
            {
                case 'w':
                    if(_snakeDirection != new Vector2Int(0, 1))
                    {
                        _snakeDirection = new Vector2Int(0, -1);
                    }
                    break;

                case 'a':
                    if (_snakeDirection != new Vector2Int(1, 0))
                    {
                        _snakeDirection = new Vector2Int(-1, 0);
                    }
                    break;

                case 's':
                    if (_snakeDirection != new Vector2Int(0, -1))
                    {
                        _snakeDirection = new Vector2Int(0, 1);
                    }
                    break;

                case 'd':
                    if (_snakeDirection != new Vector2Int(-1, 0))
                    {
                        _snakeDirection = new Vector2Int(1, 0);
                    }
                    break;

                default:
                    break;
            }

            // Check next position
            Vector2Int nextPos = _snake.CurrentPosition + _snakeDirection;
            string nextArenaString = _arena.GetArena[nextPos.GetX, nextPos.GetY];
            bool willEat = false;
            if (nextArenaString == Arena.__wallStr || (nextArenaString == Arena.__snakeStr && nextPos != _snake.Next()))
            {
                DisplayDeathScene();
                isDead = true;
                return;
            }
            else if(nextArenaString == Arena.__foodStr)
            {
                willEat = true;
            }

            // Update snake
            if (!willEat)
            {
                Vector2Int deletedPos = _snake.Dequeue();
                _arena.SetPosition(deletedPos, Arena.__noneStr);
            }
            else
            {
                GenerateFood();
                _score++;
            }

            _snake.Queue(nextPos);

            // Update arena
            _arena.SetPosition(nextPos, Arena.__snakeStr);
        }

        static void Draw()
        {
            Console.SetCursorPosition(0, 0);
            Console.CursorVisible = false;

            Console.WriteLine("Score: " + _score + "\n");
            Console.WriteLine(_arena.Print());
        }

        static void GenerateFood()
        {
            int size = __height * __width;
            int index = _foodRNG.Next(size);
            Vector2Int position = Vector2Int.Zero();
            while(_arena.GetStringAsListIndex(index, out position) != Arena.__noneStr)
            {
                index = _foodRNG.Next(size);
            }

            _arena.SetPosition(_foodPosition, Arena.__noneStr);
            _arena.SetPosition(position, Arena.__foodStr);
            _foodPosition = position;
        }

        static void DisplayDeathScene()
        {
            Console.WriteLine("You died!");
        }
    }
}