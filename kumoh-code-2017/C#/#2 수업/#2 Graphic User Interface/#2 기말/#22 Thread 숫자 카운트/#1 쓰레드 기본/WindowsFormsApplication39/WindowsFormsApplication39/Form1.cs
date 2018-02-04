﻿using System;
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
        }

        public void threadFunc()
        {
            for (int i = 0; ; i++)
            {
                label1.Text = i.ToString();
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
