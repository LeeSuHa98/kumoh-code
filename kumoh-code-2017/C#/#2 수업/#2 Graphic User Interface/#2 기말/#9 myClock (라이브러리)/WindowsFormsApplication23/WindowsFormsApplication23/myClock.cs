using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication23
{
    public partial class myClock : Form
    {
        bool buttonClicked = false;
        public myClock()
        {
            InitializeComponent();
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            DateTime nowTime = DateTime.Now;

            string timeSTR;

            if (buttonClicked == true)
            {
                timeSTR = string.Format("오후 {0}시 {1}분 {2} 초", nowTime.Hour, nowTime.Minute, nowTime.Second);
                timeLabel.Text = timeSTR;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(buttonClicked == false)
            {
                timer1.Start();
                buttonClicked = true;
            }
            else if(buttonClicked == true)
            {
                timer1.Stop();
                buttonClicked = false;
            }
        }
    }
}

