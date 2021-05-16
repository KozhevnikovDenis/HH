
namespace MyCompany.Kozhevnikov
{
    partial class Form2
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
            this.components = new System.ComponentModel.Container();
            this.arrowButton1 = new MyCompany.Kozhevnikov.ArrowButton(this.components);
            this.arrowButton2 = new MyCompany.Kozhevnikov.ArrowButton(this.components);
            this.arrowButton3 = new MyCompany.Kozhevnikov.ArrowButton(this.components);
            this.arrowButton4 = new MyCompany.Kozhevnikov.ArrowButton(this.components);
            this.SuspendLayout();
            // 
            // arrowButton1
            // 
            this.arrowButton1.Location = new System.Drawing.Point(214, 72);
            this.arrowButton1.Name = "arrowButton1";
            this.arrowButton1.ScrollButton = System.Windows.Forms.ScrollButton.Right;
            this.arrowButton1.Size = new System.Drawing.Size(75, 23);
            this.arrowButton1.TabIndex = 0;
            this.arrowButton1.Text = "arrowButton1";
            this.arrowButton1.UseVisualStyleBackColor = true;
            // 
            // arrowButton2
            // 
            this.arrowButton2.Location = new System.Drawing.Point(214, 119);
            this.arrowButton2.Name = "arrowButton2";
            this.arrowButton2.ScrollButton = System.Windows.Forms.ScrollButton.Right;
            this.arrowButton2.Size = new System.Drawing.Size(75, 23);
            this.arrowButton2.TabIndex = 1;
            this.arrowButton2.Text = "arrowButton2";
            this.arrowButton2.UseVisualStyleBackColor = true;
            // 
            // arrowButton3
            // 
            this.arrowButton3.Location = new System.Drawing.Point(214, 174);
            this.arrowButton3.Name = "arrowButton3";
            this.arrowButton3.ScrollButton = System.Windows.Forms.ScrollButton.Right;
            this.arrowButton3.Size = new System.Drawing.Size(75, 23);
            this.arrowButton3.TabIndex = 2;
            this.arrowButton3.Text = "arrowButton3";
            this.arrowButton3.UseVisualStyleBackColor = true;
            // 
            // arrowButton4
            // 
            this.arrowButton4.Location = new System.Drawing.Point(214, 229);
            this.arrowButton4.Name = "arrowButton4";
            this.arrowButton4.ScrollButton = System.Windows.Forms.ScrollButton.Right;
            this.arrowButton4.Size = new System.Drawing.Size(75, 23);
            this.arrowButton4.TabIndex = 3;
            this.arrowButton4.Text = "arrowButton4";
            this.arrowButton4.UseVisualStyleBackColor = true;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(488, 366);
            this.Controls.Add(this.arrowButton4);
            this.Controls.Add(this.arrowButton3);
            this.Controls.Add(this.arrowButton2);
            this.Controls.Add(this.arrowButton1);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);

        }

        #endregion

        private ArrowButton arrowButton1;
        private ArrowButton arrowButton2;
        private ArrowButton arrowButton3;
        private ArrowButton arrowButton4;
    }
}