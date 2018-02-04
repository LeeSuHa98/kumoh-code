namespace WindowsFormsApplication10
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.프로그램ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.종료ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.설정ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.색상ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.빨강ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.파랑ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.녹색ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.배경검정색ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.배경흰색ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.두께ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButton6 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton5 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton4 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton3 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
            this.toolStripTextBox1 = new System.Windows.Forms.ToolStripTextBox();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.프로그램ToolStripMenuItem,
            this.설정ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(635, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 프로그램ToolStripMenuItem
            // 
            this.프로그램ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.종료ToolStripMenuItem});
            this.프로그램ToolStripMenuItem.Name = "프로그램ToolStripMenuItem";
            this.프로그램ToolStripMenuItem.Size = new System.Drawing.Size(81, 24);
            this.프로그램ToolStripMenuItem.Text = "프로그램";
            // 
            // 종료ToolStripMenuItem
            // 
            this.종료ToolStripMenuItem.Name = "종료ToolStripMenuItem";
            this.종료ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.종료ToolStripMenuItem.Text = "종료";
            this.종료ToolStripMenuItem.Click += new System.EventHandler(this.종료ToolStripMenuItem_Click);
            // 
            // 설정ToolStripMenuItem
            // 
            this.설정ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.색상ToolStripMenuItem,
            this.두께ToolStripMenuItem});
            this.설정ToolStripMenuItem.Name = "설정ToolStripMenuItem";
            this.설정ToolStripMenuItem.Size = new System.Drawing.Size(51, 24);
            this.설정ToolStripMenuItem.Text = "설정";
            // 
            // 색상ToolStripMenuItem
            // 
            this.색상ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.빨강ToolStripMenuItem,
            this.파랑ToolStripMenuItem,
            this.녹색ToolStripMenuItem,
            this.toolStripSeparator1,
            this.배경검정색ToolStripMenuItem,
            this.배경흰색ToolStripMenuItem});
            this.색상ToolStripMenuItem.Name = "색상ToolStripMenuItem";
            this.색상ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.색상ToolStripMenuItem.Text = "색상";
            // 
            // 빨강ToolStripMenuItem
            // 
            this.빨강ToolStripMenuItem.Name = "빨강ToolStripMenuItem";
            this.빨강ToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl+R";
            this.빨강ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.빨강ToolStripMenuItem.Text = "빨강";
            this.빨강ToolStripMenuItem.Click += new System.EventHandler(this.빨강ToolStripMenuItem_Click);
            // 
            // 파랑ToolStripMenuItem
            // 
            this.파랑ToolStripMenuItem.Name = "파랑ToolStripMenuItem";
            this.파랑ToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl+B";
            this.파랑ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.파랑ToolStripMenuItem.Text = "파랑";
            this.파랑ToolStripMenuItem.Click += new System.EventHandler(this.파랑ToolStripMenuItem_Click);
            // 
            // 녹색ToolStripMenuItem
            // 
            this.녹색ToolStripMenuItem.Name = "녹색ToolStripMenuItem";
            this.녹색ToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl+G";
            this.녹색ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.녹색ToolStripMenuItem.Text = "녹색";
            this.녹색ToolStripMenuItem.Click += new System.EventHandler(this.녹색ToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(178, 6);
            // 
            // 배경검정색ToolStripMenuItem
            // 
            this.배경검정색ToolStripMenuItem.Name = "배경검정색ToolStripMenuItem";
            this.배경검정색ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.배경검정색ToolStripMenuItem.Text = "배경 검정색";
            this.배경검정색ToolStripMenuItem.Click += new System.EventHandler(this.배경검정색ToolStripMenuItem_Click);
            // 
            // 배경흰색ToolStripMenuItem
            // 
            this.배경흰색ToolStripMenuItem.Name = "배경흰색ToolStripMenuItem";
            this.배경흰색ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.배경흰색ToolStripMenuItem.Text = "배경 흰색";
            this.배경흰색ToolStripMenuItem.Click += new System.EventHandler(this.배경흰색ToolStripMenuItem_Click);
            // 
            // 두께ToolStripMenuItem
            // 
            this.두께ToolStripMenuItem.Name = "두께ToolStripMenuItem";
            this.두께ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.두께ToolStripMenuItem.Text = "두께";
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton6,
            this.toolStripSeparator3,
            this.toolStripButton5,
            this.toolStripButton4,
            this.toolStripButton3,
            this.toolStripButton1,
            this.toolStripButton2,
            this.toolStripSeparator2,
            this.toolStripComboBox1,
            this.toolStripTextBox1});
            this.toolStrip1.Location = new System.Drawing.Point(0, 28);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(635, 28);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButton6
            // 
            this.toolStripButton6.BackColor = System.Drawing.Color.Red;
            this.toolStripButton6.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton6.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton6.Image")));
            this.toolStripButton6.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton6.Name = "toolStripButton6";
            this.toolStripButton6.Size = new System.Drawing.Size(23, 25);
            this.toolStripButton6.Text = "R";
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 28);
            // 
            // toolStripButton5
            // 
            this.toolStripButton5.BackColor = System.Drawing.Color.Blue;
            this.toolStripButton5.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton5.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton5.Image")));
            this.toolStripButton5.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton5.Name = "toolStripButton5";
            this.toolStripButton5.Size = new System.Drawing.Size(23, 25);
            this.toolStripButton5.Text = "B";
            // 
            // toolStripButton4
            // 
            this.toolStripButton4.BackColor = System.Drawing.Color.Lime;
            this.toolStripButton4.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton4.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton4.Image")));
            this.toolStripButton4.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton4.Name = "toolStripButton4";
            this.toolStripButton4.Size = new System.Drawing.Size(24, 25);
            this.toolStripButton4.Text = "G";
            // 
            // toolStripButton3
            // 
            this.toolStripButton3.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton3.Image")));
            this.toolStripButton3.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton3.Name = "toolStripButton3";
            this.toolStripButton3.Size = new System.Drawing.Size(24, 25);
            this.toolStripButton3.Text = "toolStripButton3";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(24, 25);
            this.toolStripButton1.Text = "toolStripButton1";
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(24, 25);
            this.toolStripButton2.Text = "toolStripButton2";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 28);
            // 
            // toolStripComboBox1
            // 
            this.toolStripComboBox1.Name = "toolStripComboBox1";
            this.toolStripComboBox1.Size = new System.Drawing.Size(121, 28);
            // 
            // toolStripTextBox1
            // 
            this.toolStripTextBox1.Name = "toolStripTextBox1";
            this.toolStripTextBox1.Size = new System.Drawing.Size(100, 28);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(635, 417);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 프로그램ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 설정ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 색상ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 빨강ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 파랑ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 두께ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 녹색ToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem 배경검정색ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 배경흰색ToolStripMenuItem;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripComboBox toolStripComboBox1;
        private System.Windows.Forms.ToolStripTextBox toolStripTextBox1;
        private System.Windows.Forms.ToolStripButton toolStripButton6;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripButton toolStripButton5;
        private System.Windows.Forms.ToolStripButton toolStripButton4;
        private System.Windows.Forms.ToolStripButton toolStripButton3;
        private System.Windows.Forms.ToolStripMenuItem 종료ToolStripMenuItem;
    }
}

