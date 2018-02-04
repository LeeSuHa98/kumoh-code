using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Input String: ");
            string str = Console.ReadLine();

            Console.Write("Reverse String: ");
            for (int i = str.Length - 1; i >= 0; i--)
            {
                Console.Write(str[i]);
                Console.Write(" ");
            }
            Console.WriteLine();
        }
    }
}
