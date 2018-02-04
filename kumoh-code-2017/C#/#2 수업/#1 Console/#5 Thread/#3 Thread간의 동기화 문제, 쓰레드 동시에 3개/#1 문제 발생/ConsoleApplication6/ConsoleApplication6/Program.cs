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

            Thread[] thread = new Thread[3];

            for(int i = 0; i < 3; i++)
            {
                thread[i] = new Thread(new ThreadStart(app.incValue));
                thread[i].Name = (i+1).ToString();
                thread[i].Start();
            }

            Console.WriteLine("Program Exit");
        }

        public void incValue()
        {
            Thread current = Thread.CurrentThread;

            Console.WriteLine("Thread Start");
            for (int i = 0; i < 10; i ++)
            {
                Console.WriteLine("{0} prints {1}", current.Name, i);
            }
            Console.WriteLine("Thread End\n");
        }
    }
}

