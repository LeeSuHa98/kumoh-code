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

namespace WindowsFormsApplication41
{
    public partial class Form1 : Form
    {
        private Thread rThread = null;

        private TcpClient client = null;
        private NetworkStream ns = null;

        private StreamReader m_reader = null;
        private StreamWriter m_writer = null;

        public Form1()
        {
            InitializeComponent();

            CheckForIllegalCrossThreadCalls = false;
        }

        public void Receive()
        {
            // Reading을 위한 스레드
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

                this.listBox1.Items.Add("S: " + message);
                this.listBox1.SelectedIndex = this.listBox1.Items.Count - 1;
            }

            this.listBox1.Items.Add("Thread Quit");
        }

        private void button1_Click(object sender, EventArgs e)
        {

            try
            {
                // To be coded (Hint: Connect to Server)
                client = new TcpClient(textBox1.Text.ToString(), Convert.ToInt16(textBox2.Text));
                ns = client.GetStream();    // 스트림 열기

                m_reader = new StreamReader(ns);
                m_writer = new StreamWriter(ns);

                m_writer.AutoFlush = true;  // 중요 (버퍼링 해결)

                listBox1.Items.Add("채팅 서버 접속 성공");
                this.listBox1.SelectedIndex = this.listBox1.Items.Count - 1;

                this.rThread = new Thread(new ThreadStart(Receive));
                this.rThread.Start();   // 메시지 읽어오는 스레드 시작
            }
            catch (SocketException)
            {
                Console.WriteLine("Unable to connect to server");
                return;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(client != null)
            {
                if(this.rThread != null)
                {
                    this.rThread.Abort();
                }
                this.rThread = null;

                m_reader.Close();
                m_writer.Close();
                ns.Close();
                client.Close();

                m_reader = null;
                m_writer = null;
                ns = null;
                client = null;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if(client == null)
            {
                return;
            }

            m_writer.WriteLine(textBox3.Text + " " + textBox4.Text);

            this.listBox1.Items.Add("M: " + textBox4.Text);
            this.listBox1.SelectedIndex = this.listBox1.Items.Count - 1;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (client != null)
            {
                if (this.rThread != null)
                {
                    this.rThread.Abort();
                }
                this.rThread = null;

                m_reader.Close();
                m_writer.Close();
                ns.Close();
                client.Close();

                m_reader = null;
                m_writer = null;
                ns = null;
                client = null;
            }
        }
    }
}
