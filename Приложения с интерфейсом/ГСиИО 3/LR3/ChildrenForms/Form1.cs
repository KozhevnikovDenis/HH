using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyCompany.Kozhevnikov
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnClickGen_Click(object sender, EventArgs e)
        {
            int tickCount;
            if (!Int32.TryParse(lblTickCount.Text, out tickCount))
                tickCount = 1; // При некорректном преобразовании установить 1
            else
                tickCount++; // При корректоном преобразовании увеличить на 1

            lblTickCount.Text = tickCount.ToString();
        }
    }
}
