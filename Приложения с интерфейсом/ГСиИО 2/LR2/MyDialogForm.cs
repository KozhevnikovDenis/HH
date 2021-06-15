using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyCompany.UserControls
{
    public partial class MyDialogForm : Form
    {
        public MyDialogForm()
        {
            InitializeComponent();
        }

        private void btnShowDialog_Click(object sender, EventArgs e)
        {
            // Запускаем наше диалоговое окно статическим методом
            MyDialogBox.ShowAuthor("ADB-18-07 Kozhevnikov D.A.", "Author");
        }
    }
}
