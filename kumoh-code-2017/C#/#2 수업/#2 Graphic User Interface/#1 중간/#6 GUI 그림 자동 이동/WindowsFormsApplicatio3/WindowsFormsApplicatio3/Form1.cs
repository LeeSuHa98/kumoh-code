using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplicatio3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void timer1_Tick_2(object sender, EventArgs e)
        {
            Image temp = pictureBox3.Image;
            pictureBox3.Image = pictureBox2.Image;
            pictureBox2.Image = pictureBox1.Image;
            pictureBox1.Image = temp;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Stop();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            timer1.Interval = (int)numericUpDown1.Value;
        }
    }
}
