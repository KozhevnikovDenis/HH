
namespace MyCompany.Kozhevnikov.ChildrenForms
{
    partial class Form3
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
            this.label1 = new System.Windows.Forms.Label();
            this.numericScan2 = new MyCompany.Kozhevnikov.NumericScan(this.components);
            this.numericScan1 = new MyCompany.Kozhevnikov.NumericScan(this.components);
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(362, 106);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "label1";
            // 
            // numericScan2
            // 
            this.numericScan2.DecimalPlaces = 0;
            this.numericScan2.Increment = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericScan2.Location = new System.Drawing.Point(464, 181);
            this.numericScan2.Maximum = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numericScan2.Minimum = new decimal(new int[] {
            0,
            0,
            0,
            0});
            this.numericScan2.Name = "numericScan2";
            this.numericScan2.Size = new System.Drawing.Size(147, 43);
            this.numericScan2.TabIndex = 1;
            this.numericScan2.Value = new decimal(new int[] {
            0,
            0,
            0,
            0});
            this.numericScan2.ValueChanged += new System.EventHandler(this.NumericScanOnValueChanged);
            // 
            // numericScan1
            // 
            this.numericScan1.DecimalPlaces = 0;
            this.numericScan1.Increment = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericScan1.Location = new System.Drawing.Point(235, 181);
            this.numericScan1.Maximum = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numericScan1.Minimum = new decimal(new int[] {
            0,
            0,
            0,
            0});
            this.numericScan1.Name = "numericScan1";
            this.numericScan1.Size = new System.Drawing.Size(139, 43);
            this.numericScan1.TabIndex = 0;
            this.numericScan1.Value = new decimal(new int[] {
            0,
            0,
            0,
            0});
            this.numericScan1.ValueChanged += new System.EventHandler(this.NumericScanOnValueChanged);
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericScan2);
            this.Controls.Add(this.numericScan1);
            this.Name = "Form3";
            this.Text = "Form3";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private NumericScan numericScan1;
        private NumericScan numericScan2;
        private System.Windows.Forms.Label label1;
    }
}