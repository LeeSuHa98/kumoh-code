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
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(textBox1.Text.Length < 1)
            {
                return;
            }

            TreeNode nameNode = new TreeNode(textBox1.Text);
            nameNode.Nodes.Add(textBox2.Text);
            nameNode.Nodes.Add(textBox3.Text);
            nameNode.Nodes.Add(comboBox1.Text);

            treeView1.Nodes.Add(nameNode);
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            if (treeView1.SelectedNode.Level > 0)
            {
                return;
            }

            textBox1.Text = treeView1.SelectedNode.Text;
            textBox2.Text = treeView1.SelectedNode.Nodes[0].Text;
            textBox3.Text = treeView1.SelectedNode.Nodes[1].Text;
            comboBox1.Text = treeView1.SelectedNode.Nodes[2].Text;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(treeView1.SelectedNode.Level > 0)
            {
                return;
            }

            string selectedName = textBox1.Text;

            for(int i = treeView1.Nodes.Count - 1; i >= 0; i--)
            {
                if(treeView1.Nodes[i].Text == selectedName)
                {
                    treeView1.SelectedNode.Remove();
                }
            }
        }
    }
}
