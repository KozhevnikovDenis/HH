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
    public partial class Smiles : Form
    {
        public Smiles()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close(); // Закрыть форму
        }

        private void picFrown_Click(object sender, EventArgs e)
        {
            picSmile.BorderStyle = BorderStyle.None; // Нет рамки
            picFrown.BorderStyle = BorderStyle.FixedSingle; // Рамка
            picHappy.BorderStyle = BorderStyle.None; // Нет рамки
            lblMessage.Text = "Щелкнули на втором рисунке";

            Random rnd = new Random((int)DateTime.Now.Ticks);
            picSmile.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))));
            picHappy.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))));

        }

        private void picSmile_Click(object sender, EventArgs e)
        {
            picSmile.BorderStyle = BorderStyle.FixedSingle; // Рамка
            picFrown.BorderStyle = BorderStyle.None; // Нет рамки
            picHappy.BorderStyle = BorderStyle.None; // Нет рамки
            lblMessage.Text = "Щелкнули на первом рисунке";

            Random rnd = new Random((int)DateTime.Now.Ticks);
            picFrown.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))));
            picHappy.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))));


        }

        private void picHappy_Click(object sender, EventArgs e)
        {
            picSmile.BorderStyle = BorderStyle.None; // Нет рамки
            picFrown.BorderStyle = BorderStyle.None; // Нет рамки
            picHappy.BorderStyle = BorderStyle.FixedSingle; // Рамка
            lblMessage.Text = "Щелкнули на третьем рисунке";

            Random rnd = new Random((int)DateTime.Now.Ticks);
            picFrown.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))));
            picSmile.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))), ((int)(((byte)(rnd.Next(0, 256))))));

        }

        private void btnExit_Click(object sender, System.EventArgs e)
        {
            this.Close(); // Закрыть форму
        }

        static void Main()
        {
            Application.Run(new Smiles());
        }
    }
}
