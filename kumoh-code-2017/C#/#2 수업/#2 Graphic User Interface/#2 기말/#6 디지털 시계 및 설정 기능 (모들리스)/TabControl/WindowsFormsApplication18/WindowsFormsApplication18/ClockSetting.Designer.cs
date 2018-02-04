namespace WindowsFormsApplication18
{
    partial class ClockSetting
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.colorLabel = new System.Windows.Forms.Label();
            this.timeLabel = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.applyButton = new System.Windows.Forms.Button();
            this.closeButton = new System.Windows.Forms.Button();
            this.colorPage = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.timePage = new System.Windows.Forms.TabPage();
            this.colorPage.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.timePage.SuspendLayout();
            this.SuspendLayout();
            // 
            // colorLabel
            // 
            this.colorLabel.AutoSize = true;
            this.colorLabel.Location = new System.Drawing.Point(6, 28);
            this.colorLabel.Name = "colorLabel";
            this.colorLabel.Size = new System.Drawing.Size(37, 15);
            this.colorLabel.TabIndex = 0;
            this.colorLabel.Text = "색상";
            // 
            // timeLabel
            // 
            this.timeLabel.AutoSize = true;
            this.timeLabel.Location = new System.Drawing.Point(6, 29);
            this.timeLabel.Name = "timeLabel";
            this.timeLabel.Size = new System.Drawing.Size(53, 15);
            this.timeLabel.TabIndex = 1;
            this.timeLabel.Text = "24시간";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(65, 25);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 23);
            this.comboBox1.TabIndex = 2;
            // 
            // comboBox2
            // 
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Location = new System.Drawing.Point(65, 26);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(121, 23);
            this.comboBox2.TabIndex = 3;
            // 
            // applyButton
            // 
            this.applyButton.Location = new System.Drawing.Point(84, 147);
            this.applyButton.Name = "applyButton";
            this.applyButton.Size = new System.Drawing.Size(75, 23);
            this.applyButton.TabIndex = 4;
            this.applyButton.Text = "Apply";
            this.applyButton.UseVisualStyleBackColor = true;
            this.applyButton.Click += new System.EventHandler(this.applyButton_Click);
            // 
            // closeButton
            // 
            this.closeButton.Location = new System.Drawing.Point(165, 147);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(75, 23);
            this.closeButton.TabIndex = 5;
            this.closeButton.Text = "Close";
            this.closeButton.UseVisualStyleBackColor = true;
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // colorPage
            // 
            this.colorPage.Controls.Add(this.tabPage1);
            this.colorPage.Controls.Add(this.timePage);
            this.colorPage.Location = new System.Drawing.Point(63, 40);
            this.colorPage.Name = "colorPage";
            this.colorPage.SelectedIndex = 0;
            this.colorPage.Size = new System.Drawing.Size(200, 101);
            this.colorPage.TabIndex = 6;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.comboBox1);
            this.tabPage1.Controls.Add(this.colorLabel);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(192, 72);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Color";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // timePage
            // 
            this.timePage.Controls.Add(this.comboBox2);
            this.timePage.Controls.Add(this.timeLabel);
            this.timePage.Location = new System.Drawing.Point(4, 25);
            this.timePage.Name = "timePage";
            this.timePage.Padding = new System.Windows.Forms.Padding(3);
            this.timePage.Size = new System.Drawing.Size(192, 72);
            this.timePage.TabIndex = 1;
            this.timePage.Text = "Time";
            this.timePage.UseVisualStyleBackColor = true;
            // 
            // ClockSetting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(373, 294);
            this.Controls.Add(this.colorPage);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.applyButton);
            this.Name = "ClockSetting";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.colorPage.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.timePage.ResumeLayout(false);
            this.timePage.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label colorLabel;
        private System.Windows.Forms.Label timeLabel;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.Button applyButton;
        private System.Windows.Forms.Button closeButton;
        private System.Windows.Forms.TabControl colorPage;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage timePage;
    }
}