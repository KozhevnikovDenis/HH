using System;
using System.Collections.Generic;
using System.ComponentModel;
//using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LR1
{
    public partial class InputPassword : Form
    {
        public InputPassword()
        {
            InitializeComponent();
        }

        public InputPassword(string windowTitle, string message)
        {
            InitializeComponent();

            this.Text = windowTitle;
            lblMessage.Text = message;
        }

        public static string Show(string windowTitle, string message)
        {
            using (InputPassword inputDlg = new InputPassword (windowTitle, message))
            {
                inputDlg.ShowDialog();
                return inputDlg.txtInput.Text;
            }
        }
    }
}
