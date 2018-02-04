using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace cSharp_프로그래밍___20170914_2_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();  // control 초기화
            
        }

        private void copyButton_Click(object sender, EventArgs e)
        {
            copyPrint.Text = inputData.Text;
        }

        private void to_Red_CheckedChanged(object sender, EventArgs e)
        {
            copyPrint.ForeColor = System.Drawing.Color.Red;
        }

        private void to_Green_CheckedChanged(object sender, EventArgs e)
        {
            copyPrint.ForeColor = System.Drawing.Color.Green;
        }

        private void to_Blue_CheckedChanged(object sender, EventArgs e)
        {
            copyPrint.ForeColor = System.Drawing.Color.Blue;
        }

        private void isEnable_CheckedChanged(object sender, EventArgs e)
        {
            copyButton.Enabled = isEnable.Checked;
            // enable의 속성에 맞게 button의 가능성을 가능한지 안한지 확인한다.
        }
    }
}
