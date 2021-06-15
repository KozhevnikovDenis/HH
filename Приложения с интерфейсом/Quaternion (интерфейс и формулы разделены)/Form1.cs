using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Quaternion
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Text = "Кватернионы – Кожевников Д.А. АДБ-18-07";
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (listBox1.SelectedIndex + 1)
            {
                case 1:
                    Single frm1 = new Single();
                    frm1.ShowDialog();
                    break;
                case 2:
                    Double frm2 = new Double();
                    frm2.ShowDialog();
                    break;
            }
        }
    }
}
