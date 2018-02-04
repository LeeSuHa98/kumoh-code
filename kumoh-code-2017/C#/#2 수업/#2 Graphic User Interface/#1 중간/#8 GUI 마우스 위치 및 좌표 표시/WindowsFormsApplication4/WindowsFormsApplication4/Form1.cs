using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            textBox1.Text = string.Format("X : {0}, Y : {1}", e.X, e.Y);
        }

        private void listBox1_MouseClick(object sender, MouseEventArgs e)
        {
            string str = null;

            if(e.Button == MouseButtons.Left)
            {
                listBox1.Items.Add(string.Format("Left X : {0}, Y : {1}", e.X, e.Y));
            }
            else if(e.Button == MouseButtons.Right)
            {
                listBox1.Items.Add(string.Format("Right X : {0}, Y : {1}", e.X, e.Y));
            }
        }
    }
}
