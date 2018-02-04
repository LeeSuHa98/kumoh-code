using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyClock
{
    public partial class MyClock : Form
    {
        bool state_start = false;
        public MyClock()
        {
            InitializeComponent();
            timer1.Start();
            state_start = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text = String.Format("{0}시 {1}분 {2}초", DateTime.Now.Hour, DateTime.Now.Minute, DateTime.Now.Second);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (state_start == true)
            {
                timer1.Stop();
                state_start = false;
            }

            else
            {
                timer1.Start();
                state_start = true;
            }
        }
    }
}
