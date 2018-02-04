using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Input Number? ");
            string aLine = Console.ReadLine();
            int num = int.Parse(aLine);
            int result = num;

            for (int i = 1; i < num; i++)
            {
                result = result * i;
            }

            aLine = result.ToString();

            Console.WriteLine(aLine);
        }
    }
}
