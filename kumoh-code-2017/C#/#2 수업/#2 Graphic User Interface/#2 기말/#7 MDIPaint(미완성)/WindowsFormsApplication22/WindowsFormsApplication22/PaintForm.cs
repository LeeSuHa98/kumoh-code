using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication22
{
    public partial class PaintForm : Form
    {
        private bool mouseClicked = false;
        private Color mouseColor = Color.Blue;
        private int mouseSize = 2;

        public PaintForm()
        {
            InitializeComponent();
        }

        private void PaintForm_MouseMove(object sender, MouseEventArgs e)
        {
            if (mouseClicked)
            {
                Graphics g = CreateGraphics();
                g.FillEllipse(new SolidBrush(mouseColor), e.X, e.Y, mouseSize, mouseSize);
                g.Dispose();
            }
        }

        private void PaintForm_MouseDown(object sender, MouseEventArgs e)
        {
            mouseClicked = true;
        }

        private void PaintForm_MouseUp(object sender, MouseEventArgs e)
        {
            mouseClicked = false;
        }
    }
}
