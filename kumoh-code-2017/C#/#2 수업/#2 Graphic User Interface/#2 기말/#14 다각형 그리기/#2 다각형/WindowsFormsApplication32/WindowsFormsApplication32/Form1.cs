using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Collections;

namespace WindowsFormsApplication32
{
    public partial class Form1 : Form
    {
        private ArrayList points = new ArrayList();

        int shapeStyle = 0; // 0: Polygon, 1: Curve, 2: Spline

        private Color penColor = Color.Red;
        private int penWidth = 1;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            Pen rPen = new Pen(penColor, penWidth);
            Graphics gHandle = CreateGraphics();

            if (e.Button == MouseButtons.Left)
            {
                Point cp = new Point(e.X, e.Y);
                points.Add(cp);
            }
            else if(e.Button == MouseButtons.Right)
            {
                points.Clear();
            }

            if(points.Count > 1)
            {
                Point[] pointArray = (Point[])points.ToArray(points[0].GetType());
                gHandle.Clear(this.BackColor);
                gHandle.DrawPolygon(rPen, pointArray);
            }

            this.Invalidate();
        }

        private void resetToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics gHandle = e.Graphics;

            Pen rPen = new Pen(Color.Red);

            if (points.Count > 1)
            {
                Point[] pointArray = (Point[])points.ToArray(points[0].GetType());
                gHandle.Clear(this.BackColor);
                gHandle.DrawPolygon(rPen, pointArray);
            }

            rPen.Dispose();
            gHandle.Dispose();
        }
    }
}
