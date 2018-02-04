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
                Console.Write("Reference String: ");
                string sentence = Console.ReadLine();
                Console.Write("Input Substring: ");
                string aLine = Console.ReadLine();

                int count = 0;
                int index = 0;

                //for(int i = 0; i < sentence.Length; i++)    // while(true)
                //{
                //    index = sentence.IndexOf(aLine, i); // index - 시작위치
                //                                        // 없으면 0부터 시작
                //    if (index >= 0)
                //    {
                //        count++;
                //        i = index+1;
                //    }
                //    else
                //    {
                //        break;
                //    }
                //}
                while(true)
                {
                    index = sentence.IndexOf(aLine, index); // index - 시작위치
                                                        // 없으면 0부터 시작
                    if(index >= 0)
                    {
                        count++;
                        index++;
                    }
                    else if(aLine == "exit")
                    {
                        break;
                    }
                    else
                    {
                        break;
                    }
                }

                Console.WriteLine("Count = " + count);

            }
        }
    }
}
