using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        void studentAvg()
        {
            int[] score = new int[3];
            int korean = 0;
            int math = 0;
            int english = 0;


            for(int i = 0; i < 3; i++)
            {
                Console.WriteLine("Student {0} ", i);

                Console.Write("Korean? ");
                korean = Convert.ToInt32(Console.ReadLine());

                Console.Write("math? ");
                math = Convert.ToInt32(Console.ReadLine());

                Console.Write("english? ");
                english = Convert.ToInt32(Console.ReadLine());

                score[i] = (korean + math + english) / 3;
            }

            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine("Student {0} Average = {1} ", i, score[i]);
            }
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            p.studentAvg();
        }
    }
}
