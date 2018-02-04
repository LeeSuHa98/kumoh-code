using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Shape
    {
        public string getType() { return "Shaep"; }
    }
    class Rectangle : Shape
    {
        public string getType() { return "Rectangle"; }
    }
    class Triangle : Shape
    {
        public string getType() { return "Triangle"; }
    }
    class Circle : Shape
    {
        public string getType() { return "Circle"; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Rectangle r = new Rectangle();
            Triangle t = new Triangle();
            Circle c = new Circle();

            Console.WriteLine(r.getType());
            Console.WriteLine(t.getType());
            Console.WriteLine(c.getType());
        }
    }
}
