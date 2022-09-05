using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ASCII_Snake
{
    public struct Vector2Int
    {
        int _x;
        int _y;

        public int GetX => _x;
        public int GetY => _y;

        public Vector2Int(int x, int y)
        {
            _x = x;
            _y = y;
        }

        public static Vector2Int Zero()
        {
            return new Vector2Int(0, 0);
        }

        // Operators

        public static Vector2Int operator + (Vector2Int a, Vector2Int b)
        {
            return new Vector2Int(a.GetX + b.GetX, a.GetY + b.GetY);
        }

        public static Vector2Int operator - (Vector2Int a, Vector2Int b)
        {
            return new Vector2Int(a.GetX - b.GetX, a.GetY - b.GetY);
        }

        public static bool operator == (Vector2Int a, Vector2Int b)
        {
            if (a.GetX == b.GetX && a.GetY == b.GetY)
                return true;

            return false;
        }

        public static bool operator != (Vector2Int a, Vector2Int b)
        {
            if (a.GetX != b.GetX || a.GetY != b.GetY)
                return true;

            return false;
        }
    }
}
