using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LR1
{
    public partial class Start : Form
    {
        public Start()
        {
            InitializeComponent();
        }

        private void Start_Load(object sender, EventArgs e)
        {
            string password = InputPassword.Show("Окно аутентификации пользователя", "Просим ввести Ваш пароль:");
            if (password != "root")// Плохой способ хранения пароля
            {
                MessageBox.Show("Извините, но Вам не разрешено\n" // Сообщение
                    + "пользоваться этой суперпрограммой!!!",
                    "Неверный пароль", // Заголовок окна
                    MessageBoxButtons.OK, // Кнопка OK
                    MessageBoxIcon.Stop); // Критическая иконка
                this.Close();
            }    
        }

        private void generalList_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (generalList.SelectedIndex + 1)
            {
                case 1:
                    Smiles frm1 = new Smiles();
                    frm1.ShowDialog();
                    break;
                case 2:
                    Calculate frm2 = new Calculate();
                    frm2.ShowDialog();
                    break;
            }

        }

        private void flow_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
