using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                Console.Write("Input String: ");
                string refStr = "Hello";
                string cmpStr = Console.ReadLine();
                if(cmpStr == "exit")
                {
                    break;
                }

                int cmpVal = cmpStr.CompareTo(refStr);
                if (cmpVal > 0)
                {
                    Console.WriteLine(cmpStr + " > " + refStr);
                }
                else if (cmpVal < 0)
                {
                    Console.WriteLine(cmpStr + " < " + refStr);
                }
                else
                {
                    Console.WriteLine(cmpStr + " = " + refStr);
                }
            }
        }
    }
}
