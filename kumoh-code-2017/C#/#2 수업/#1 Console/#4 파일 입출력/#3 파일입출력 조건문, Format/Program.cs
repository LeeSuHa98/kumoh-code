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
            StreamWriter sw = new StreamWriter("filename.txt");

            int strLine;
            int result;

            Console.Write("출력할 단을 입력 (0은 전체 출력) : ");
            strLine = int.Parse(Console.ReadLine());

            if (strLine == 0)
            {
                for (int i = 1; i <= 9; i++)
                {
                    for (int j = 1; j <= 9; j++)
                    {
                        //result = j * i;
                        //sw.Write("{0}*{1}={2}\t", j, i, result);
                        string aLine = string.Format("{0}*{1}={2,2}\t", j, i, i*j);
                        sw.Write(aLine);
                    }
                    sw.WriteLine();
                }
            }
            else
            {
                for (int i = 0; i <= 9; i++)
                {
                    //result = strLine * i;
                    //sw.WriteLine("{0} * {1} = {2}", strLine, i, result);
                    string aLine = string.Format("{0} * {1} = {2,2}", strLine, i, strLine * i);
                    sw.Write(aLine);
                }
            }

            sw.Close();

            StreamReader sr = new StreamReader("filename.txt");

            while (sr.Peek() >= 0)
            {
                string aLine = sr.ReadLine();
                for(int i = 0; i < aLine.Length; i++)
                {
                    if(aLine[i] == '3')
                    {
                        Console.WriteLine("*");
                    }
                }
            }

            //string doc = sr.ReadToEnd();

            //Console.WriteLine(doc);

            sr.Close();
        }
    }
}
