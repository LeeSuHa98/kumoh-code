using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        void calculate()
        {
            while (true)
            {
                Console.Write("Input Equation: ");
                string aLine = Console.ReadLine();

                if (aLine == "exit")
                    break;

                string delimiter = " ";
                string[] item = aLine.Split(delimiter.ToCharArray());

                int num1 = Convert.ToInt32(item[0]);
                int num2 = Convert.ToInt32(item[2]);

                Console.Write("Answer: ");

                switch (item[1])
                {
                    case "+":
                        Console.WriteLine(num1 + num2);
                        break;
                    case "-":
                        Console.WriteLine(num1 - num2);
                        break;
                    case "*":
                        Console.WriteLine(num1 * num2);
                        break;
                    case "/":
                        Console.WriteLine(num1 / num2);
                        break;
                }
            }
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            p.calculate();
        }
    }
}
