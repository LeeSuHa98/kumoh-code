using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Shape
    {
        public virtual string getType() { return "Shaep"; }
    }
    class Rectangle : Shape
    {
        public override string getType() { return "Rectangle"; }
    }
    class Triangle : Shape
    {
        public override string getType() { return "Triangle"; }
    }
    class Circle : Shape
    {
        public override string getType() { return "Circle"; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Shape[] sList = new Shape[100];
            sList[0] = new Rectangle();
            sList[1] = new Triangle();
            sList[2] = new Circle();

            for(int i = 0; i < 3; i++)
            {
                Console.WriteLine("Shape{0} is Circle" , i);
                Console.WriteLine("Shape{0} is Triangle", i);
                Console.WriteLine("Shape{0} is Rectangle", i);
            }
        }
    }
}
