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

using System.Net;
using System.Net.Sockets;
using System.IO;

namespace WindowsFormsApplication42
{
    public partial class Form1 : Form
    {
        private Thread server = null;

        private TcpListener listener = null;
        private TcpClient client = null;
        private NetworkStream ns = null;

        private StreamReader m_reader = null;
        private StreamWriter m_writer = null;

        public Form1()
        {
            InitializeComponent();

            CheckForIllegalCrossThreadCalls = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(this.server != null)
            {
                this.listener.Stop();
                this.server.Abort();
            }

            this.server = new Thread(new ThreadStart(Listen));
            this.server.Start();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(this.server != null)
            {
                this.listener.Stop();
                this.server.Abort();
            }
            this.server = null;
        }

        void Listen()
        {
            listener = new TcpListener(IPAddress.Any, Convert.ToInt16(textBox1.Text));
            listener.Start();

            while(true)
            {
                listBox1.Items.Add("연결 대기중");

                try
                {
                    client = listener.AcceptTcpClient();
                }
                catch
                {
                    continue;
                }

                listBox1.Items.Add("연결 됨");

                ns = client.GetStream();
                m_reader = new StreamReader(ns);
                m_writer = new StreamWriter(ns);

                m_writer.AutoFlush = true;  // 중요 (버퍼링 해결)

                string welcome = "Welcome to C# Server";
                m_writer.WriteLine(welcome);

                while(true)
                {
                    string message = m_reader.ReadLine();

                    if(client.Connected == false)
                    {
                        break;
                    }
                    
                    if(message == null)
                    {
                        break;
                    }

                    this.listBox1.Items.Add("Client: " + message);
                    this.listBox1.SelectedIndex = this.listBox1.Items.Count - 1;
                }

                m_reader.Close();
                m_writer.Close();

                ns.Close();
                client.Close();

                listBox1.Items.Add("Connected Close");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if(client == null)
            {
                return;
            }

            m_writer.WriteLine(textBox2.Text);

            this.listBox1.Items.Add("Me: " + textBox2.Text);
            this.listBox1.SelectedIndex = this.listBox1.Items.Count - 1;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(this.server != null)
            {
                this.listener.Stop();
                this.server.Abort();
            }
            this.server = null;
        }
    }
}
