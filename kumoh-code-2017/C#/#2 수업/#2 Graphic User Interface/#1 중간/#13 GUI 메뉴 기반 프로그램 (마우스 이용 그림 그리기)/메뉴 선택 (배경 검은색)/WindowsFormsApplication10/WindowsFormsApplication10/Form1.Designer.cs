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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.프로그램ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.설정ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.색상ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.두께ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.빨강ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.파랑ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.녹색ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.배경검정색ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.배경흰색ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
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
            this.menuStrip1.Size = new System.Drawing.Size(635, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 프로그램ToolStripMenuItem
            // 
            this.프로그램ToolStripMenuItem.Name = "프로그램ToolStripMenuItem";
            this.프로그램ToolStripMenuItem.Size = new System.Drawing.Size(81, 24);
            this.프로그램ToolStripMenuItem.Text = "프로그램";
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
            // 두께ToolStripMenuItem
            // 
            this.두께ToolStripMenuItem.Name = "두께ToolStripMenuItem";
            this.두께ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.두께ToolStripMenuItem.Text = "두께";
            // 
            // 빨강ToolStripMenuItem
            // 
            this.빨강ToolStripMenuItem.Name = "빨강ToolStripMenuItem";
            this.빨강ToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl+R";
            this.빨강ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.빨강ToolStripMenuItem.Text = "빨강";
            // 
            // 파랑ToolStripMenuItem
            // 
            this.파랑ToolStripMenuItem.Name = "파랑ToolStripMenuItem";
            this.파랑ToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl+G";
            this.파랑ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.파랑ToolStripMenuItem.Text = "파랑";
            // 
            // 녹색ToolStripMenuItem
            // 
            this.녹색ToolStripMenuItem.Name = "녹색ToolStripMenuItem";
            this.녹색ToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl+B";
            this.녹색ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.녹색ToolStripMenuItem.Text = "녹색";
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
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(635, 417);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
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
    }
}

