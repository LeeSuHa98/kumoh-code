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

        private System.Windows.Forms.Button[] button = null;

        int buttonNo = 5;

        private int buttonX = 4;

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

            button = new System.Windows.Forms.Button[buttonNo];
            for(int i = 0; i < buttonNo; i++)
            {
                this.button[i] = new System.Windows.Forms.Button();

                this.button[i].Location = new System.Drawing.Point(100, 100 + i * 30);
                this.button[i].Name = i.ToString();
                this.button[i].Size = new System.Drawing.Size(30, 30);
                this.button[i].TabIndex = 0;
                this.button[i].Text = i.ToString();
                this.button[i].UseVisualStyleBackColor = true;

                this.button[i].Click += new System.EventHandler(this.button_Click);

                this.Controls.Add(this.button[i]);
            }
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button_Click(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            textBox1.Text = textBox1.Text + " " + b.Text.ToString();
        }
    }
}
