﻿namespace WindowsFormsApplication6
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(54, 57);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 289);
            this.button1.TabIndex = 0;
            this.button1.Text = "도";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button1_MouseDown);
            this.button1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button1_MouseUp);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.White;
            this.button2.Location = new System.Drawing.Point(135, 57);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 289);
            this.button2.TabIndex = 1;
            this.button2.Text = "레";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button2_MouseDown);
            this.button2.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button2_MouseUp);
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.White;
            this.button3.Location = new System.Drawing.Point(216, 57);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 289);
            this.button3.TabIndex = 2;
            this.button3.Text = "미";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button3_MouseDown);
            this.button3.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button3_MouseUp);
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.SystemColors.Window;
            this.button4.Location = new System.Drawing.Point(297, 57);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 289);
            this.button4.TabIndex = 3;
            this.button4.Text = "파";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button1_MouseDown);
            this.button4.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button1_MouseUp);
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.Color.White;
            this.button5.Location = new System.Drawing.Point(378, 57);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 289);
            this.button5.TabIndex = 4;
            this.button5.Text = "솔";
            this.button5.UseVisualStyleBackColor = false;
            this.button5.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button1_MouseDown);
            this.button5.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button1_MouseUp);
            // 
            // button6
            // 
            this.button6.BackColor = System.Drawing.Color.White;
            this.button6.Location = new System.Drawing.Point(459, 57);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(75, 289);
            this.button6.TabIndex = 5;
            this.button6.Text = "라";
            this.button6.UseVisualStyleBackColor = false;
            this.button6.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button1_MouseDown);
            this.button6.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button1_MouseUp);
            // 
            // button7
            // 
            this.button7.BackColor = System.Drawing.Color.White;
            this.button7.Location = new System.Drawing.Point(540, 57);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(75, 289);
            this.button7.TabIndex = 6;
            this.button7.Text = "시";
            this.button7.UseVisualStyleBackColor = false;
            this.button7.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button1_MouseDown);
            this.button7.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button1_MouseUp);
            // 
            // button8
            // 
            this.button8.BackColor = System.Drawing.Color.White;
            this.button8.Location = new System.Drawing.Point(621, 57);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(75, 289);
            this.button8.TabIndex = 7;
            this.button8.Text = "도";
            this.button8.UseVisualStyleBackColor = false;
            this.button8.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button1_MouseDown);
            this.button8.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button1_MouseUp);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(762, 432);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Mouse Piano";
            this.UseWaitCursor = true;
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
    }
}

