using System.Collections.Generic;

namespace ASCII_Snake
{
    public class Snake
    {
        Queue<Vector2Int> _positions;
        Vector2Int _currentPosition;

        public Vector2Int CurrentPosition => _currentPosition;

        public Queue<Vector2Int> Positions => _positions;

        public Snake(Vector2Int startPosition)
        {
            _positions = new Queue<Vector2Int>();
            _positions.Enqueue(startPosition);
            _currentPosition = startPosition;
        }

        public void Queue(Vector2Int position)
        {
            _positions.Enqueue(position);
            _currentPosition = position;
        }

        public Vector2Int Dequeue()
        {
            return _positions.Dequeue();
        }

        public Vector2Int Next()
        {
            return _positions.ToArray()[0];
        }
    }
}
