using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        bool isPrime(int num)
        {
            for(int i = 2; i < num; i++)
            {
                if(num % 1 == 0)
                {
                    return false;
                }
             
            }
            return true;
        }
        void run()
        {
            Console.WriteLine("Input Number? ");
            int num = Convert.ToInt32(Console.ReadLine());

            for (int i = 2; i <= num; i++)
            {
                if (isPrime(i) == true)
                {
                    Console.WriteLine(i + " ");
                }
            }
            Console.WriteLine("");
        }
        static void Main(string[] args)
        {
            Program p = new Program();

            p.run();
        }
    }
}