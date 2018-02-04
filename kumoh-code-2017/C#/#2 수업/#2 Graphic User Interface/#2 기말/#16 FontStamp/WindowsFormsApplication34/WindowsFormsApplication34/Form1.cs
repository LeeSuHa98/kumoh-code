using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication34
{
    public partial class Form1 : Form
    {
        private string drawSTR = "Hello";
        private Font drawFONT = DefaultFont;

        public Form1()
        {
            InitializeComponent();
        }

        private void fontToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FontDialog fDlg = new FontDialog();

            if(fDlg.ShowDialog() == DialogResult.OK)
            {
                drawFONT = fDlg.Font;
            }
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            Graphics gHandle = this.CreateGraphics();

            gHandle.DrawString(drawSTR, drawFONT, Brushes.Red, e.X, e.Y);
        }

        private void toolStripTextBox1_Click(object sender, EventArgs e)
        {
            drawSTR = toolStripTextBox1.Text;
        }
    }
}
