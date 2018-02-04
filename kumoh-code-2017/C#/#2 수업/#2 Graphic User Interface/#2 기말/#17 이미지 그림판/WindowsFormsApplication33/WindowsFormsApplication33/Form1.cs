using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication33
{
    public partial class Form1 : Form
    {
        Bitmap image = null;
        private Color penColor = Color.Red;
        private Point clickPos;
        private bool mouseClick = true;

        public Form1()
        {
            InitializeComponent();
        }

        private void fileOpenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "bmp files (*.bmp)|*.bmp|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.RestoreDirectory = true;

            if(openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                image = new Bitmap(openFileDialog1.FileName);

                this.Invalidate();
            }
        }

        private void fileSaveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(image == null)
            {
                MessageBox.Show("image is not loaded");
                return;
            }
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "bmp files (*.bmp)|*.bmp|All files (*.*)|*.*";
            saveFileDialog1.FilterIndex = 2;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                image.Save(saveFileDialog1.FileName);
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            this.Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics gHandle = e.Graphics;

            if(image != null)
            {
                gHandle.DrawImage(image, 0, 0, ClientRectangle.Width, ClientRectangle.Height);
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            mouseClick = true;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            mouseClick = false;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if(mouseClick == true && image != null)
            {
                for(int i = 0; i < 30; i++)
                {
                    for(int j = 0; j < 30; j++)
                    {
                        Color px = image.GetPixel(e.X+i, e.Y+j);
                        int mean = (px.R + px.G + px.B) / 3;
                        image.SetPixel(e.X + i, e.Y + j, Color.FromArgb(mean, mean, mean));
                    }
                }

                this.Invalidate();
            }
        }
    }
}
