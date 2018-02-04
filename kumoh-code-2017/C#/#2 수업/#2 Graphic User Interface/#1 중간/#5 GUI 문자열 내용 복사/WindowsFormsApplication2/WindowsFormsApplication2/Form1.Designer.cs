namespace cSharp_프로그래밍___20170914_2_GUI
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
            this.copyButton = new System.Windows.Forms.Button();
            this.input = new System.Windows.Forms.Label();
            this.copy = new System.Windows.Forms.Label();
            this.inputData = new System.Windows.Forms.TextBox();
            this.copyPrint = new System.Windows.Forms.TextBox();
            this.to_Red = new System.Windows.Forms.RadioButton();
            this.to_Green = new System.Windows.Forms.RadioButton();
            this.to_Blue = new System.Windows.Forms.RadioButton();
            this.color = new System.Windows.Forms.Label();
            this.isCopy = new System.Windows.Forms.Label();
            this.isEnable = new System.Windows.Forms.CheckBox();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // copyButton
            // 
            this.copyButton.Location = new System.Drawing.Point(551, 48);
            this.copyButton.Name = "copyButton";
            this.copyButton.Size = new System.Drawing.Size(75, 74);
            this.copyButton.TabIndex = 0;
            this.copyButton.Text = "복사";
            this.copyButton.UseVisualStyleBackColor = true;
            this.copyButton.Click += new System.EventHandler(this.copyButton_Click);
            // 
            // input
            // 
            this.input.AutoSize = true;
            this.input.Location = new System.Drawing.Point(35, 48);
            this.input.Name = "input";
            this.input.Size = new System.Drawing.Size(72, 15);
            this.input.TabIndex = 1;
            this.input.Text = "입력 내용";
            // 
            // copy
            // 
            this.copy.AutoSize = true;
            this.copy.Location = new System.Drawing.Point(35, 149);
            this.copy.Name = "copy";
            this.copy.Size = new System.Drawing.Size(72, 15);
            this.copy.TabIndex = 2;
            this.copy.Text = "복사 내용";
            // 
            // inputData
            // 
            this.inputData.Location = new System.Drawing.Point(139, 48);
            this.inputData.Name = "inputData";
            this.inputData.Size = new System.Drawing.Size(369, 25);
            this.inputData.TabIndex = 3;
            this.inputData.TextChanged += new System.EventHandler(this.inputData_TextChanged);
            // 
            // copyPrint
            // 
            this.copyPrint.BackColor = System.Drawing.Color.Black;
            this.copyPrint.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.copyPrint.ForeColor = System.Drawing.Color.Red;
            this.copyPrint.Location = new System.Drawing.Point(139, 139);
            this.copyPrint.Name = "copyPrint";
            this.copyPrint.Size = new System.Drawing.Size(487, 25);
            this.copyPrint.TabIndex = 4;
            this.copyPrint.Text = "복사될 내용을 여기에";
            this.copyPrint.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.copyPrint.TextChanged += new System.EventHandler(this.copyPrint_TextChanged);
            // 
            // to_Red
            // 
            this.to_Red.AutoSize = true;
            this.to_Red.ForeColor = System.Drawing.Color.Red;
            this.to_Red.Location = new System.Drawing.Point(3, 3);
            this.to_Red.Name = "to_Red";
            this.to_Red.Size = new System.Drawing.Size(54, 19);
            this.to_Red.TabIndex = 5;
            this.to_Red.TabStop = true;
            this.to_Red.Text = "Red";
            this.to_Red.UseVisualStyleBackColor = true;
            this.to_Red.CheckedChanged += new System.EventHandler(this.to_Red_CheckedChanged);
            // 
            // to_Green
            // 
            this.to_Green.AutoSize = true;
            this.to_Green.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.to_Green.Location = new System.Drawing.Point(3, 46);
            this.to_Green.Name = "to_Green";
            this.to_Green.Size = new System.Drawing.Size(67, 19);
            this.to_Green.TabIndex = 6;
            this.to_Green.TabStop = true;
            this.to_Green.Text = "Green";
            this.to_Green.UseVisualStyleBackColor = true;
            this.to_Green.CheckedChanged += new System.EventHandler(this.to_Green_CheckedChanged);
            // 
            // to_Blue
            // 
            this.to_Blue.AutoSize = true;
            this.to_Blue.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.to_Blue.Location = new System.Drawing.Point(3, 97);
            this.to_Blue.Name = "to_Blue";
            this.to_Blue.Size = new System.Drawing.Size(57, 19);
            this.to_Blue.TabIndex = 7;
            this.to_Blue.TabStop = true;
            this.to_Blue.Text = "Blue";
            this.to_Blue.UseVisualStyleBackColor = true;
            this.to_Blue.CheckedChanged += new System.EventHandler(this.to_Blue_CheckedChanged);
            // 
            // color
            // 
            this.color.AutoSize = true;
            this.color.Location = new System.Drawing.Point(41, 216);
            this.color.Name = "color";
            this.color.Size = new System.Drawing.Size(52, 15);
            this.color.TabIndex = 8;
            this.color.Text = "글자색";
            // 
            // isCopy
            // 
            this.isCopy.AutoSize = true;
            this.isCopy.Location = new System.Drawing.Point(41, 354);
            this.isCopy.Name = "isCopy";
            this.isCopy.Size = new System.Drawing.Size(67, 15);
            this.isCopy.TabIndex = 9;
            this.isCopy.Text = "복사기능";
            // 
            // isEnable
            // 
            this.isEnable.AutoSize = true;
            this.isEnable.Checked = true;
            this.isEnable.CheckState = System.Windows.Forms.CheckState.Checked;
            this.isEnable.Location = new System.Drawing.Point(136, 354);
            this.isEnable.Name = "isEnable";
            this.isEnable.Size = new System.Drawing.Size(137, 19);
            this.isEnable.TabIndex = 10;
            this.isEnable.Text = "Enable / Disable";
            this.isEnable.UseVisualStyleBackColor = true;
            this.isEnable.CheckedChanged += new System.EventHandler(this.isEnable_CheckedChanged);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.ForeColor = System.Drawing.SystemColors.ControlDark;
            this.radioButton1.Location = new System.Drawing.Point(15, 3);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(65, 19);
            this.radioButton1.TabIndex = 12;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "White";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.to_White_CheckedChanged);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.ForeColor = System.Drawing.Color.Black;
            this.radioButton2.Location = new System.Drawing.Point(15, 46);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(64, 19);
            this.radioButton2.TabIndex = 13;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "Black";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.to_Black_CheckedChanged);
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.ForeColor = System.Drawing.Color.Yellow;
            this.radioButton3.Location = new System.Drawing.Point(16, 94);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(69, 19);
            this.radioButton3.TabIndex = 14;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "Yellow";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.CheckedChanged += new System.EventHandler(this.to_Yellow_CheckedChanged);
            // 
            // backgroundWorker1
            // 
            this.backgroundWorker1.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker1_DoWork);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.to_Red);
            this.panel1.Controls.Add(this.to_Green);
            this.panel1.Controls.Add(this.to_Blue);
            this.panel1.Location = new System.Drawing.Point(139, 216);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(200, 132);
            this.panel1.TabIndex = 15;
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.radioButton1);
            this.panel2.Controls.Add(this.radioButton2);
            this.panel2.Controls.Add(this.radioButton3);
            this.panel2.Location = new System.Drawing.Point(426, 216);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(200, 129);
            this.panel2.TabIndex = 16;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(139, 402);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 17;
            this.button1.Text = "Show";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.show_button_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(341, 402);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 18;
            this.button2.Text = "Hide";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(551, 402);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 19;
            this.button3.Text = "Close";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(889, 471);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.isEnable);
            this.Controls.Add(this.isCopy);
            this.Controls.Add(this.color);
            this.Controls.Add(this.copyPrint);
            this.Controls.Add(this.inputData);
            this.Controls.Add(this.copy);
            this.Controls.Add(this.input);
            this.Controls.Add(this.copyButton);
            this.Name = "Form1";
            this.Text = "C# 프로그래밍";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button copyButton;
        private System.Windows.Forms.Label input;
        private System.Windows.Forms.Label copy;
        private System.Windows.Forms.TextBox inputData;
        private System.Windows.Forms.TextBox copyPrint;
        private System.Windows.Forms.RadioButton to_Red;
        private System.Windows.Forms.RadioButton to_Green;
        private System.Windows.Forms.RadioButton to_Blue;
        private System.Windows.Forms.Label color;
        private System.Windows.Forms.Label isCopy;
        private System.Windows.Forms.CheckBox isEnable;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
    }
}

