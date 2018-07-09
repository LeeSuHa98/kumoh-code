using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Omok
{
    public partial class Form1 : Form
    {
        intelligentMatch iMatch;
        public Form1(intelligentMatch m)
        {
            InitializeComponent();

            iMatch = m;
            VisibilityControlSecondSet(false);
            VisibilityControlThirdSet(false);
            pictureBox1.Hide();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            VisibilityControlFirstSet(false);
            VisibilityControlSecondSet(true);

        }

        private void button5_Click(object sender, EventArgs e)
        {
            VisibilityControlSecondSet(false);
            VisibilityControlThirdSet(true);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            iMatch.setPlayType(2);
            SinglePlayerRegister singleregisterform = new SinglePlayerRegister(iMatch, "사용자 이름을 입력하세요.");
            singleregisterform.ShowDialog();
            iMatch.setfirstplayer(singleregisterform.Username);
            iMatch.setsecondplayer("컴퓨터");
            labelPlayer1name.Text = iMatch.getfirstplayer();
            labelPlayer2name.Text = "컴퓨터";
            VisibilityControlSecondSet(false);
            pictureBox1.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            VisibilityControlSecondSet(false);
            VisibilityControlFirstSet(true);
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void VisibilityControlFirstSet(bool flag)
        {
            if (flag == true)
            {
                button1.Show();
                button2.Show();
                button3.Show();
            }
            else
            {
                button1.Hide();
                button2.Hide();
                button3.Hide();
            }
        }
        private void VisibilityControlSecondSet(bool flag)
        {
            if (flag == true)
            {
                button4.Show();
                button5.Show();
                button6.Show();
            }
            else
            {
                button4.Hide();
                button5.Hide();
                button6.Hide();
            }
        }
        private void VisibilityControlThirdSet(bool flag)
        {
            if (flag == true)
            {
                button7.Show();
                button8.Show();
                button9.Show();
            }
            else
            {
                button7.Hide();
                button8.Hide();
                button9.Hide();
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            VisibilityControlThirdSet(false);
            VisibilityControlSecondSet(true);
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            int stone;
                
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Color.Black);
            SolidBrush mySoildBrush = new SolidBrush(Color.Black);
            SolidBrush whiteSoildBrush = new SolidBrush(Color.White);

            int w = pictureBox1.Width / 20;
            int h = pictureBox1.Height / 20;

            for (int i = 1; i < 20; i++)
            {
                g.DrawLine(myPen, w, i * h, 19 * w, i * h);
                g.DrawLine(myPen, i * w, h, i * w, 19 * h);
            }

            g.FillEllipse(mySoildBrush, 5 * w - 5, 5 * h - 5, 10, 10);
            g.FillEllipse(mySoildBrush, 15 * w - 5, 5 * h - 5, 10, 10);
            g.FillEllipse(mySoildBrush, 5 * w - 5, 15 * h - 5, 10, 10);
            g.FillEllipse(mySoildBrush, 15 * w - 5, 15 * h - 5, 10, 10);
            g.FillEllipse(mySoildBrush, 10 * w - 5, 10 * h - 5, 10, 10);
            g.FillEllipse(mySoildBrush, 5 * w - 5, 10 * h - 5, 10, 10);
            g.FillEllipse(mySoildBrush, 10 * w - 5, 5 * h - 5, 10, 10);
            g.FillEllipse(mySoildBrush, 10 * w - 5, 15 * h - 5, 10, 10);
            g.FillEllipse(mySoildBrush, 15 * w - 5, 10 * h - 5, 10, 10);

            for (int i = 0; i < 19; i++)
                for (int j = 0; j < 19; j++)
                {
                    stone = iMatch.getStone(i, j);
                    if (stone == 1) {
                        g.FillEllipse(mySoildBrush, (j + 1) * h - 10, (i + 1) * w - 10, 20, 20);
                    }
                    else if (stone == 2) {
                        g.FillEllipse(whiteSoildBrush, (j + 1) * h - 10, (i + 1) * w - 10, 20, 20);
                    }
                }

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

            iMatch.setPlayType(1);
            SinglePlayerRegister singleregisterform = new SinglePlayerRegister(iMatch, "첫번째 사용자 이름을 입력하세요.");
            singleregisterform.ShowDialog();
            iMatch.setfirstplayer(singleregisterform.Username);
            singleregisterform = new SinglePlayerRegister(iMatch, "두번째 사용자 이름을 입력하세요.");
            singleregisterform.ShowDialog();
            iMatch.setsecondplayer(singleregisterform.Username);
            VisibilityControlThirdSet(false);
            pictureBox1.Show();
            labelPlayer1name.Text = iMatch.getfirstplayer();
            labelPlayer2name.Text = iMatch.getsecondplayer();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            iMatch.setPlayType(3);
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            int w, h, r = 0, c = 0;

            if (iMatch.getPlayType() == 1)
            {
                w = pictureBox1.Width / 20;
                h = pictureBox1.Height / 20;
                c = (int)(e.X + w * 0.5) / w - 1;
                r = (int)(e.Y + h * 0.5) / h - 1;
                play(r, c, iMatch.getturn());
            }
            else if (iMatch.getPlayType() == 2)
            {
                int turn = iMatch.getturn();
                if (turn == 1)
                {
                    w = pictureBox1.Width / 20;
                    h = pictureBox1.Height / 20;
                    c = (int)(e.X + w * 0.5) / w - 1;
                    r = (int)(e.Y + h * 0.5) / h - 1;
                    play(r, c, turn);
                    autoPlay();
                }
            }
        }

        public void DispalyBoard()
        {
            pictureBox1.Invalidate();
        }

            
        private void play(int r, int c, int turn)
        {
            string winner;
                        
          
            if (iMatch.isValid(r, c) == true)
            { // 자리가 비어 있을 경우
                iMatch.putStone(r, c, turn);
                iMatch.incrementSequenceNumber(turn);
                DispalyBoard();
                bool flag = iMatch.checkwinningcondition();

                if (flag == true)
                {
                    if (turn == 1) winner = iMatch.getfirstplayer();
                    else winner = iMatch.getsecondplayer();
                    MessageBox.Show("축하합니다. " + winner + "님이 이겼습니다.");
                    return;
                }
                else
                {
                    if (turn == 1)
                    { // 첫번째 주자이면
                        labelPlayer1name.Text = iMatch.getfirstplayer();
                        labelPlayer1location.Text = r + ", " + c;
                        labelPlayer1name.ForeColor = Color.Blue;
                        labelPlayer1location.ForeColor = Color.Blue;
                        labelPlayer2name.ForeColor = Color.Black;
                        labelPlayer2location.ForeColor = Color.Black;
                        iMatch.setturn(2);
                    }
                    else
                    {
                        labelPlayer2name.Text = iMatch.getsecondplayer();
                        labelPlayer2location.Text = r + ", " + c;
                        labelPlayer1name.ForeColor = Color.Black;
                        labelPlayer1location.ForeColor = Color.Black;
                        labelPlayer2name.ForeColor = Color.Blue;
                        labelPlayer2location.ForeColor = Color.Blue;
                        iMatch.setturn(1);
                    }
                }
            }
            else
            { // 자리가 차 있을 경우
                MessageBox.Show("이미 있는 자리입니다. 다시 놓으세요.");
            }
        }

        private void autoPlay() 
        {
            int r = 0, c = 0, check;

            if (iMatch.getSequenceNumber(iMatch.getturn()) == 0)
            {
                check = iMatch.getRandomPosition(ref r, ref c);
            }
            else check = iMatch.getStonePositionAuto(ref r, ref c);
            play(r, c, iMatch.getturn());
        }

        private void labelPlayer1name_Click(object sender, EventArgs e)
        {

        }

        private void labelPlayer2name_Click(object sender, EventArgs e)
        {

        }

        private void labelPlayer1location_Click(object sender, EventArgs e)
        {

        }

        private void labelPlayer2location_Click(object sender, EventArgs e)
        {

        }
    }
}
