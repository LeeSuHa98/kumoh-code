using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharp_단어퀴즈
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("단어가 설정되었습니다.");
            question.Enabled = false;
            answer.MaxLength = word.Text.Length;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            bool check = false;
            String wordPiece = "";

            if(question.Text.Equals(word.Text))
            {
                MessageBox.Show("정답입니다!");
                question.Enabled = true;
                answer.Text = word.Text;
                question.Text = "";
            }
            else if(word.Text.Length == 1 || word.Text.Length == answer.Text.Length)
            {
                for(int i = 0; i < question.Text.Length; i++)
                {
                    if(question.Text[i] == '_')
                    {
                        if(word.Text[0] == question.Text[i])
                        {
                            wordPiece = wordPiece + word.Text[0];
                            check = true;
                        }
                        else
                        {
                            wordPiece = wordPiece + "_";
                        }
                    }
                    else
                    {
                        wordPiece = wordPiece + question.Text[i];
                    }
                }

                if (check)
                {
                    MessageBox.Show(word.Text + "단어를 찾았습니다.");
                    word.Text = "";
                }
                else
                {
                    MessageBox.Show(word.Text + "단어를 찾지 못했습니다.");
                }
            }


            if (question.Text.Equals(word.Text))
            {
                MessageBox.Show("정답입니다!");
                question.Enabled = true;
                question.Text = "";
            }
        }
    }
}
