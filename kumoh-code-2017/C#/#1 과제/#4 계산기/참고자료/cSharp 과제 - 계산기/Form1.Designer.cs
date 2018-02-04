namespace cSharp_과제___계산기
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
            this.view = new System.Windows.Forms.TextBox();
            this.clear = new System.Windows.Forms.Button();
            this.Seven = new System.Windows.Forms.Button();
            this.Eight = new System.Windows.Forms.Button();
            this.Nine = new System.Windows.Forms.Button();
            this.Four = new System.Windows.Forms.Button();
            this.Five = new System.Windows.Forms.Button();
            this.Six = new System.Windows.Forms.Button();
            this.One = new System.Windows.Forms.Button();
            this.Two = new System.Windows.Forms.Button();
            this.Three = new System.Windows.Forms.Button();
            this.Open = new System.Windows.Forms.Button();
            this.Zero = new System.Windows.Forms.Button();
            this.Close = new System.Windows.Forms.Button();
            this.Divide = new System.Windows.Forms.Button();
            this.Multiply = new System.Windows.Forms.Button();
            this.subtract = new System.Windows.Forms.Button();
            this.Plus = new System.Windows.Forms.Button();
            this.Calculate = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // view
            // 
            this.view.Font = new System.Drawing.Font("굴림", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.view.Location = new System.Drawing.Point(49, 45);
            this.view.Name = "view";
            this.view.Size = new System.Drawing.Size(521, 45);
            this.view.TabIndex = 0;
            // 
            // clear
            // 
            this.clear.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.clear.Location = new System.Drawing.Point(49, 118);
            this.clear.Name = "clear";
            this.clear.Size = new System.Drawing.Size(521, 55);
            this.clear.TabIndex = 1;
            this.clear.Text = "Clear";
            this.clear.UseVisualStyleBackColor = true;
            this.clear.Click += new System.EventHandler(this.clear_Click);
            // 
            // Seven
            // 
            this.Seven.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Seven.Location = new System.Drawing.Point(49, 190);
            this.Seven.Name = "Seven";
            this.Seven.Size = new System.Drawing.Size(75, 59);
            this.Seven.TabIndex = 2;
            this.Seven.Text = "7";
            this.Seven.UseVisualStyleBackColor = true;
            this.Seven.Click += new System.EventHandler(this.Seven_Click);
            // 
            // Eight
            // 
            this.Eight.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Eight.Location = new System.Drawing.Point(130, 190);
            this.Eight.Name = "Eight";
            this.Eight.Size = new System.Drawing.Size(75, 59);
            this.Eight.TabIndex = 3;
            this.Eight.Text = "8";
            this.Eight.UseVisualStyleBackColor = true;
            this.Eight.Click += new System.EventHandler(this.Eight_Click);
            // 
            // Nine
            // 
            this.Nine.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Nine.Location = new System.Drawing.Point(211, 190);
            this.Nine.Name = "Nine";
            this.Nine.Size = new System.Drawing.Size(75, 59);
            this.Nine.TabIndex = 4;
            this.Nine.Text = "9";
            this.Nine.UseVisualStyleBackColor = true;
            this.Nine.Click += new System.EventHandler(this.Nine_Click);
            // 
            // Four
            // 
            this.Four.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Four.Location = new System.Drawing.Point(49, 255);
            this.Four.Name = "Four";
            this.Four.Size = new System.Drawing.Size(75, 59);
            this.Four.TabIndex = 5;
            this.Four.Text = "4";
            this.Four.UseVisualStyleBackColor = true;
            this.Four.Click += new System.EventHandler(this.Four_Click);
            // 
            // Five
            // 
            this.Five.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Five.Location = new System.Drawing.Point(130, 255);
            this.Five.Name = "Five";
            this.Five.Size = new System.Drawing.Size(75, 59);
            this.Five.TabIndex = 6;
            this.Five.Text = "5";
            this.Five.UseVisualStyleBackColor = true;
            this.Five.Click += new System.EventHandler(this.Five_Click);
            // 
            // Six
            // 
            this.Six.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Six.Location = new System.Drawing.Point(211, 255);
            this.Six.Name = "Six";
            this.Six.Size = new System.Drawing.Size(75, 59);
            this.Six.TabIndex = 7;
            this.Six.Text = "6";
            this.Six.UseVisualStyleBackColor = true;
            this.Six.Click += new System.EventHandler(this.Six_Click);
            // 
            // One
            // 
            this.One.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.One.Location = new System.Drawing.Point(49, 320);
            this.One.Name = "One";
            this.One.Size = new System.Drawing.Size(75, 59);
            this.One.TabIndex = 8;
            this.One.Text = "1";
            this.One.UseVisualStyleBackColor = true;
            this.One.Click += new System.EventHandler(this.One_Click);
            // 
            // Two
            // 
            this.Two.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Two.Location = new System.Drawing.Point(130, 320);
            this.Two.Name = "Two";
            this.Two.Size = new System.Drawing.Size(75, 59);
            this.Two.TabIndex = 9;
            this.Two.Text = "2";
            this.Two.UseVisualStyleBackColor = true;
            this.Two.Click += new System.EventHandler(this.Two_Click);
            // 
            // Three
            // 
            this.Three.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Three.Location = new System.Drawing.Point(211, 320);
            this.Three.Name = "Three";
            this.Three.Size = new System.Drawing.Size(75, 59);
            this.Three.TabIndex = 10;
            this.Three.Text = "3";
            this.Three.UseVisualStyleBackColor = true;
            this.Three.Click += new System.EventHandler(this.Three_Click);
            // 
            // Open
            // 
            this.Open.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Open.Location = new System.Drawing.Point(49, 385);
            this.Open.Name = "Open";
            this.Open.Size = new System.Drawing.Size(75, 59);
            this.Open.TabIndex = 11;
            this.Open.Text = "(";
            this.Open.UseVisualStyleBackColor = true;
            this.Open.Click += new System.EventHandler(this.Open_Click);
            // 
            // Zero
            // 
            this.Zero.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Zero.Location = new System.Drawing.Point(130, 385);
            this.Zero.Name = "Zero";
            this.Zero.Size = new System.Drawing.Size(75, 59);
            this.Zero.TabIndex = 12;
            this.Zero.Text = "0";
            this.Zero.UseVisualStyleBackColor = true;
            this.Zero.Click += new System.EventHandler(this.Zero_Click);
            // 
            // Close
            // 
            this.Close.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Close.Location = new System.Drawing.Point(211, 385);
            this.Close.Name = "Close";
            this.Close.Size = new System.Drawing.Size(75, 59);
            this.Close.TabIndex = 13;
            this.Close.Text = ")";
            this.Close.UseVisualStyleBackColor = true;
            this.Close.Click += new System.EventHandler(this.Close_Click);
            // 
            // Divide
            // 
            this.Divide.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Divide.Location = new System.Drawing.Point(307, 190);
            this.Divide.Name = "Divide";
            this.Divide.Size = new System.Drawing.Size(173, 59);
            this.Divide.TabIndex = 14;
            this.Divide.Text = "/";
            this.Divide.UseVisualStyleBackColor = true;
            this.Divide.Click += new System.EventHandler(this.Divide_Click);
            // 
            // Multiply
            // 
            this.Multiply.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Multiply.Location = new System.Drawing.Point(307, 255);
            this.Multiply.Name = "Multiply";
            this.Multiply.Size = new System.Drawing.Size(173, 59);
            this.Multiply.TabIndex = 15;
            this.Multiply.Text = "*";
            this.Multiply.UseVisualStyleBackColor = true;
            this.Multiply.Click += new System.EventHandler(this.Multiply_Click);
            // 
            // subtract
            // 
            this.subtract.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.subtract.Location = new System.Drawing.Point(307, 320);
            this.subtract.Name = "subtract";
            this.subtract.Size = new System.Drawing.Size(173, 59);
            this.subtract.TabIndex = 16;
            this.subtract.Text = "-";
            this.subtract.UseVisualStyleBackColor = true;
            this.subtract.Click += new System.EventHandler(this.subtract_Click);
            // 
            // Plus
            // 
            this.Plus.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Plus.Location = new System.Drawing.Point(307, 385);
            this.Plus.Name = "Plus";
            this.Plus.Size = new System.Drawing.Size(173, 59);
            this.Plus.TabIndex = 17;
            this.Plus.Text = "+";
            this.Plus.UseVisualStyleBackColor = true;
            this.Plus.Click += new System.EventHandler(this.Plus_Click);
            // 
            // Calculate
            // 
            this.Calculate.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Calculate.Location = new System.Drawing.Point(489, 190);
            this.Calculate.Name = "Calculate";
            this.Calculate.Size = new System.Drawing.Size(81, 254);
            this.Calculate.TabIndex = 18;
            this.Calculate.Text = "=";
            this.Calculate.UseVisualStyleBackColor = true;
            this.Calculate.Click += new System.EventHandler(this.Calculate_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(611, 497);
            this.Controls.Add(this.Calculate);
            this.Controls.Add(this.Plus);
            this.Controls.Add(this.subtract);
            this.Controls.Add(this.Multiply);
            this.Controls.Add(this.Divide);
            this.Controls.Add(this.Close);
            this.Controls.Add(this.Zero);
            this.Controls.Add(this.Open);
            this.Controls.Add(this.Three);
            this.Controls.Add(this.Two);
            this.Controls.Add(this.One);
            this.Controls.Add(this.Six);
            this.Controls.Add(this.Five);
            this.Controls.Add(this.Four);
            this.Controls.Add(this.Nine);
            this.Controls.Add(this.Eight);
            this.Controls.Add(this.Seven);
            this.Controls.Add(this.clear);
            this.Controls.Add(this.view);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox view;
        private System.Windows.Forms.Button clear;
        private System.Windows.Forms.Button Seven;
        private System.Windows.Forms.Button Eight;
        private System.Windows.Forms.Button Nine;
        private System.Windows.Forms.Button Four;
        private System.Windows.Forms.Button Five;
        private System.Windows.Forms.Button Six;
        private System.Windows.Forms.Button One;
        private System.Windows.Forms.Button Two;
        private System.Windows.Forms.Button Three;
        private System.Windows.Forms.Button Open;
        private System.Windows.Forms.Button Zero;
        private System.Windows.Forms.Button Close;
        private System.Windows.Forms.Button Divide;
        private System.Windows.Forms.Button Multiply;
        private System.Windows.Forms.Button subtract;
        private System.Windows.Forms.Button Plus;
        private System.Windows.Forms.Button Calculate;
    }
}

