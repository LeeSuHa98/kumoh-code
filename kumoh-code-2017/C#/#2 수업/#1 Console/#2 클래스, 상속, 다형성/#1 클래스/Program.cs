using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Student
    {
        private int korean;
        private int math;
        private int english;

        public void setScore(int korean, int math, int english) { this.korean = korean; this.math = math; this.english = english; }
        public int getAverage()
        {
            return (korean + math + english) / 3;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Student[] sList = new Student[3];

            int korean = 0;
            int math = 0;
            int english = 0;

            for(int i = 0; i < 3; i++)
            {
                Console.WriteLine("Student[0]", i);
                Console.Write("Korean? ");
                korean = Convert.ToInt32(Console.ReadLine());

                Console.Write("math? ");
                math = Convert.ToInt32(Console.ReadLine());

                Console.Write("english? ");
                english = Convert.ToInt32(Console.ReadLine());

                sList[i] = new Student();
              
                sList[i].setScore(korean, math, english);
            }
            for (int i = 0; i < 3; i++)
            {
                int result = sList[i].getAverage();

                Console.WriteLine("Student " + i + " Average = " + result);
            }
        }
    }
}
