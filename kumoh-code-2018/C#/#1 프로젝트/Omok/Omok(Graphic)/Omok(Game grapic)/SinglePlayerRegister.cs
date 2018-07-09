using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Omok
{
    public partial class SinglePlayerRegister : Form
    {
        intelligentMatch iMatch;
        private string username = "";
        public string Username {
            get { return username; 
            }
        }
        public SinglePlayerRegister(intelligentMatch m, string message)
        {
            InitializeComponent();
            iMatch = m;
            displayMessage.Text = message;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            username = textBox1.Text;
            this.Close();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter) button1_Click(sender, e);
        }
    }
}
