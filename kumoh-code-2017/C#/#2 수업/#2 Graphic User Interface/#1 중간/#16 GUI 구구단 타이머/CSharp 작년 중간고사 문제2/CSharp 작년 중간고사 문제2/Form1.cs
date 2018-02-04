using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharp_작년_중간고사_문제2
{
    public partial class Form1 : Form
    {

        Random r = new Random();
        public Form1()
        {
            InitializeComponent();
            timer1.Start();
            textBox1.Text = "2";
            textBox2.Text = Convert.ToString((r.Next() % 9) + 1);
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            label2.Text = "5";
            label7.Text = "0";
            label8.Text = "0";
            listBox1.Items.Clear();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox1.Text = comboBox1.Text;
            label2.Text = "5";
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
          
            int timeCount = (Convert.ToInt32(label2.Text))-1;
            label2.Text = Convert.ToString(timeCount);
            int tmpCnt= Convert.ToInt32(label8.Text);

           if (label2.Text=="-1")
            {
                label2.Text = "5";
                tmpCnt++;
                label8.Text = Convert.ToString(tmpCnt);

                listBox1.Items.Add("시간 " + DateTime.Now.ToString("HH:mm:ss") + " 실패 " + textBox1.Text + "x" + textBox2.Text + "=" + Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text));
                textBox2.Text = Convert.ToString((r.Next() % 9) + 1);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int result = Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text);

            if (result != Convert.ToInt32(textBox3.Text))
            {
                listBox1.Items.Add("시간 " + DateTime.Now.ToString("HH:mm:ss") + " 실패 " + textBox1.Text + "x" + textBox2.Text + "=" + Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text));
                int WCnt = Convert.ToInt32(label8.Text);
                WCnt++;
                label8.Text = Convert.ToString(WCnt);
                label2.Text = "5";
                textBox2.Text = Convert.ToString((r.Next() % 9) + 1);
            
            }
            else
            {
                listBox1.Items.Add("시간 " + DateTime.Now.ToString("HH:mm:ss") + " 성공 " + textBox1.Text + "x" + textBox2.Text + "=" + Convert.ToInt32(textBox1.Text) * Convert.ToInt32(textBox2.Text));
                int CCnt = Convert.ToInt32(label7.Text);
                CCnt++;
                label7.Text = Convert.ToString(CCnt);
                label2.Text = "5";
                textBox2.Text = Convert.ToString((r.Next() % 9) + 1);
    
            }
        }
    }
}
