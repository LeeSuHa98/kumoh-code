using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Omok
{
    public class board
    {
        private const int N = 19;
        private int[,] matrix = new int[N, N];

        public void putStone(int x, int y, int stone)
        {
            matrix[x, y] = stone;
        }
        public void removeStone(int x, int y)
        {
            matrix[x, y] = 0;
        }
        public int getStone(int x, int y)
        {
            return matrix[x, y];
        }
        public void display()
        {
            int x, y;
            Console.Write("↘ ");
            for (x = 0; x < N; x++)
            {
                Console.Write(x + " ");
            }
            Console.WriteLine();
            for (x = 0; x < N; x++)
            {
                Console.Write(" " + x);
                for (y = 0; y < N; y++)
                {
                    if (matrix[x, y] == 0) Console.Write("□");
                    else if (matrix[x, y] == 1) Console.Write("●");
                    else if (matrix[x, y] == 2) Console.Write("○");
                    else Console.Write("□");
                }
                Console.WriteLine();
            }
        }
        public void clear()
        {
            int x, y;
            for (x = 0; x < N; x++)
            {
                for (y = 0; y < N; y++)
                {
                    matrix[x, y] = 0;
                }
            }
        }
    }
}