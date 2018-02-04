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
    public partial class Form1 : Form
    {
        public ClockSetting cs = null;

        int timeDisplay = 1;

        public Form1()
        {
            InitializeComponent();
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            DateTime nowTime = DateTime.Now;

            string timeSTR;

            //if (nowTime.Hour > 12)
            //{
            //    timeSTR = string.Format("오후 {0}시 {1}분 {2} 초", nowTime.Hour - 12, nowTime.Minute, nowTime.Second);
            //}
            //else
            //{
            //    timeSTR = string.Format("오후 {0}시 {1}분 {2} 초", nowTime.Hour - 12, nowTime.Minute, nowTime.Second);
            //}

            //timeLabel.Text = timeSTR;

            if (timeDisplay == 12)
            {
                if (nowTime.Hour > 12)
                {
                    timeSTR = string.Format("오후 {0}시 {1}분 {2} 초", nowTime.Hour - 12, nowTime.Minute, nowTime.Second);
                }
                else
                {
                    timeSTR = string.Format("오후 {0}시 {1}분 {2} 초", nowTime.Hour - 12, nowTime.Minute, nowTime.Second);
                }

                timeLabel.Text = timeSTR;
            }
            else
            {
                timeSTR = string.Format("오후 {0}시 {1}분 {2} 초", nowTime.Hour, nowTime.Minute, nowTime.Second);
                timeLabel.Text = timeSTR;
            }
        }

        private void fontButton_Click(object sender, EventArgs e)
        {
            FontDialog fDlg = new FontDialog();

            if(fDlg.ShowDialog() == DialogResult.OK)
            {
                timeLabel.Font = fDlg.Font;
            }
        }

        private void colorButton_Click(object sender, EventArgs e)
        {
            ColorDialog cDlg = new ColorDialog();

            cDlg.Color = timeLabel.ForeColor;

            if(cDlg.ShowDialog() == DialogResult.OK)
            {
                timeLabel.ForeColor = cDlg.Color;
            }
        }

        public void setText(Color textColor, int timeDisplay)
        {
            timeLabel.ForeColor = textColor;
            this.timeDisplay = timeDisplay;
        }

        private void setTimer_Click(object sender, EventArgs e)
        {
            //ClockSetting cs = new ClockSetting();

            //cs.textColor = timeLabel.ForeColor;
            //cs.timeDisplay = timeDisplay;   // 현재 설정을 다시 표시

            //cs.Show();  // 모들리스 (클릭하면 창이 무한대로 뜰거임)

            //if(cs.ShowDialog() == DialogResult.OK)
            //{
            //    timeLabel.ForeColor = cs.textColor;
            //    timeDisplay = cs.timeDisplay;
            //}

            if(cs == null)
            {
                cs = new ClockSetting(this);
            }

            cs.Show();
            cs.Focus();
        }
    }
}
