using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Runtime.InteropServices;

namespace WindowsFormsApplication6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("kernel32.dll")]
        public static extern bool Beep(int n, int m);   // n은 주파수, m은 소리내는 시간(단위: 1/1000초)

        private void button1_MouseDown(object sender, MouseEventArgs e)
        {
            if(sender is Button)
            {
                Button b = (Button)sender;

                b.BackColor = Color.Red;
                Beep(262, 1000);    // 도
            }
        }

        private void button2_MouseDown(object sender, MouseEventArgs e)
        {
            button2.BackColor = Color.Red;
            Beep(294, 1000);    // 레
        }

        private void button3_MouseDown(object sender, MouseEventArgs e)
        {
            button3.BackColor = Color.Red;
            Beep(330, 1000);    // 미
        }

        private void button1_MouseUp(object sender, MouseEventArgs e)
        {
            if(sender is Button)
            {
                Button b = (Button)sender;

                b.BackColor = Color.White;
            }
        }

        private void button2_MouseUp(object sender, MouseEventArgs e)
        {
            button2.BackColor = Color.White;
        }

        private void button3_MouseUp(object sender, MouseEventArgs e)
        {
            button3.BackColor = Color.White;
        }
    }
}
