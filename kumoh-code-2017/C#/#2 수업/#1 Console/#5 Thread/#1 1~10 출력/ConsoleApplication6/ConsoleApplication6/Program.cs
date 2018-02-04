using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ConsoleApplication6
{
    class Program
    {
        static void Main(string[] args)
        {
            Program app = new Program();

            Thread thread = new Thread(new ThreadStart(app.threadFunc));
            thread.Start();

            //for (int i = 1; i <= 10; i++)
            //{
            //    Console.WriteLine("{0} ", i);
            //}

            Console.WriteLine("Program Exit");
        }

        public void threadFunc()
        {
            Console.WriteLine("Thread Start");
            for(int i = 1; i <= 10; i++)
            {
                Console.WriteLine("{0} ", i);
            }
            Console.WriteLine("Thread End\n");
        }
    }
}
