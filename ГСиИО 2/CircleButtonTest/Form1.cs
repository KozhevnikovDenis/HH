using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using MyCompany.UserControls;

namespace CircleButtonTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void circleButton_MouseClick(object sender, MouseEventArgs e)
        {
            // Создаем псевдоним переданной ссылки
            CircleButton button = sender as CircleButton;
            if (button != null)
            {
                if (e.Button == MouseButtons.Left)
                    MessageBox.Show("Нажата ЛКМ. Нажата кнопка: " + button.Name);
                if (e.Button == MouseButtons.Right)
                    MessageBox.Show("Нажата ПКМ. Нажата кнопка: " + button.Name);
                if (e.Button == MouseButtons.Middle)
                    MessageBox.Show("Нажата СКМ. Нажата кнопка: " + button.Name);

            }
        }
    }
}
