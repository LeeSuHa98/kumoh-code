using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication7
{
    public partial class Form1 : Form
    {
        int catchCount = 0;

        Random r = new Random();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Interval = 1000;

            timer1.Start();

            catchCount = 0;
            label2.Text = catchCount.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Stop();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

            button3.Show();

            int x = r.Next() % (this.Size.Width - button3.Size.Width);
            int y = r.Next() % (this.Size.Height - button3.Size.Width);

            this.button3.Location = new Point(x, y);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if(timer1.Enabled == true)
            {
                catchCount = catchCount + 1;
                label2.Text = catchCount.ToString();
                button3.Hide();
            }
        }
    }
}
