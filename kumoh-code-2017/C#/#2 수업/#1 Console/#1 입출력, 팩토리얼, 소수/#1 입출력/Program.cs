﻿using System;
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
            while (true)
            {
                Console.WriteLine("Input Number? ");
                //string aLine = Console.ReadLine();
                //int num = Convert.ToInt32(aLine);
                //int num = int.Parse(aLine);
                int num = Convert.ToInt32(Console.ReadLine());

                if (num == -1)
                {
                    break;
                }
                if (num % 2 == 0)
                {
                    Console.WriteLine(num + " is Even");
                }
                else
                {
                    Console.WriteLine(num + " is Odd");
                }
            }
        }
    }
}
