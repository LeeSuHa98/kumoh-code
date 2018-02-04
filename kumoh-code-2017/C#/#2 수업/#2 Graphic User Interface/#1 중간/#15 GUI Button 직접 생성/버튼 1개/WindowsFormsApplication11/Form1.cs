using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication11
{
    public partial class Form1 : Form
    {
        private System.Windows.Forms.Button button1;
        public Form1()
        {
            InitializeComponent();

            this.button1 = new System.Windows.Forms.Button();

            this.button1.Location = new System.Drawing.Point(100, 50);
            this.button1.Name = "b1";
            this.button1.Size = new System.Drawing.Size(30, 30);
            this.button1.TabIndex = 0;
            this.button1.Text = "b1";
            this.button1.UseVisualStyleBackColor = true;

            this.Controls.Add(this.button1);
        }
    }
}
