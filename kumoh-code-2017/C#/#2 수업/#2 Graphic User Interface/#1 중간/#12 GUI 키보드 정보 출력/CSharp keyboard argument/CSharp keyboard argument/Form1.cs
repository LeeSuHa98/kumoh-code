using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharp_keyboard_argument
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            label2.Text = "Key Pressed: " + e.KeyChar;
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            label2.Text = " ";
            label4.Text = " ";
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            label4.Text =
                "Alt: " + (e.Alt ?)
        }
    }
}
