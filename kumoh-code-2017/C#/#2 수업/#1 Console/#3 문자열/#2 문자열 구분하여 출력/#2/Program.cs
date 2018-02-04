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
            Console.Write("Input String: ");
            string delimiter = " ,";
            string str = Console.ReadLine();
            string[] item = str.Split(delimiter.ToCharArray());

            Console.Write("String : ");
            for(int i = 0; i < item.Length; i++)
            {
                Console.WriteLine("String {0} = {1}", i, item[i]);
            }
            Console.WriteLine();
        }
    }
}
