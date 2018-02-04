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

namespace WindowsFormsApplication38
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public void PopulateTreeView(string directoryValue, TreeNode parentNode)
        {
            // array stores all subdirectories in the directory
            string[] directoryArray = Directory.GetDirectories(directoryValue);

            try
            {
                if (directoryArray.Length != 0)
                {
                    for (int i = 0; i < directoryArray.Length; i++)
                    {
                        string fullPath = directoryArray[i];

                        string substringDirectory = fullPath.Substring(fullPath.LastIndexOf('\\') + 1, fullPath.Length - fullPath.LastIndexOf('\\') - 1);

                        TreeNode myNode = new TreeNode(substringDirectory);
                        parentNode.Nodes.Add(myNode);

                        // recursively populate every subdirectory
                        PopulateTreeView(fullPath, myNode);
                    }
                }

            }
            catch (UnauthorizedAccessException)
            {
                parentNode.Nodes.Add("Access denied");
            }
        }

    private void button1_Click(object sender, EventArgs e)
        {
            treeView1.Nodes.Clear();

            if (Directory.Exists(textBox1.Text) == true)
            {
                treeView1.Nodes.Add(textBox1.Text);

                PopulateTreeView(textBox1.Text, treeView1.Nodes[0]);
            }
        }
    }
}
