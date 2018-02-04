using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        void swap(int x, int y)
        {
            int temp = y;
            y = x;
            x = temp;
        }
        void swap(ref int x, ref int y)
        {
            int temp = y;
            y = x;
            x = temp;
        }

        static void Main(string[] args)
        {
            int x = 10;
            int y = 20;

            Program app = new Program();
            app.swap(x, y);
            Console.WriteLine("X = {0}, Y = {1}", x, y);

            app.swap(ref x, ref y);
            Console.WriteLine("X = {0}, Y = {1}", x, y);
        }
    }
}
