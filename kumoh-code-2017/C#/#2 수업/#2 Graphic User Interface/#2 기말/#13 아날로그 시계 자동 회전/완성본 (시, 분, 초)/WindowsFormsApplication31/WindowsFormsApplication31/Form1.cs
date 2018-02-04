using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication31
{
    public partial class Form1 : Form
    {
        private double theta = 0;
        private double secondTheta = 0;
        private double minuteTheta = 0;
        private double hourTheta = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            DateTime now = DateTime.Now;

            int cx = this.Size.Width / 2;
            int cy = this.Size.Height / 2;

            int radius = 150;

            int nX = (int)(Math.Cos(theta * 3.14 / 180.0) * radius) + cx;
            int nY = (int)(Math.Sin(theta * 3.14 / 180.0) * radius) + cy;

            Graphics g = CreateGraphics();
            g.Clear(this.BackColor);
            g.DrawLine(Pens.Red, cx, cy, nX, nY);
            g.Dispose();

            int minuteRadius = 150;

            int nX1 = (int)(Math.Cos(minuteTheta * 3.14 / 180.0) * minuteRadius) + cx;
            int nY1 = (int)(Math.Sin(minuteTheta * 3.14 / 180.0) * minuteRadius) + cy;

            Graphics g1 = CreateGraphics();
            g1.DrawLine(Pens.Green, cx, cy, nX1, nY1);
            g1.Dispose();


            int secondRadius = 50;

            int nX2 = (int)(Math.Cos(secondTheta * 3.14 / 180.0) * secondRadius) + cx;
            int nY2 = (int)(Math.Sin(secondTheta * 3.14 / 180.0) * secondRadius) + cy;

            Graphics g2 = CreateGraphics();
            g2.DrawLine(Pens.Blue, cx, cy, nX2, nY2);
            g2.Dispose();

            int hourRadius = 70;

            int nX3 = (int)(Math.Cos(hourTheta * 3.14 / 180.0) * hourRadius) + cx;
            int nY3 = (int)(Math.Sin(hourTheta * 3.14 / 180.0) * hourRadius) + cy;

            Graphics g3 = CreateGraphics();
            g3.DrawLine(Pens.Yellow, cx, cy, nX3, nY3);
            g3.Dispose();

            if (checkBox1.Checked == true)
            {
                theta++;
                secondTheta = now.Second * 6 - 90;
                minuteTheta = now.Minute * 6 - 90;
                hourTheta = now.Hour * 30 - 90;
            }
            else
            {
                theta--;
                secondTheta = now.Second * -6 + 270;
                minuteTheta = now.Minute * -6 + 270;
                hourTheta = now.Hour * -30 + 270;
            }
        }

        private void endButton_Click(object sender, EventArgs e)
        {
            timer1.Stop();
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }
    }
}
