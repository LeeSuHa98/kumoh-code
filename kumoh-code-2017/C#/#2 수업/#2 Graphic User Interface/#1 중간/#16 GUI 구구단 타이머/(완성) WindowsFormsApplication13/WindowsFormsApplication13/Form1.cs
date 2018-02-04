using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication13
{
    public partial class Form1 : Form
    {
        Random r = new Random();

        public Form1()
        {
            InitializeComponent();
            timer1.Interval = 1000;
            timer1.Start();
            textBox1.Text = "2";
            textBox2.Text = Convert.ToString((r.Next() % 9) + 1);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 게임 재시작
            label6.Text = "0";
            label7.Text = "0";
            label8.Text = "5";
            listBox1.Items.Clear();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox1.Text = comboBox1.Text;
            label8.Text = "5";
        }

        private void 종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // 프로그램 종료
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int result = Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text);

            if (result != Convert.ToInt32(textBox3.Text))
            {
                listBox1.Items.Add("시간 " + DateTime.Now.ToString("HH:mm:ss") + " 실패 " + textBox1.Text + "x" + textBox2.Text + "=" + Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text));
                int WCnt = Convert.ToInt32(label7.Text);
                WCnt++;
                label7.Text = Convert.ToString(WCnt);
                label8.Text = "5";
                textBox2.Text = Convert.ToString((r.Next() % 9) + 1);

            }
            else
            {
                listBox1.Items.Add("시간 " + DateTime.Now.ToString("HH:mm:ss") + " 성공 " + textBox1.Text + "x" + textBox2.Text + "=" + Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text));
                int CCnt = Convert.ToInt32(label6.Text);
                CCnt++;
                label6.Text = Convert.ToString(CCnt);
                label8.Text = "5";
                textBox2.Text = Convert.ToString((r.Next() % 9) + 1);

            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int timeCount = (Convert.ToInt32(label8.Text)) - 1;
            label8.Text = Convert.ToString(timeCount);
            int tmpCnt = Convert.ToInt32(label7.Text);

            if (label8.Text == "-1")
            {
                label8.Text = "5";
                tmpCnt++;
                label7.Text = Convert.ToString(tmpCnt);

                listBox1.Items.Add("시간 " + DateTime.Now.ToString("HH:mm:ss") + " 실패 " + textBox1.Text + "x" + textBox2.Text + "=" + Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text));
                textBox2.Text = Convert.ToString((r.Next() % 9) + 1);
            }
        }
    }
}
