
namespace MyCompany.Kozhevnikov
{
    partial class Start
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
            this.Form1 = new System.Windows.Forms.LinkLabel();
            this.Form2 = new System.Windows.Forms.LinkLabel();
            this.Form3 = new System.Windows.Forms.LinkLabel();
            this.SuspendLayout();
            // 
            // Form1
            // 
            this.Form1.AutoSize = true;
            this.Form1.Location = new System.Drawing.Point(66, 40);
            this.Form1.Name = "Form1";
            this.Form1.Size = new System.Drawing.Size(213, 17);
            this.Form1.TabIndex = 0;
            this.Form1.TabStop = true;
            this.Form1.Tag = "Form1";
            this.Form1.Text = "Упражнение 1. ClickmaticButton";
            this.Form1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.OnLinkClicked);
            // 
            // Form2
            // 
            this.Form2.AutoSize = true;
            this.Form2.Location = new System.Drawing.Point(79, 100);
            this.Form2.Name = "Form2";
            this.Form2.Size = new System.Drawing.Size(187, 17);
            this.Form2.TabIndex = 1;
            this.Form2.TabStop = true;
            this.Form2.Tag = "Form2";
            this.Form2.Text = "Упражнение 2. ArrowButton";
            this.Form2.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.OnLinkClicked);
            // 
            // Form3
            // 
            this.Form3.AutoSize = true;
            this.Form3.Location = new System.Drawing.Point(75, 160);
            this.Form3.Name = "Form3";
            this.Form3.Size = new System.Drawing.Size(194, 17);
            this.Form3.TabIndex = 2;
            this.Form3.TabStop = true;
            this.Form3.Tag = "Form3";
            this.Form3.Text = "Упражнение 3. NumericScan";
            this.Form3.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.OnLinkClicked);
            // 
            // Start
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(344, 291);
            this.Controls.Add(this.Form3);
            this.Controls.Add(this.Form2);
            this.Controls.Add(this.Form1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "Start";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Lab3.Kozhevnikov";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.LinkLabel Form1;
        private System.Windows.Forms.LinkLabel Form2;
        private System.Windows.Forms.LinkLabel Form3;
    }
}