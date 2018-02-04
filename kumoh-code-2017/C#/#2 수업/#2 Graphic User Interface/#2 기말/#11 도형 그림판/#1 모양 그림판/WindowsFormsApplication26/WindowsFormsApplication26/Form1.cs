using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication26
{
    public partial class Form1 : Form
    {
        private int shapeStyle = 0; // 0: Line, 1:Rectangle, 2:Ellipse

        private Point clickPos;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            clickPos = new Point(e.X, e.Y);
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            Graphics gHandle = CreateGraphics();

            Point nowPos = new Point(e.X, e.Y);
            Rectangle nowRect = new Rectangle(clickPos.X, clickPos.Y, nowPos.X - clickPos.X, nowPos.Y - clickPos.Y);

            if(shapeStyle == 0)
            {
                gHandle.DrawLine(Pens.Red, clickPos, nowPos);
            }
            else if (shapeStyle == 1)
            {
                gHandle.DrawRectangle(Pens.Red, nowRect);
            }
            else if (shapeStyle == 2)
            {
                gHandle.DrawEllipse(Pens.Red, nowRect);
            }

            gHandle.Dispose();
        }

        private void lineToolStripMenuItem_Click(object sender, EventArgs e)
        {
            shapeStyle = 0;
        }

        private void rectangleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            shapeStyle = 1;
        }

        private void ellipseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            shapeStyle = 2;
        }
    }
}
