
namespace LR1
{
    partial class Calculate
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
            this.lblFirst = new System.Windows.Forms.Label();
            this.lblSecond = new System.Windows.Forms.Label();
            this.lblResult = new System.Windows.Forms.Label();
            this.txtFirst = new System.Windows.Forms.TextBox();
            this.txtSecond = new System.Windows.Forms.TextBox();
            this.txtResult = new System.Windows.Forms.TextBox();
            this.btnIncrement = new System.Windows.Forms.Button();
            this.btnDecrement = new System.Windows.Forms.Button();
            this.btnIncrease = new System.Windows.Forms.Button();
            this.btnDivide = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.buttonequal = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblFirst
            // 
            this.lblFirst.AutoSize = true;
            this.lblFirst.Location = new System.Drawing.Point(12, 9);
            this.lblFirst.Name = "lblFirst";
            this.lblFirst.Size = new System.Drawing.Size(104, 17);
            this.lblFirst.TabIndex = 0;
            this.lblFirst.Text = "Первое число:";
            this.lblFirst.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblSecond
            // 
            this.lblSecond.AutoSize = true;
            this.lblSecond.Location = new System.Drawing.Point(12, 52);
            this.lblSecond.Name = "lblSecond";
            this.lblSecond.Size = new System.Drawing.Size(103, 17);
            this.lblSecond.TabIndex = 1;
            this.lblSecond.Text = "Второе число:";
            this.lblSecond.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblResult
            // 
            this.lblResult.AutoSize = true;
            this.lblResult.Location = new System.Drawing.Point(35, 193);
            this.lblResult.Name = "lblResult";
            this.lblResult.Size = new System.Drawing.Size(80, 17);
            this.lblResult.TabIndex = 2;
            this.lblResult.Text = "Результат:";
            this.lblResult.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // txtFirst
            // 
            this.txtFirst.Location = new System.Drawing.Point(122, 6);
            this.txtFirst.Name = "txtFirst";
            this.txtFirst.Size = new System.Drawing.Size(178, 22);
            this.txtFirst.TabIndex = 3;
            this.txtFirst.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtFirst_KeyDown);
            this.txtFirst.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtFirst_KeyPress);
            // 
            // txtSecond
            // 
            this.txtSecond.Location = new System.Drawing.Point(122, 49);
            this.txtSecond.Name = "txtSecond";
            this.txtSecond.Size = new System.Drawing.Size(178, 22);
            this.txtSecond.TabIndex = 4;
            this.txtSecond.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtFirst_KeyDown);
            this.txtSecond.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtFirst_KeyPress);
            // 
            // txtResult
            // 
            this.txtResult.Location = new System.Drawing.Point(122, 190);
            this.txtResult.Name = "txtResult";
            this.txtResult.ReadOnly = true;
            this.txtResult.Size = new System.Drawing.Size(178, 22);
            this.txtResult.TabIndex = 5;
            this.txtResult.TabStop = false;
            // 
            // btnIncrement
            // 
            this.btnIncrement.Font = new System.Drawing.Font("Courier New", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnIncrement.Location = new System.Drawing.Point(122, 98);
            this.btnIncrement.Name = "btnIncrement";
            this.btnIncrement.Size = new System.Drawing.Size(40, 40);
            this.btnIncrement.TabIndex = 6;
            this.btnIncrement.Text = "+";
            this.btnIncrement.UseVisualStyleBackColor = true;
            this.btnIncrement.Click += new System.EventHandler(this.btn_Click);
            // 
            // btnDecrement
            // 
            this.btnDecrement.Font = new System.Drawing.Font("Courier New", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnDecrement.Location = new System.Drawing.Point(168, 98);
            this.btnDecrement.Name = "btnDecrement";
            this.btnDecrement.Size = new System.Drawing.Size(40, 40);
            this.btnDecrement.TabIndex = 7;
            this.btnDecrement.Text = "-";
            this.btnDecrement.UseVisualStyleBackColor = true;
            this.btnDecrement.Click += new System.EventHandler(this.btn_Click);
            // 
            // btnIncrease
            // 
            this.btnIncrease.Font = new System.Drawing.Font("Courier New", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnIncrease.Location = new System.Drawing.Point(214, 98);
            this.btnIncrease.Name = "btnIncrease";
            this.btnIncrease.Size = new System.Drawing.Size(40, 40);
            this.btnIncrease.TabIndex = 8;
            this.btnIncrease.Text = "*";
            this.btnIncrease.UseVisualStyleBackColor = true;
            this.btnIncrease.Click += new System.EventHandler(this.btn_Click);
            // 
            // btnDivide
            // 
            this.btnDivide.Font = new System.Drawing.Font("Courier New", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnDivide.Location = new System.Drawing.Point(260, 98);
            this.btnDivide.Name = "btnDivide";
            this.btnDivide.Size = new System.Drawing.Size(40, 40);
            this.btnDivide.TabIndex = 9;
            this.btnDivide.Text = "/";
            this.btnDivide.UseVisualStyleBackColor = true;
            this.btnDivide.Click += new System.EventHandler(this.btn_Click);
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(121, 238);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 10;
            this.btnExit.Text = "Выход";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // buttonequal
            // 
            this.buttonequal.Font = new System.Drawing.Font("Courier New", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonequal.Location = new System.Drawing.Point(168, 144);
            this.buttonequal.Name = "buttonequal";
            this.buttonequal.Size = new System.Drawing.Size(86, 40);
            this.buttonequal.TabIndex = 11;
            this.buttonequal.Text = "=";
            this.buttonequal.UseVisualStyleBackColor = true;
            this.buttonequal.Click += new System.EventHandler(this.buttonequal_Click);
            // 
            // Calculate
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(317, 273);
            this.Controls.Add(this.buttonequal);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnDivide);
            this.Controls.Add(this.btnIncrease);
            this.Controls.Add(this.btnDecrement);
            this.Controls.Add(this.btnIncrement);
            this.Controls.Add(this.txtResult);
            this.Controls.Add(this.txtSecond);
            this.Controls.Add(this.txtFirst);
            this.Controls.Add(this.lblResult);
            this.Controls.Add(this.lblSecond);
            this.Controls.Add(this.lblFirst);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "Calculate";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Простой калькулятор";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblFirst;
        private System.Windows.Forms.Label lblSecond;
        private System.Windows.Forms.Label lblResult;
        private System.Windows.Forms.TextBox txtFirst;
        private System.Windows.Forms.TextBox txtSecond;
        private System.Windows.Forms.TextBox txtResult;
        private System.Windows.Forms.Button btnIncrement;
        private System.Windows.Forms.Button btnDecrement;
        private System.Windows.Forms.Button btnIncrease;
        private System.Windows.Forms.Button btnDivide;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Button buttonequal;
    }
}