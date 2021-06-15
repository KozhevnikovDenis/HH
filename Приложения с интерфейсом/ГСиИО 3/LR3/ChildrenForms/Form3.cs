using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyCompany.Kozhevnikov.ChildrenForms
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();

            numericScan1.DecimalPlaces = numericScan2.DecimalPlaces = 2;
            numericScan1.Increment = numericScan2.Increment = 0.01M;
        }

        private void NumericScanOnValueChanged(object sender, EventArgs e)
        {
            label1.Text = "Первый: " + numericScan1.Value + "; Второй: " + numericScan2.Value;
        }
    }
}
