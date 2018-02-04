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


        private void button_MouseDown(object sender, MouseEventArgs e)
        {
            if (sender is Button)
            {
                Button b = (Button)sender;

                //b.BackColor = Color.Red;
                if(b.Equals(button1))
                {
                    Beep(262, 1000);    // 도
                    button1.BackColor = Color.Red;
                }
                else if (b.Equals(button2))
                {
                    Beep(294, 1000);    // 레
                    button2.BackColor = Color.Red;
                }
                else if (b.Equals(button3))
                {
                    Beep(330, 1000);    // 미
                    button3.BackColor = Color.Red;
                }
                else if(b.Equals(button4))
                {
                    Beep(360, 1000);    // 파
                    button4.BackColor = Color.Red;
                }
                else if(b.Equals(button5))
                {
                    Beep(392, 1000);    // 솔
                    button5.BackColor = Color.Red;
                }
                else if (b.Equals(button6))
                {
                    Beep(440, 1000);    // 라
                    button6.BackColor = Color.Red;
                }
                else if (b.Equals(button7))
                {
                    Beep(494, 1000);    // 시
                    button7.BackColor = Color.Red;
                }
                else if (b.Equals(button8))
                {
                    Beep(524, 1000);    // 도
                    button8.BackColor = Color.Red;
                }
            }
        }

        private void button_MouseUp(object sender, MouseEventArgs e)
        {
            if (sender is Button)
            {
                Button b = (Button)sender;

                b.BackColor = Color.White;
            }
        }

        //private void button1_MouseDown(object sender, MouseEventArgs e)
        //{
        //    Beep(262, 1000);    // 도
        //    button1.BackColor = Color.Red;
        //}

        //private void button2_MouseDown(object sender, MouseEventArgs e)
        //{
        //    Beep(294, 1000);    // 레
        //    button2.BackColor = Color.Red;
        //}

        //private void button3_MouseDown(object sender, MouseEventArgs e)
        //{
        //    Beep(330, 1000);    // 미
        //    button3.BackColor = Color.Red;
        //}

        //private void button1_MouseUp(object sender, MouseEventArgs e)
        //{
        //    button1.BackColor = Color.White;
        //}

        //private void button2_MouseUp(object sender, MouseEventArgs e)
        //{
        //    button2.BackColor = Color.White;
        //}

        //private void button3_MouseUp(object sender, MouseEventArgs e)
        //{
        //    button3.BackColor = Color.White;
        //}

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyValue)
            {
                case '1':
                    Beep(262, 100);
                    button1.BackColor = Color.Red;
                    break;
                case '2':
                    Beep(294, 100);
                    button2.BackColor = Color.Red;
                    break;
                case '3':
                    Beep(330, 100);
                    button3.BackColor = Color.Red;
                    break;
                case '4':
                    Beep(360, 100);
                    button4.BackColor = Color.Red;
                    break;
                case '5':
                    Beep(392, 100);
                    button5.BackColor = Color.Red;
                    break;
                case '6':
                    Beep(440, 100);
                    button6.BackColor = Color.Red;
                    break;
                case '7':
                    Beep(494, 100);
                    button7.BackColor = Color.Red;
                    break;
                case '8':
                    Beep(524, 100);
                    button8.BackColor = Color.Red;
                    break;
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            switch (e.KeyValue)
            {
                case '1':
                    button1.BackColor = Color.White;
                    break;
                case '2':
                    button2.BackColor = Color.White;
                    break;
                case '3':
                    button3.BackColor = Color.White;
                    break;
                case '4':
                    button4.BackColor = Color.White;
                    break;
                case '5':
                    button5.BackColor = Color.White;
                    break;
                case '6':
                    button6.BackColor = Color.White;
                    break;
                case '7':
                    button7.BackColor = Color.White;
                    break;
                case '8':
                    button8.BackColor = Color.White;
                    break;
            }
        }
    }
}
