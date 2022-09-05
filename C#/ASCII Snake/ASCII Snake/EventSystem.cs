using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ASCII_Snake
{
    public class EventSystem
    {
        ConsoleKeyInfo _lastKeyPressed;

        public char LastKeyPressed => _lastKeyPressed.KeyChar;

        public void Initialize()
        {
            new Thread(CheckInput).Start();
        }

        public void CheckInput()
        {
            while (true)
            {
                _lastKeyPressed = Console.ReadKey(true);
            }
        }
    }
}
