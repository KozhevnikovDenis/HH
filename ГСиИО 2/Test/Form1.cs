using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using MyCompany.UserControls;

namespace Test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void ButtonOnClick(object sender, EventArgs e)
        {
            string msg;

            if (textBox1.Text.Trim().Length == 0)
                msg = "Щелкнули на кнопке";
            else
                msg = textBox1.Text.Trim();

            // Запускаем наше диалоговое окно статическим методом
            MyDialogBox.Show(msg, this.Text);
        }
    }
}
