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
        int ccnt = 0;
        int wcnt = 0;
        int t = 5;

        public Form1()
        {
            InitializeComponent();
            timer1.Start();
            label6.Text = Convert.ToString(ccnt);
            label7.Text = Convert.ToString(wcnt);
        }

        private void make_random()
        {
            Random r = new Random();
            r.Next();
            textBox2.Text = Convert.ToString(r.Next(1, 10));
            textBox3.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 게임 재시작
            ccnt = 0;
            wcnt = 0;
            label6.Text = Convert.ToString(ccnt);
            label7.Text = Convert.ToString(wcnt);
            label8.Text = Convert.ToString(t);
            make_random();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(comboBox1.SelectedItem);
            make_random();
        }

        private void 종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // 프로그램 종료
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int result = Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text);

            if(Convert.ToInt32(textBox3.Text) == result)
            {
                ccnt++;
                label6.Text = Convert.ToString(ccnt);
                listBox1.Items.Add("시간 " + DateTime.Now.ToString("hh:mm:ss") + " 성공 " + textBox1.Text + "x" + textBox2.Text + "=" + result);
                label8.Text = Convert.ToString(t);
            }
            else
            {
                wcnt++;
                label7.Text = Convert.ToString(wcnt);
                listBox1.Items.Add("시간 " + DateTime.Now.ToString("hh:mm:ss") + " 성공 " + textBox1.Text + "x" + textBox2.Text + "=" + result);
                label8.Text = Convert.ToString(t);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label8.Text = Convert.ToString(Convert.ToInt32(label8.Text) - 1);
            if (Convert.ToInt32(label8.Text) == 0)
            {
                int result = Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text);
                wcnt++;
                label7.Text = Convert.ToString(wcnt);
                listBox1.Items.Add("시간 " + DateTime.Now.ToString("hh:mm:ss") + " 실패 " + textBox1.Text + "x" + textBox2.Text + "=" + result);
                make_random();
                label8.Text = Convert.ToString(t);
            }
        }
    }
}
