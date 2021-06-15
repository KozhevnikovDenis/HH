
namespace CircleButtonTest
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.circleButton1 = new MyCompany.UserControls.CircleButton(this.components);
            this.circleButton2 = new MyCompany.UserControls.CircleButton(this.components);
            this.circleButton3 = new MyCompany.UserControls.CircleButton(this.components);
            this.SuspendLayout();
            // 
            // circleButton1
            // 
            this.circleButton1.AutoSize = true;
            this.circleButton1.Location = new System.Drawing.Point(176, 211);
            this.circleButton1.Margin = new System.Windows.Forms.Padding(15);
            this.circleButton1.Name = "circleButton1";
            this.circleButton1.Size = new System.Drawing.Size(100, 89);
            this.circleButton1.TabIndex = 0;
            this.circleButton1.Text = "circleButton1";
            this.circleButton1.UseVisualStyleBackColor = true;
            this.circleButton1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.circleButton_MouseClick);
            // 
            // circleButton2
            // 
            this.circleButton2.AutoSize = true;
            this.circleButton2.Location = new System.Drawing.Point(332, 211);
            this.circleButton2.Margin = new System.Windows.Forms.Padding(15);
            this.circleButton2.Name = "circleButton2";
            this.circleButton2.Size = new System.Drawing.Size(100, 89);
            this.circleButton2.TabIndex = 1;
            this.circleButton2.Text = "circleButton2";
            this.circleButton2.UseVisualStyleBackColor = true;
            this.circleButton2.MouseDown += new System.Windows.Forms.MouseEventHandler(this.circleButton_MouseClick);
            // 
            // circleButton3
            // 
            this.circleButton3.AutoSize = true;
            this.circleButton3.Location = new System.Drawing.Point(484, 211);
            this.circleButton3.Margin = new System.Windows.Forms.Padding(15);
            this.circleButton3.Name = "circleButton3";
            this.circleButton3.Size = new System.Drawing.Size(100, 89);
            this.circleButton3.TabIndex = 2;
            this.circleButton3.Text = "circleButton3";
            this.circleButton3.UseVisualStyleBackColor = true;
            this.circleButton3.MouseDown += new System.Windows.Forms.MouseEventHandler(this.circleButton_MouseClick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.circleButton3);
            this.Controls.Add(this.circleButton2);
            this.Controls.Add(this.circleButton1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private MyCompany.UserControls.CircleButton circleButton1;
        private MyCompany.UserControls.CircleButton circleButton2;
        private MyCompany.UserControls.CircleButton circleButton3;
    }
}

