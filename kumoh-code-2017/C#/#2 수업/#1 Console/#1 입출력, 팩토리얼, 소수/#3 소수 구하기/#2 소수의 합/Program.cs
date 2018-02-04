using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {
        bool isPrime(int num)
        {
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
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

            int sum = 0;

            for (int i = 2; i <= num; i++)
            {
                if (isPrime(i) == true)
                {
                    Console.Write(i + " ");
                    sum += i;
                }
            }
            Console.WriteLine("Sum of Prime Numbers = " + sum);
        }
        static void Main(string[] args)
        {
            Program p = new Program();

            p.run();
        }
    }
}
