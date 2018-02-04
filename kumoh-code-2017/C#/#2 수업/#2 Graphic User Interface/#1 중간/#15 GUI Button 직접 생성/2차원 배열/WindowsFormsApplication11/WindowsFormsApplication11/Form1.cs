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
        private System.Windows.Forms.Button[] button = null;

        private int buttonX = 4;

        public Form1()
        {
            InitializeComponent();

            makeButton(buttonX);
        }

        private void makeButton(int buttonNo)
        {
            if(button != null)
            {
                for(int i = 0; i < buttonX * buttonX; i++)
                {
                    this.Controls.Remove(this.button[i]);
                }
            }

            buttonX = buttonNo;

            button = new Button[buttonX * buttonX];

            for(int i = 0; i < buttonX * buttonX; i++)
            {
                this.button[i] = new System.Windows.Forms.Button();
            }

            for (int i = 0; i < buttonNo * buttonNo; i++)
            {
                int x = i % buttonX;
                int y = i / buttonX;

                this.button[i].Location = new System.Drawing.Point(50 + x * 40, 50 + y * 40);
                this.button[i].Name = i.ToString();
                this.button[i].Size = new System.Drawing.Size(40, 40);
                this.button[i].TabIndex = 0;
                this.button[i].Text = i.ToString();
                this.button[i].UseVisualStyleBackColor = true;

                this.button[i].Click += new System.EventHandler(this.button_Click);

                this.Controls.Add(this.button[i]);
            }
        }

        private void button_Click(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            textBox1.Text = textBox1.Text + " " + b.Text.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            makeButton(Convert.ToInt32(textBox1.Text));
        }

    }
}
