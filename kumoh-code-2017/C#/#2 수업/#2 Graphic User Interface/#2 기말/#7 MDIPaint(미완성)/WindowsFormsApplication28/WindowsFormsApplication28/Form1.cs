using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication28
{
    public partial class Form1 : Form
    {
        bool clickedMouse = false;
        public Form1()
        {
            InitializeComponent();
        }

        private void 새프로그램ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PaintForm pForm = new PaintForm();
            pForm.MdiParent = this;

            pForm.Show();
        }

        private void 종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void cascadeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.Cascade);
        }

        private void tileHorizontalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void tileVerticalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileVertical);
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (clickedMouse == true)
            {
                if (e.Button == MouseButtons.Left)
                {
                    Graphics graphics = CreateGraphics();
                    graphics.FillEllipse(new SolidBrush(Color.Red), e.X, e.Y, 4, 4);
                    graphics.Dispose();
                }
            }
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            clickedMouse = false;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            clickedMouse = true;
        }
    }
}
