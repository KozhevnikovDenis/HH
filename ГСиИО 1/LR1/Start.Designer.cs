namespace LR1
{
    partial class Start
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
            this.flow = new System.Windows.Forms.FlowLayoutPanel();
            this.generalList = new System.Windows.Forms.ListBox();
            this.flow.SuspendLayout();
            this.SuspendLayout();
            // 
            // flow
            // 
            this.flow.AutoSize = true;
            this.flow.Controls.Add(this.generalList);
            this.flow.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flow.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.flow.Location = new System.Drawing.Point(0, 0);
            this.flow.Name = "flow";
            this.flow.Padding = new System.Windows.Forms.Padding(8);
            this.flow.Size = new System.Drawing.Size(430, 203);
            this.flow.TabIndex = 0;
            this.flow.WrapContents = false;
            // 
            // generalList
            // 
            this.generalList.FormattingEnabled = true;
            this.generalList.ItemHeight = 16;
            this.generalList.Items.AddRange(new object[] {
            "1) Простое диалоговое окно со смайликами",
            "2) Простой калькулятор"});
            this.generalList.Location = new System.Drawing.Point(11, 11);
            this.generalList.Name = "generalList";
            this.generalList.Size = new System.Drawing.Size(407, 100);
            this.generalList.TabIndex = 1;
            this.generalList.SelectedIndexChanged += new System.EventHandler(this.generalList_SelectedIndexChanged);
            // 
            // Start
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(430, 203);
            this.Controls.Add(this.flow);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "Start";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "LR1 - Kozhevnikov D.A.";
            this.Load += new System.EventHandler(this.Start_Load);
            this.flow.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.FlowLayoutPanel flow;
        private System.Windows.Forms.ListBox generalList;
    }
}

