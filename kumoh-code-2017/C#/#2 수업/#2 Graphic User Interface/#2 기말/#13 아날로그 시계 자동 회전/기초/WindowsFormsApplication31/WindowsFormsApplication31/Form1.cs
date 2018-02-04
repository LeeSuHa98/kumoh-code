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

        public Form1()
        {
            InitializeComponent();
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            DateTime now = DateTime.Now;

            //theta = now.Second * 6 - 90;
            //theta = now.Hour * 30 - 90;

            int radius = 150;
            int cx = this.Size.Width / 2;
            int cy = this.Size.Height / 2;

            int nX = (int)(Math.Cos(theta * 3.14 / 180.0) * radius) + cx;
            int nY = (int)(Math.Sin(theta * 3.14 / 180.0) * radius) + cy;

            Graphics g = CreateGraphics();
            g.Clear(this.BackColor);
            g.DrawLine(Pens.Red, cx, cy, nX, nY);
            g.Dispose();

            if(checkBox1.Checked == true)
            {
                theta++;
            }
            else
            {
                theta--;
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
