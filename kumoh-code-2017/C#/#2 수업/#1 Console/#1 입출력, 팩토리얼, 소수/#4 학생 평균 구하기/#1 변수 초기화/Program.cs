using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        void StudentAvg()
        {
            int korean = 0;
            int math = 0;
            int english = 0;
            Console.WriteLine("Korean? ");
            korean = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Math? ");
            math = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("English? ");
            english = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Average = " + (korean + math + english) / 3);
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            p.StudentAvg();

        }
    }
}
