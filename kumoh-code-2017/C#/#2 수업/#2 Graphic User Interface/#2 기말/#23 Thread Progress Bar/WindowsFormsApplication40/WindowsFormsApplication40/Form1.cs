using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace WindowsFormsApplication40
{
    public partial class Form1 : Form
    {
        private Thread thread1;
        private Thread thread2;
        private Thread thread3;
        private Random r = new Random();
    
        public Form1()
        {
            InitializeComponent();
        }

        delegate void SetProgressBarCallBack(int barNo, int Value);
        private void SetProgressBar(int barNo, int Value)
        {
            if (barNo == 1)
            {
                if (this.progressBar1.InvokeRequired)
                {
                    this.progressBar1.Invoke(new SetProgressBarCallBack(SetProgressBar), new object[] { 1, Value });
                }
                else
                {
                    if (Value >= 100)
                        this.progressBar1.Value = 100;
                    else
                        this.progressBar1.Value = Value;
                }
            }
            else if (barNo == 2)
            {
                if (this.progressBar2.InvokeRequired)
                {
                    this.progressBar2.Invoke(new SetProgressBarCallBack(SetProgressBar), new object[] { 2, Value });
                }
                else
                {
                    if (Value >= 100)
                        this.progressBar2.Value = 100;
                    else
                        this.progressBar2.Value = Value;
                }
            }
            else if (barNo == 3)
            {
                if (this.progressBar3.InvokeRequired)
                {
                    this.progressBar3.Invoke(new SetProgressBarCallBack(SetProgressBar), new object[] { 3, Value });
                }
                else
                {
                    if (Value >= 100)
                        this.progressBar3.Value = 100;
                    else
                        this.progressBar3.Value = Value;
                }
            }
        }

        delegate int GetProgressBarCallBack(int barNo);
        private int GetProgressBar(int barNo)
        {
            int result = 0;

            if (barNo == 1)
            {
                if (this.progressBar1.InvokeRequired)
                {
                    result = (int)this.progressBar1.Invoke(new GetProgressBarCallBack(GetProgressBar), new object[] { 1 });
                }
                else
                {
                    result = this.progressBar1.Value;
                }
            }
            else if (barNo == 2)
            {
                if (this.progressBar2.InvokeRequired)
                {
                    result = (int)this.progressBar2.Invoke(new GetProgressBarCallBack(GetProgressBar), new object[] { 2 });
                }
                else
                {
                    result = this.progressBar2.Value;
                }
            }
            else if (barNo == 3)
            {
                if (this.progressBar3.InvokeRequired)
                {
                    result = (int)this.progressBar3.Invoke(new GetProgressBarCallBack(GetProgressBar), new object[] { 3 });
                }
                else
                {
                    result = this.progressBar3.Value;
                }
            }

            return result;
        }

        delegate void SetTextBoxCallBack(int barNo, int Value);
        private void SetTextBox(int barNo, int Value)
        {
            if (barNo == 1)
            {
                if (this.textBox1.InvokeRequired)
                {
                    this.textBox1.Invoke(new SetProgressBarCallBack(SetTextBox), new object[] { 1, Value });
                }
                else
                {
                    textBox1.Text = Value.ToString();
                }
            }
            else if (barNo == 2)
            {
                if (this.textBox2.InvokeRequired)
                {
                    this.textBox2.Invoke(new SetProgressBarCallBack(SetTextBox), new object[] { 2, Value });
                }
                else
                {
                    textBox2.Text = Value.ToString();
                }
            }
            else if (barNo == 3)
            {
                if (this.textBox3.InvokeRequired)
                {
                    this.textBox3.Invoke(new SetProgressBarCallBack(SetTextBox), new object[] { 3, Value });
                }
                else
                {
                    textBox3.Text = Value.ToString();
                }
            }
        }

        public void threadFunc1()
        {
            for (int i = 0; i <= 100; i++)
            {
                SetProgressBar(1, i);
                int pv = GetProgressBar(1);
                SetTextBox(1, pv);

                System.Threading.Thread.Sleep(r.Next(5, 100));
            }
        }

        public void threadFunc2()
        {
            for (int i = 0; i <= 100; i++)
            {
                SetProgressBar(2, i);
                int pv = GetProgressBar(2);
                SetTextBox(2, pv);

                System.Threading.Thread.Sleep(r.Next(5, 100));
            }
        }

        public void threadFunc3()
        {
            for(int i = 0; i <= 100; i++)
            {
                SetProgressBar(3, i);
                int pv = GetProgressBar(3);
                SetTextBox(3, pv);

                System.Threading.Thread.Sleep(r.Next(5, 100));
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            thread1 = new Thread(new ThreadStart(this.threadFunc1));
            thread2 = new Thread(new ThreadStart(this.threadFunc2));
            thread3 = new Thread(new ThreadStart(this.threadFunc3));

            thread1.Start();
            thread2.Start();
            thread3.Start();
        }
    }
}
