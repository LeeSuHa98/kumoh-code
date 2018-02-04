using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 씨샾계산기
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void AllButton_Click(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            if (b.Text != "X")
                textBox1.Text += b.Text;
            else
                textBox1.Text += "*";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            textBox1.Text = null;
        }

        private void button18_Click(object sender, EventArgs e)
        {
            Expression ex = new Expression();
            Calculator c = new Calculator();
            
            string err = ex.expInput(textBox1.Text);
            if (err == null)
            {
                c.postfix(ex);
                err = c.calculation();
                if (err != null)
                {
                    MessageBox.Show(err);
                    return;
                }
                else
                    textBox1.Text += " = "+c.getNumStack().Peek();
            }
            else
            {
                MessageBox.Show(err);
                return;
            }
        }
    }
}
