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

namespace WindowsFormsApplication39
{
    public partial class Form1 : Form
    {
        private Thread thread;

        public Form1()
        {
            InitializeComponent();

            CheckForIllegalCrossThreadCalls = true; // 디버깅중 잘못된 스레드에 관한 Catch를  호출 할 건지 말건지를 설정하는 기능
        }

        public void threadFunc()
        {
            for (int i = 0; ; i++)
            {
                SetLabelText(i.ToString());
            }
        }

        delegate void SetLabelCallBack(string str);
        public void SetLabelText(string str)
        {
            if(label1.InvokeRequired)
            {
                label1.Invoke(new SetLabelCallBack(SetLabelText), new object[] { str });
            }
            else
            {
                label1.Text = str;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            thread = new Thread(new ThreadStart(threadFunc));
            thread.Start();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            thread.Abort();
        }
    }
}
