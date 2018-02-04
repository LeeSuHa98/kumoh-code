using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication30
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Graphics gHandle = this.screenButton.CreateGraphics();

            Random random = new Random();

            int size = random.Next(100);
            int x = random.Next(startButton.Size.Width);
            int y = random.Next(startButton.Size.Height);

            Color c = Color.FromArgb(random.Next(255), random.Next(255), random.Next(255));
            SolidBrush myBrush = new SolidBrush(c);

            gHandle.FillEllipse(myBrush, x, y, size, size);

            myBrush.Dispose();
            gHandle.Dispose();
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
        }

        private void endButton_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;
        }
    }
}
