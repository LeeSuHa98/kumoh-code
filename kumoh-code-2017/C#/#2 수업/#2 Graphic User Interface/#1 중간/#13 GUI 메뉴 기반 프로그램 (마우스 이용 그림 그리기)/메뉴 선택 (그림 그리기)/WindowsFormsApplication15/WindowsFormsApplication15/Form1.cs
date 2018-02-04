using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication15
{
    public partial class Form1 : Form
    {
        bool clicked = false;

        private Color penColor = Color.Red;

        public Form1()
        {
            InitializeComponent();
        }

        private void 배경검정색ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Black;
        }

        private void 빨강ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            빨강ToolStripMenuItem.Checked = true;
            파랑ToolStripMenuItem.Checked = false;
            녹색ToolStripMenuItem.Checked = false;
            penColor = Color.Red;
        }

        private void 파랑ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            빨강ToolStripMenuItem.Checked = false;
            파랑ToolStripMenuItem.Checked = true;
            녹색ToolStripMenuItem.Checked = false;
            penColor = Color.Blue;
        }

        private void 녹색ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            빨강ToolStripMenuItem.Checked = false;
            파랑ToolStripMenuItem.Checked = false;
            녹색ToolStripMenuItem.Checked = true;
            penColor = Color.Green;
        }

        private void 종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (clicked == true)
            {
                int size = Convert.ToInt32(toolStripComboBox1.SelectedItem);
                Graphics graphics = CreateGraphics();
                graphics.FillEllipse(new SolidBrush(penColor), e.X, e.Y, size, size);
                //if (comboBox1.Text == "Red")
                //{
                //    graphics.FillEllipse(new SolidBrush(Color.Red), e.X, e.Y, 4, 4);
                //}
                //else if (comboBox1.Text == "Green")
                //{
                //    graphics.FillEllipse(new SolidBrush(Color.Green), e.X, e.Y, 4, 4);
                //}
                //else if (comboBox1.Text == "Blue")
                //{
                //    graphics.FillEllipse(new SolidBrush(Color.Blue), e.X, e.Y, 4, 4);
                //}
                //else if (comboBox1.Text == "Yellow")
                //{
                //    graphics.FillEllipse(new SolidBrush(Color.Yellow), e.X, e.Y, 4, 4);
                //}
                graphics.Dispose();
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            clicked = true;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            clicked = false;
        }

        private void toolStripComboBox1_Click(object sender, EventArgs e)
        {
            toolStripTextBox1.Text = Convert.ToString(toolStripComboBox1.SelectedItem);
        }

        private void 배경흰색ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.White;
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Red;
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Blue;
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Green;
        }
    }
}
