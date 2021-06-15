namespace LR1
{
    partial class Smiles
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
            this.lblMessage = new System.Windows.Forms.Label();
            this.btnExit = new System.Windows.Forms.Button();
            this.picHappy = new System.Windows.Forms.PictureBox();
            this.picFrown = new System.Windows.Forms.PictureBox();
            this.picSmile = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.picHappy)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picFrown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picSmile)).BeginInit();
            this.SuspendLayout();
            // 
            // lblMessage
            // 
            this.lblMessage.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblMessage.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblMessage.ForeColor = System.Drawing.Color.Red;
            this.lblMessage.Location = new System.Drawing.Point(33, 139);
            this.lblMessage.Name = "lblMessage";
            this.lblMessage.Size = new System.Drawing.Size(360, 97);
            this.lblMessage.TabIndex = 3;
            this.lblMessage.Text = "Щелкайте на смайликах";
            this.lblMessage.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblMessage.Click += new System.EventHandler(this.label1_Click);
            // 
            // btnExit
            // 
            this.btnExit.AutoSize = true;
            this.btnExit.Location = new System.Drawing.Point(163, 284);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(100, 27);
            this.btnExit.TabIndex = 4;
            this.btnExit.Text = "Выход";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.button1_Click);
            // 
            // picHappy
            // 
            this.picHappy.Image = global::LR1.Properties.Resources._3;
            this.picHappy.Location = new System.Drawing.Point(293, 12);
            this.picHappy.Name = "picHappy";
            this.picHappy.Size = new System.Drawing.Size(100, 100);
            this.picHappy.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picHappy.TabIndex = 2;
            this.picHappy.TabStop = false;
            this.picHappy.Click += new System.EventHandler(this.picHappy_Click);
            // 
            // picFrown
            // 
            this.picFrown.Image = global::LR1.Properties.Resources._2;
            this.picFrown.Location = new System.Drawing.Point(163, 12);
            this.picFrown.Name = "picFrown";
            this.picFrown.Size = new System.Drawing.Size(100, 100);
            this.picFrown.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picFrown.TabIndex = 1;
            this.picFrown.TabStop = false;
            this.picFrown.Click += new System.EventHandler(this.picFrown_Click);
            // 
            // picSmile
            // 
            this.picSmile.Image = global::LR1.Properties.Resources._1;
            this.picSmile.Location = new System.Drawing.Point(33, 12);
            this.picSmile.Name = "picSmile";
            this.picSmile.Size = new System.Drawing.Size(100, 100);
            this.picSmile.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picSmile.TabIndex = 0;
            this.picSmile.TabStop = false;
            this.picSmile.Click += new System.EventHandler(this.picSmile_Click);
            // 
            // Smiles
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(427, 330);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.lblMessage);
            this.Controls.Add(this.picHappy);
            this.Controls.Add(this.picFrown);
            this.Controls.Add(this.picSmile);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Smiles";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Smiles - Упражнение №1";
            ((System.ComponentModel.ISupportInitialize)(this.picHappy)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picFrown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picSmile)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox picSmile;
        private System.Windows.Forms.PictureBox picFrown;
        private System.Windows.Forms.PictureBox picHappy;
        private System.Windows.Forms.Label lblMessage;
        private System.Windows.Forms.Button btnExit;
    }
}