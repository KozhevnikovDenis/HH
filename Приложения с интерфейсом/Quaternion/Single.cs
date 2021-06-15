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
    public partial class Single : Form
    {
        public Single()
        {
            InitializeComponent();
        }


        private bool isNumber = false;

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            isNumber = e.KeyCode >= Keys.D0 && e.KeyCode <= Keys.D9 // keyboard - основная клавиатура
            || e.KeyCode >= Keys.NumPad0 && e.KeyCode <= Keys.NumPad9 //keypad - дополнительная клавиатура
            || e.KeyCode == Keys.Back;

        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            TextBox box = (TextBox)sender;// Явное преобразование типов

            switch (e.KeyChar) // Переключатель
            {
                case '-': // Разрешаем минус, если он первый
                    if (box.Text.Length == 0)
                        isNumber = true;
                    break;
                case '.':
                    // Точка не должна быть первой
                    if (box.Text.Length == 0)
                        break;
                    // Точка не должна следовать сразу за минусом
                    if (box.Text[0] == '-' && box.Text.Length == 1)
                        break;
                    // Точка должна быть одна
                    if (box.Text.IndexOf('.') == -1)
                        isNumber = true; // Еще не было точек
                    break;
            }
            // Запрещаем в текстовом поле лишние символы
            if (!isNumber)
                e.Handled = true;
        }


        private double numS, numX, numY, numZ, numResultS, numResultX, numResultY, numResultZ, numResultScalar;

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Копируем текстовые поля в локальные переменные
            string strS = string.Copy(textBox1.Text);
            string strX = string.Copy(textBox2.Text);
            string strY = string.Copy(textBox3.Text);
            string strZ = string.Copy(textBox4.Text);



            // Замена в строке точки символом запятой
            // для корректного преобразования в число
            int pos = strS.IndexOf('.');
            if (pos != -1)
            {
                strS = strS.Substring(0, pos)
                + ','
                + strS.Substring(pos + 1);
            }
            pos = strX.IndexOf('.');
            if (pos != -1)
            {
                strX = strX.Substring(0, pos)
                + ','
                + strX.Substring(pos + 1);
            }
            pos = strY.IndexOf('.');
            if (pos != -1)
            {
                strY = strY.Substring(0, pos)
                + ','
                + strY.Substring(pos + 1);
            }
            pos = strZ.IndexOf('.');
            if (pos != -1)
            {
                strZ = strZ.Substring(0, pos)
                + ','
                + strZ.Substring(pos + 1);
            }


            // Преобразуем текст в число для выполнения операций
            if (textBox1.Text.Length > 0)
                numS = Convert.ToDouble(strS);
            else
                numS = 0.0D;
            if (textBox2.Text.Length > 0)
                numX = Convert.ToDouble(strX);
            else
                numX = 0.0D;
            if (textBox3.Text.Length > 0)
                numY = Convert.ToDouble(strY);
            else
                numY = 0.0D;
            if (textBox4.Text.Length > 0)
                numZ = Convert.ToDouble(strZ);
            else
                numZ = 0.0D;
            

            // Выполняем нужную операцию
            Button btn = (Button)sender;// Явное приведение типов для распознавания кнопок
            switch (btn.Name)// Переключатель
            {
                case "button1":
                    numResultS = numS;
                    numResultX = -1 * numX;
                    numResultY = -1 * numY;
                    numResultZ = -1 * numZ;

                    // Отображение результата
                    textBox5.Text = Convert.ToString(numResultS);
                    textBox6.Text = Convert.ToString(numResultX);
                    textBox7.Text = Convert.ToString(numResultY);
                    textBox8.Text = Convert.ToString(numResultZ);
                    textBox9.Text = "";
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;
                case "button2":
                    numResultScalar = System.Math.Sqrt(numS * numS + numX * numX + numY * numY + numZ * numZ);

                    // Отображение результата
                    textBox5.Text = "";
                    textBox6.Text = "";
                    textBox7.Text = "";
                    textBox8.Text = "";
                    textBox9.Text = Convert.ToString(numResultScalar);
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;
                case "button3":
                    numResultS = numS / (numS * numS + numX * numX + numY * numY + numZ * numZ);
                    numResultX = (-1 * numX) / (numS * numS + numX * numX + numY * numY + numZ * numZ);
                    numResultY = (-1 * numY) / (numS * numS + numX * numX + numY * numY + numZ * numZ);
                    numResultZ = (-1 * numZ) / (numS * numS + numX * numX + numY * numY + numZ * numZ);

                    // Отображение результата
                    textBox5.Text = Convert.ToString(numResultS);
                    textBox6.Text = Convert.ToString(numResultX);
                    textBox7.Text = Convert.ToString(numResultY);
                    textBox8.Text = Convert.ToString(numResultZ);
                    textBox9.Text = "";
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;
            }
        }
    }
}
