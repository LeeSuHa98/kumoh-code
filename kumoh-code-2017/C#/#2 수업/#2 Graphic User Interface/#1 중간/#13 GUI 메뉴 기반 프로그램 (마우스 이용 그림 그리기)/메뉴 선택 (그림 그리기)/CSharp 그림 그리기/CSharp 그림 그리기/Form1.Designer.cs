namespace CSharp_그림_그리기
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.프로그램ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.종료ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.설정ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.빨강ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.빨강ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.파랑ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.녹색ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.노랑ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.두께ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripTextBox1 = new System.Windows.Forms.ToolStripTextBox();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.menuStrip1.SuspendLayout();
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
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(7, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(623, 28);
            this.menuStrip1.TabIndex = 1;
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
            this.종료ToolStripMenuItem.Text = "종료(&Ctrl+x)";
            this.종료ToolStripMenuItem.Click += new System.EventHandler(this.종료ToolStripMenuItem_Click);
            // 
            // 설정ToolStripMenuItem
            // 
            this.설정ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.빨강ToolStripMenuItem,
            this.두께ToolStripMenuItem});
            this.설정ToolStripMenuItem.Name = "설정ToolStripMenuItem";
            this.설정ToolStripMenuItem.Size = new System.Drawing.Size(51, 24);
            this.설정ToolStripMenuItem.Text = "설정";
            this.설정ToolStripMenuItem.Click += new System.EventHandler(this.설정ToolStripMenuItem_Click);
            // 
            // 빨강ToolStripMenuItem
            // 
            this.빨강ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.빨강ToolStripMenuItem1,
            this.파랑ToolStripMenuItem1,
            this.녹색ToolStripMenuItem1,
            this.노랑ToolStripMenuItem1});
            this.빨강ToolStripMenuItem.Name = "빨강ToolStripMenuItem";
            this.빨강ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.빨강ToolStripMenuItem.Text = "색상";
            this.빨강ToolStripMenuItem.Click += new System.EventHandler(this.빨강ToolStripMenuItem_Click);
            // 
            // 빨강ToolStripMenuItem1
            // 
            this.빨강ToolStripMenuItem1.Checked = true;
            this.빨강ToolStripMenuItem1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.빨강ToolStripMenuItem1.Name = "빨강ToolStripMenuItem1";
            this.빨강ToolStripMenuItem1.Size = new System.Drawing.Size(168, 26);
            this.빨강ToolStripMenuItem1.Text = "빨강(&Red)";
            this.빨강ToolStripMenuItem1.Click += new System.EventHandler(this.빨강ToolStripMenuItem1_Click);
            // 
            // 파랑ToolStripMenuItem1
            // 
            this.파랑ToolStripMenuItem1.Name = "파랑ToolStripMenuItem1";
            this.파랑ToolStripMenuItem1.Size = new System.Drawing.Size(168, 26);
            this.파랑ToolStripMenuItem1.Text = "파랑(&Blue)";
            this.파랑ToolStripMenuItem1.Click += new System.EventHandler(this.파랑ToolStripMenuItem1_Click);
            // 
            // 녹색ToolStripMenuItem1
            // 
            this.녹색ToolStripMenuItem1.Name = "녹색ToolStripMenuItem1";
            this.녹색ToolStripMenuItem1.Size = new System.Drawing.Size(168, 26);
            this.녹색ToolStripMenuItem1.Text = "녹색(&Green)";
            this.녹색ToolStripMenuItem1.Click += new System.EventHandler(this.녹색ToolStripMenuItem1_Click);
            // 
            // 노랑ToolStripMenuItem1
            // 
            this.노랑ToolStripMenuItem1.CheckOnClick = true;
            this.노랑ToolStripMenuItem1.Name = "노랑ToolStripMenuItem1";
            this.노랑ToolStripMenuItem1.Size = new System.Drawing.Size(168, 26);
            this.노랑ToolStripMenuItem1.Text = "노랑(&Yellow)";
            this.노랑ToolStripMenuItem1.Click += new System.EventHandler(this.노랑ToolStripMenuItem1_Click);
            // 
            // 두께ToolStripMenuItem
            // 
            this.두께ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripTextBox1});
            this.두께ToolStripMenuItem.Name = "두께ToolStripMenuItem";
            this.두께ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.두께ToolStripMenuItem.Text = "두께";
            // 
            // toolStripTextBox1
            // 
            this.toolStripTextBox1.Name = "toolStripTextBox1";
            this.toolStripTextBox1.Size = new System.Drawing.Size(100, 27);
            this.toolStripTextBox1.Text = "2";
            this.toolStripTextBox1.Click += new System.EventHandler(this.toolStripTextBox1_Click);
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Location = new System.Drawing.Point(0, 28);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(623, 25);
            this.toolStrip1.TabIndex = 2;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(623, 364);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 프로그램ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 설정ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 빨강ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 빨강ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 파랑ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 녹색ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 노랑ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 두께ToolStripMenuItem;
        private System.Windows.Forms.ToolStripTextBox toolStripTextBox1;
        private System.Windows.Forms.ToolStripMenuItem 종료ToolStripMenuItem;
        private System.Windows.Forms.ToolStrip toolStrip1;
    }
}

