using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharp_그림_그리기
{
    public partial class Form1 : Form
    {
        bool clicked = false;

        private Color penColor = Color.Red;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
          
        }
        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {          
           if(clicked == true)
            {
                int size = Convert.ToInt32(toolStripTextBox1.Text);
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

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void 설정ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 파랑ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
        private void 빨강ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }

        private void 녹색ToolStripMenuItem_Click(object sender, EventArgs e)
        {
           
        }

        private void 노랑ToolStripMenuItem_Click(object sender, EventArgs e)
        {
           
        }

        private void 빨강ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            빨강ToolStripMenuItem1.Checked = true;
            파랑ToolStripMenuItem1.Checked = false;
            녹색ToolStripMenuItem1.Checked = false;
            노랑ToolStripMenuItem1.Checked = false;
            penColor = Color.Red;
        }

        private void 파랑ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            빨강ToolStripMenuItem1.Checked = false;
            파랑ToolStripMenuItem1.Checked = true;
            녹색ToolStripMenuItem1.Checked = false;
            노랑ToolStripMenuItem1.Checked = false;
            penColor = Color.Blue;
        }

        private void 녹색ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            빨강ToolStripMenuItem1.Checked = false;
            파랑ToolStripMenuItem1.Checked = false;
            녹색ToolStripMenuItem1.Checked = true;
            노랑ToolStripMenuItem1.Checked = false;
            penColor = Color.Green;
        }

        private void 노랑ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            빨강ToolStripMenuItem1.Checked = false;
            파랑ToolStripMenuItem1.Checked = false;
            녹색ToolStripMenuItem1.Checked = false;
            노랑ToolStripMenuItem1.Checked = true;
            penColor = Color.Yellow;
        }

        private void toolStripTextBox1_Click(object sender, EventArgs e)
        {

        }

        private void 종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
