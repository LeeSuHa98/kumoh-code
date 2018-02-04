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
        public Rectangle() : base() { }
        public override string getType() { return "Rectangle from " + base.getType(); }
    }
    class Triangle : Shape
    {
        public Triangle() : base() { }
        public override string getType() { return "Triangle from " + base.getType(); }
    }
    class Circle : Shape
    {
        public Circle() : base() { }
        public override string getType() { return "Circle from " + base.getType(); }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Shape[] sList = new Shape[100];
            sList[0] = new Rectangle();
            sList[1] = new Triangle();
            sList[2] = new Circle();

            for(int i = 0; i < 1; i++)
            {
                Console.WriteLine(sList[i].getType());
            }
        }
    }
}
