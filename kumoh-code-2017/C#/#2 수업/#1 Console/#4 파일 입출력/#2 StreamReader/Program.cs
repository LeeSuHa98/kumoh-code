using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamWriter sw = new StreamWriter("filename.txt");

            //int strLine;
            //Console.Write("출력할 구구단 번호를 입력하세요 : ");
            //strLine = int.Parse(Console.ReadLine());
            //for (int i = 1; i < 10; i++)
            //{
            //    sw.WriteLine("{0} * {1} = {2,2}", strLine, i, strLine * i);
            //}

            //sw.Close();

            StreamReader sr = new StreamReader("filename.txt");

            //while(sr.Peek() >= 0)
            //{
            //    string strLine = sr.ReadLine();
            //}

            string doc = sr.ReadToEnd();

            Console.WriteLine(doc);

            sr.Close();
        }
    }
}
