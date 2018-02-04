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
    public partial class ClockSetting : Form
    {
        //public Color textColor = Color.Red;
        //public int timeDisplay = 12;

        Form1 mainForm = null;

        public ClockSetting(Form1 mForm)
        {
            InitializeComponent();

            this.mainForm = mForm;
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            mainForm.cs = null;
            this.Close();
        }

        private void applyButton_Click(object sender, EventArgs e)
        {
            Color textColor = Color.FromName(comboBox1.Text);
            int timeDisplay = Convert.ToInt32(comboBox2.Text);

            mainForm.setText(textColor, timeDisplay);
        }

        private void Form2_Load(object sender, EventArgs e)
        {
        }
    }
}
