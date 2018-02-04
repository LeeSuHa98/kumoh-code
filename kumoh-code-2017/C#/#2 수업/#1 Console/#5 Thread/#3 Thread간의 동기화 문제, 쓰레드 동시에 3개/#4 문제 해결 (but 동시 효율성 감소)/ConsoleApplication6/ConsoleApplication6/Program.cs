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
        private int value = 0;

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

        Random r = new Random();

        public void incValue()
        {
            Thread current = Thread.CurrentThread;

            lock(this)
            {
                Console.WriteLine("Thread Start");
                for (int i = 0; i < 10; i++)
                {
                    int copyValue = value;
                    Thread.Sleep(r.Next(100));  // 잠시 휴식
                    Console.WriteLine("{0} prints {1}", current.Name, copyValue++);
                    value++;
                }
                Console.WriteLine("Thread End\n");
            }
        }
    }
}

