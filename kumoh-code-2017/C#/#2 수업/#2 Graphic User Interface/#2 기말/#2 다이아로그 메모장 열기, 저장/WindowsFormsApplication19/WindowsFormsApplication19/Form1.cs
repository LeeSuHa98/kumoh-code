using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication19
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void openFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog openDlg = new OpenFileDialog();

            if(openDlg.ShowDialog() == DialogResult.OK)
            {
                fileName.Text = openDlg.FileName;

                StreamReader sr = new StreamReader(openDlg.FileName);

                string allText = sr.ReadToEnd();

                sr.Close();

                textBox1.Text = openDlg.FileName;
                textBox2.Text = allText;
            }
        }

        private void fileSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveDlg = new SaveFileDialog();

            if (saveDlg.ShowDialog() == DialogResult.OK)
            {
                StreamWriter sw = new StreamWriter(saveDlg.FileName);

                sw.WriteLine(textBox2.Text);

                sw.Close();
            }
        }
    }
}
