using System;
using System.Text;

namespace ASCII_Snake
{
    public class Arena
    {
        public const string __wallStr = "# ";
        public const string __snakeStr = "S ";
        public const string __foodStr = "F ";
        public const string __noneStr = "  ";

        public readonly int _width;
        public readonly int _height;

        string[,] _arena;

        public string[,] GetArena => _arena;

        public Arena(int width, int height)
        {
            _width = width;
            _height = height;
            _arena = new string[_width, _height];
            for (int h = 0; h < _height; h++)
            {
                for (int w = 0; w < _width; w++)
                {
                    if(w == 0 || w == _width - 1 || h == 0 || h == _height - 1)
                    {
                        _arena[w, h] = __wallStr;
                    }
                    else
                    {
                        _arena[w, h] = __noneStr;
                    }
                }
            }
        }

        public void SetPosition(Vector2Int position, string value)
        {
            _arena[position.GetX, position.GetY] = value;
        }

        public void RemovePosition(Vector2Int position)
        {
            _arena[position.GetX, position.GetY] = __noneStr;
        }

        public string GetStringAsListIndex(int index, out Vector2Int position)
        {
            int row = index / _width;
            int col = index - row * _width;

            position = new Vector2Int(row, col);
            return _arena[row, col];
        }

        public string Print()
        {
            StringBuilder sb = new StringBuilder();
            for (int h = 0; h < _height; h++)
            {
                for (int w = 0; w < _width; w++)
                {
                    sb.Append(_arena[w, h]);
                }

                sb.Append("\n");
            }

            return sb.ToString();
        }
    }
}
