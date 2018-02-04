using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace WindowsFormsApplication29
{
    public partial class Form1 : Form
    {
        private int shapeStyle = 0; // 0: Line, 1:Rectangle, 2:Ellipse

        private Color penColor = Color.Red;
        private int penStyle = 0;   // 0: Solid, 1: Dot, 2: Dash Dot
        private int penWidth = 1;

        private Color brushColor1 = Color.Red;
        private Color brushColor2 = Color.Green;
        private int brushStyle = 0; // 0: Solid, 1: Hatch, 2: Linear Gradient, 3: Texture

        private Point clickPos;

        public Form1()
        {
            InitializeComponent();
        }

        private void solidToolStripMenuItem_Click(object sender, EventArgs e)
        {
            penStyle = 0;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            Graphics gHandle = CreateGraphics();

            Point nowPos = new Point(e.X, e.Y);
            Rectangle nowRect = new Rectangle(clickPos.X, clickPos.Y, nowPos.X - clickPos.X, nowPos.Y - clickPos.Y);

            Pen dPen = new Pen(penColor, penWidth);

            if (penStyle == 0)
            {
                dPen.DashStyle = DashStyle.Solid;
            }
            else if (penStyle == 1)
            {
                dPen.DashStyle = DashStyle.Dot;
            }
            else if (penStyle == 2)
            {
                dPen.DashStyle = DashStyle.DashDot;
            }

            Brush dBrush = null;

            if (brushStyle == 0)
            {
                dBrush = new SolidBrush(brushColor1);
            }
            else if (brushStyle == 1)
            {
                dBrush = new HatchBrush(HatchStyle.Vertical, brushColor1, brushColor2);
            }
            else if (brushStyle == 2)
            {
                dBrush = new LinearGradientBrush(nowRect, brushColor1, brushColor2, LinearGradientMode.Horizontal);
            }
            else if (brushStyle == 3)
            {
                Image myImage = Image.FromFile("d:/lenna.jpg");
                dBrush = new TextureBrush(myImage);
            }

            if (shapeStyle == 0)
            {
                gHandle.DrawLine(dPen, clickPos, nowPos);
            }
            else if (shapeStyle == 1)
            {
                gHandle.DrawRectangle(dPen, nowRect);
            }
            else if (shapeStyle == 2)
            {
                gHandle.DrawEllipse(dPen, nowRect);
            }
            else if(shapeStyle == 3)
            {
                gHandle.FillRectangle(dBrush, nowRect);
            }
            else if (shapeStyle == 4)
            {
                gHandle.FillEllipse(dBrush, nowRect);
            }

            dBrush.Dispose();
            dPen.Dispose();
            gHandle.Dispose();
        }


        private void dotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            penStyle = 1;
        }

        private void dashDotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            penStyle = 2;
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

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            clickPos = new Point(e.X, e.Y);
        }

        private void penColorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog cDlg = new ColorDialog();

            cDlg.Color = penColor;

            if (cDlg.ShowDialog() == DialogResult.OK)
            {
                penColor = cDlg.Color;
            }
        }

        private void toolStripTextBox1_TextChanged(object sender, EventArgs e)
        {
            penWidth = Convert.ToInt32(toolStripTextBox1.Text);
        }

        private void solidToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            brushStyle = 0;
        }

        private void hatchToolStripMenuItem_Click(object sender, EventArgs e)
        {
            brushStyle = 1;
        }

        private void linearGradientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            brushStyle = 2;
        }

        private void textureToolStripMenuItem_Click(object sender, EventArgs e)
        {
            brushStyle = 3;
        }

        private void brushColorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog cDlg = new ColorDialog();

            cDlg.Color = brushColor1;

            if (cDlg.ShowDialog() == DialogResult.OK)
            {
                brushColor1 = cDlg.Color;
            }
        }

        private void brushColor2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog cDlg = new ColorDialog();

            cDlg.Color = brushColor2;

            if (cDlg.ShowDialog() == DialogResult.OK)
            {
                brushColor2 = cDlg.Color;
            }
        }

        private void rectangleFieldToolStripMenuItem_Click(object sender, EventArgs e)
        {
            shapeStyle = 3;
        }

        private void ellipseFieldToolStripMenuItem_Click(object sender, EventArgs e)
        {
            shapeStyle = 4;
        }
    }
}
