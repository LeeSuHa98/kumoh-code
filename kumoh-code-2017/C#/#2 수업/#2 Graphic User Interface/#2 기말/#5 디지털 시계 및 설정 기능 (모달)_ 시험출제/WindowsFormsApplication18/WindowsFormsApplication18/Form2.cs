using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication18
{
    public partial class Form2 : Form
    {
        public Color textColor = Color.Red;
        public int timeDisplay = 12;

        public Form2()
        {
            InitializeComponent();
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            textColor = Color.FromName(comboBox1.Text);
            timeDisplay = Convert.ToInt32(comboBox2.Text);

            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            if(textColor == Color.Red)
            {
                comboBox1.Text = "Red";
            }
            else if(textColor == Color.Green)
            {
                comboBox1.Text = "Green";
            }
            else if(textColor == Color.Blue)
            {
                comboBox1.Text = "Blue";
            }

            comboBox2.Text = Convert.ToString(timeDisplay);
        }
    }
}
