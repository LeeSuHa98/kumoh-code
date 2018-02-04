using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Shape
    {
        public virtual double getSize() { return -1.0; }
    }

    class Rectangle : Shape
    {
        int width;
        int height;

        public Rectangle(int width, int height)
        {
            this.width = width;
            this.height = height;
        }

        override public double getSize()
        {
            return (double)(width * height);
        }
    }

    class Triangle : Shape
    {
        int width;
        int height;

        public Triangle(int width, int height)
        {
            this.width = width;
            this.height = height;
        }

        override public double getSize()
        {
            return 0.5 * width * height;
        }
    }

    class Circle : Shape
    {
        int radius;

        public Circle(int radius)
        {
            this.radius = radius;
        }

        override public double getSize()
        {
            return 3.14 * radius * radius;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Shape[] shapeList = new Shape[100];
            int shapeCount = 0;

            char[] delimiter = { ',' };
            while (true)
            {
                Console.Write("Select Action(1. Input Object  2. Show Size  3. Exit)? ");
                int menuID = Convert.ToInt32(Console.ReadLine());
                switch (menuID)
                {
                    case 1:
                        Console.Write("Select Object(1. Triangle  2. Rectangle  3. Circle)? ");
                        int shapeID = Convert.ToInt32(Console.ReadLine());
                        switch (shapeID)
                        {
                            case 1:
                                {
                                    Console.Write("Input Size(width, height) : ");
                                    string aLine = Console.ReadLine();
                                    string[] item = aLine.Split(delimiter);
                                    int width = Convert.ToInt32(item[0]);
                                    int height = Convert.ToInt32(item[1]);

                                    shapeList[shapeCount] = new Triangle(width, height);
                                    shapeCount++;
                                }
                                break;

                            case 2:
                                {
                                    Console.Write("Input Size(width, height) : ");
                                    string aLine = Console.ReadLine();
                                    string[] item = aLine.Split(delimiter);
                                    int width = Convert.ToInt32(item[0]);
                                    int height = Convert.ToInt32(item[1]);

                                    shapeList[shapeCount] = new Rectangle(width, height);
                                    shapeCount++;
                                }
                                break;

                            case 3:
                                {
                                    Console.Write("Input Size(radius) : ");
                                    int rad = Convert.ToInt32(Console.ReadLine());

                                    shapeList[shapeCount] = new Circle(rad);
                                    shapeCount++;
                                }
                                break;
                        }
                        Console.WriteLine("");

                        break;

                    case 2:
                        for (int i = 0; i < shapeCount; i++)
                        {
                            if (shapeList[i] is Triangle)
                            {
                                Console.WriteLine("Object #{0} is Triangle and its size is {1}", i, shapeList[i].getSize());
                            }
                            else if (shapeList[i] is Rectangle)
                            {
                                Console.WriteLine("Object #{0} is Rectangle and its size is {1}", i, shapeList[i].getSize());
                            }
                            else if (shapeList[i] is Circle)
                            {
                                Console.WriteLine("Object #{0} is Circle and its size is {1}", i, shapeList[i].getSize());
                            }
                        }

                        Console.WriteLine("");

                        break;

                    case 3:
                        Console.WriteLine("종료합니다.");

                        return;
                }
            }
        }
    }
}
