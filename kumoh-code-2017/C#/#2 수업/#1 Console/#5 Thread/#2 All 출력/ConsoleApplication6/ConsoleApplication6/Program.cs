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

            Console.WriteLine("Number Of Logical Processors: {0}", Environment.ProcessorCount);

            Thread[] thread = new Thread[Environment.ProcessorCount];

            for(int i = 0; i < Environment.ProcessorCount; i++)
            {
                thread[i] = new Thread(new ThreadStart(app.threadFunc));
                thread[i].Start();
            }

            Console.WriteLine("All Thread Started");
        }

        public void threadFunc()
        {
            while(true)
            {
                ;
            }
        }
    }
}
