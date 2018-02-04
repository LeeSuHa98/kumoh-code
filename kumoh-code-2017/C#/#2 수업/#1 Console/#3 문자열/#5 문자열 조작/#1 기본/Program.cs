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
            Console.Write("Reference String: ");
            string alphabet = Console.ReadLine();

            StringBuilder sentence = new StringBuilder(alphabet);

            for (int i = 0; i < sentence.Length; i += 2)
            {
                sentence[i] = '*';
            }

            Console.WriteLine(sentence);
        }
    }
}
