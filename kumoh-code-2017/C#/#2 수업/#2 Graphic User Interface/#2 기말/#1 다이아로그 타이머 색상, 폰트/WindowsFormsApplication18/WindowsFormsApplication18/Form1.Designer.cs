namespace WindowsFormsApplication18
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
            this.components = new System.ComponentModel.Container();
            this.colorButton = new System.Windows.Forms.Button();
            this.fontButton = new System.Windows.Forms.Button();
            this.timeLabel = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.setTimer = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // colorButton
            // 
            this.colorButton.Location = new System.Drawing.Point(442, 28);
            this.colorButton.Name = "colorButton";
            this.colorButton.Size = new System.Drawing.Size(75, 23);
            this.colorButton.TabIndex = 0;
            this.colorButton.Text = "색상";
            this.colorButton.UseVisualStyleBackColor = true;
            this.colorButton.Click += new System.EventHandler(this.colorButton_Click);
            // 
            // fontButton
            // 
            this.fontButton.Location = new System.Drawing.Point(361, 28);
            this.fontButton.Name = "fontButton";
            this.fontButton.Size = new System.Drawing.Size(75, 23);
            this.fontButton.TabIndex = 1;
            this.fontButton.Text = "폰트";
            this.fontButton.UseVisualStyleBackColor = true;
            this.fontButton.Click += new System.EventHandler(this.fontButton_Click);
            // 
            // timeLabel
            // 
            this.timeLabel.AutoSize = true;
            this.timeLabel.Location = new System.Drawing.Point(89, 103);
            this.timeLabel.Name = "timeLabel";
            this.timeLabel.Size = new System.Drawing.Size(68, 15);
            this.timeLabel.TabIndex = 2;
            this.timeLabel.Text = "timeLabel";
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // setTimer
            // 
            this.setTimer.Location = new System.Drawing.Point(361, 196);
            this.setTimer.Name = "setTimer";
            this.setTimer.Size = new System.Drawing.Size(84, 23);
            this.setTimer.TabIndex = 3;
            this.setTimer.Text = "시계 설정";
            this.setTimer.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 103);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 15);
            this.label1.TabIndex = 4;
            this.label1.Text = "시간";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(590, 253);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.setTimer);
            this.Controls.Add(this.timeLabel);
            this.Controls.Add(this.fontButton);
            this.Controls.Add(this.colorButton);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button colorButton;
        private System.Windows.Forms.Button fontButton;
        private System.Windows.Forms.Label timeLabel;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button setTimer;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Label label1;
    }
}

