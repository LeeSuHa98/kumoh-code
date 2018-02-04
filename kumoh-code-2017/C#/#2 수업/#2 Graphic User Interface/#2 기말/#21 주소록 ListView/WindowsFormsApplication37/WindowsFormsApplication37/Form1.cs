using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication37
{
    public partial class Form1 : Form
    {
        Random r = new Random();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.TextLength < 1)
            {
                return;
            }

            ListViewItem nameItem = new ListViewItem(textBox1.Text);
            nameItem.SubItems.Add(textBox2.Text);
            nameItem.SubItems.Add(new ListViewItem.ListViewSubItem(nameItem, textBox3.Text));
            nameItem.SubItems.Add(new ListViewItem.ListViewSubItem(nameItem, comboBox1.Text));

            nameItem.ImageIndex = r.Next(imageList1.Images.Count - 1);

            listView1.Items.Add(nameItem);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            while(listView1.SelectedIndices.Count > 0)
            {
                listView1.Items.RemoveAt(listView1.SelectedIndices[0]);
            }
        }

        private void largeIconToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listView1.View = View.LargeIcon;
        }

        private void smallIconToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listView1.View = View.SmallIcon;
        }

        private void listToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listView1.View = View.List;
        }

        private void tileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listView1.View = View.Tile;
        }

        private void detailsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listView1.View = View.Details;
        }
    }
}
