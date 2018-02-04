using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication5
{
    public partial class Form1 : Form
    {
        private bool clicked = false;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (clicked == true)
            {
                Graphics graphics = CreateGraphics();
                graphics.FillEllipse(new SolidBrush(Color.FromName(comboBox1.Text)), e.X, e.Y, 4, 4);

                //switch(comboBox1.Text)
                //{
                //    case "Red":
                //        graphics.FillEllipse(new SolidBrush(Color.Red), e.X, e.Y, 4, 4);
                //    case "Green":
                //        graphics.FillEllipse(new SolidBrush(Color.Green), e.X, e.Y, 4, 4);
                //    case "Blue":
                //        graphics.FillEllipse(new SolidBrush(Color.Blue), e.X, e.Y, 4, 4);
                //    case "Yellow":
                //        graphics.FillEllipse(new SolidBrush(Color.Yellow), e.X, e.Y, 4, 4);
                //}
                graphics.Dispose();
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            clicked = true;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            clicked = false;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
