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
    public partial class Double : Form
    {
        public Double()
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


        private double numS1, numX1, numY1, numZ1, numS2, numX2, numY2, numZ2, numResultS, numResultX, numResultY, numResultZ, numResultScalar;

        private void button7_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Копируем текстовые поля в локальные переменные
            string strS1 = string.Copy(textBox1.Text);
            string strX1 = string.Copy(textBox2.Text);
            string strY1 = string.Copy(textBox3.Text);
            string strZ1 = string.Copy(textBox4.Text);
            string strS2 = string.Copy(textBox5.Text);
            string strX2 = string.Copy(textBox6.Text);
            string strY2 = string.Copy(textBox7.Text);
            string strZ2 = string.Copy(textBox8.Text);



            // Замена в строке точки символом запятой
            // для корректного преобразования в число
            int pos = strS1.IndexOf('.');
            if (pos != -1)
            {
                strS1 = strS1.Substring(0, pos)
                + ','
                + strS1.Substring(pos + 1);
            }
            pos = strX1.IndexOf('.');
            if (pos != -1)
            {
                strX1 = strX1.Substring(0, pos)
                + ','
                + strX1.Substring(pos + 1);
            }
            pos = strY1.IndexOf('.');
            if (pos != -1)
            {
                strY1 = strY1.Substring(0, pos)
                + ','
                + strY1.Substring(pos + 1);
            }
            pos = strZ1.IndexOf('.');
            if (pos != -1)
            {
                strZ1 = strZ1.Substring(0, pos)
                + ','
                + strZ1.Substring(pos + 1);
            }


            pos = strS2.IndexOf('.');
            if (pos != -1)
            {
                strS2 = strS2.Substring(0, pos)
                + ','
                + strS2.Substring(pos + 1);
            }
            pos = strX2.IndexOf('.');
            if (pos != -1)
            {
                strX2 = strX2.Substring(0, pos)
                + ','
                + strX2.Substring(pos + 1);
            }
            pos = strY2.IndexOf('.');
            if (pos != -1)
            {
                strY2 = strY2.Substring(0, pos)
                + ','
                + strY2.Substring(pos + 1);
            }
            pos = strZ2.IndexOf('.');
            if (pos != -1)
            {
                strZ2 = strZ2.Substring(0, pos)
                + ','
                + strZ2.Substring(pos + 1);
            }



            // Преобразуем текст в число для выполнения операций
            if (textBox1.Text.Length > 0)
                numS1 = Convert.ToDouble(strS1);
            else
                numS1 = 0.0D;
            if (textBox2.Text.Length > 0)
                numX1 = Convert.ToDouble(strX1);
            else
                numX1 = 0.0D;
            if (textBox3.Text.Length > 0)
                numY1 = Convert.ToDouble(strY1);
            else
                numY1 = 0.0D;
            if (textBox4.Text.Length > 0)
                numZ1 = Convert.ToDouble(strZ1);
            else
                numZ1 = 0.0D;


            if (textBox5.Text.Length > 0)
                numS2 = Convert.ToDouble(strS2);
            else
                numS2 = 0.0D;
            if (textBox6.Text.Length > 0)
                numX2 = Convert.ToDouble(strX2);
            else
                numX2 = 0.0D;
            if (textBox7.Text.Length > 0)
                numY2 = Convert.ToDouble(strY2);
            else
                numY2 = 0.0D;
            if (textBox8.Text.Length > 0)
                numZ2 = Convert.ToDouble(strZ2);
            else
                numZ2 = 0.0D;




            // Выполняем нужную операцию
            Button btn = (Button)sender;// Явное приведение типов для распознавания кнопок
            switch (btn.Name)// Переключатель
            {
                case "button1":
                    numResultS = numS1 + numS2;
                    numResultX = numX1 + numX2;
                    numResultY = numY1 + numY2;
                    numResultZ = numZ1 + numZ2;

                    // Отображение результата
                    textBox9.Text = Convert.ToString(numResultS);
                    textBox10.Text = Convert.ToString(numResultX);
                    textBox11.Text = Convert.ToString(numResultY);
                    textBox12.Text = Convert.ToString(numResultZ);
                    textBox13.Text = "";
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;
                case "button2":
                    numResultS = numS1 - numS2;
                    numResultX = numX1 - numX2;
                    numResultY = numY1 - numY2;
                    numResultZ = numZ1 - numZ2;

                    // Отображение результата
                    textBox9.Text = Convert.ToString(numResultS);
                    textBox10.Text = Convert.ToString(numResultX);
                    textBox11.Text = Convert.ToString(numResultY);
                    textBox12.Text = Convert.ToString(numResultZ);
                    textBox13.Text = "";
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;
                case "button3":
                    numResultS = numS1 * numS2 - numX1 * numX2 - numY1 * numY2 - numZ1 * numZ2;
                    numResultX = numS1 * numX2 + numS2 * numX1 + numY1 * numZ2 - numY2 * numZ1;
                    numResultY = numS1 * numY2 + numS2 * numY1 + numZ1 * numX2 - numZ2 * numX1;
                    numResultZ = numS1 * numZ2 + numS2 * numZ1 + numX1 * numY2 - numX2 * numY1;

                    // Отображение результата
                    textBox9.Text = Convert.ToString(numResultS);
                    textBox10.Text = Convert.ToString(numResultX);
                    textBox11.Text = Convert.ToString(numResultY);
                    textBox12.Text = Convert.ToString(numResultZ);
                    textBox13.Text = "";
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;
                case "button4":
                    numResultS = numS1 * (numS2 / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) - numX1 * ((-1 * numX2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) - numY1 * ((-1 * numY2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) - numZ1 * ((-1 * numZ2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2));
                    numResultX = numS1 * ((-1 * numX2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) + (numS2 / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) * numX1 + numY1 * ((-1 * numZ2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) - ((-1 * numY2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) * numZ1;
                    numResultY = numS1 * ((-1 * numY2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) + (numS2 / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) * numY1 + numZ1 * ((-1 * numX2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) - ((-1 * numZ2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) * numX1;
                    numResultZ = numS1 * ((-1 * numZ2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) + (numS2 / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) * numZ1 + numX1 * ((-1 * numY2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) - ((-1 * numX2) / (numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2)) * numY1;

                    // Отображение результата
                    textBox9.Text = Convert.ToString(numResultS);
                    textBox10.Text = Convert.ToString(numResultX);
                    textBox11.Text = Convert.ToString(numResultY);
                    textBox12.Text = Convert.ToString(numResultZ);
                    textBox13.Text = "";
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;
                case "button5":
                    numResultScalar = numS1 * numS2 + numX1 * numX2 + numY1 * numY2 + numZ1 * numZ2;

                    // Отображение результата
                    textBox9.Text = "";
                    textBox10.Text = "";
                    textBox11.Text = "";
                    textBox12.Text = "";
                    textBox13.Text = Convert.ToString(numResultScalar);
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;
                case "button6":
                    numResultScalar = System.Math.Acos((numS1 * numS2 + numX1 * numX2 + numY1 * numY2 + numZ1 * numZ2) / (System.Math.Sqrt(numS1 * numS1 + numX1 * numX1 + numY1 * numY1 + numZ1 * numZ1) * System.Math.Sqrt(numS2 * numS2 + numX2 * numX2 + numY2 * numY2 + numZ2 * numZ2))) * 180 / System.Math.PI;

                    // Отображение результата
                    textBox9.Text = "";
                    textBox10.Text = "";
                    textBox11.Text = "";
                    textBox12.Text = "";
                    textBox13.Text = Convert.ToString(numResultScalar);
                    this.Validate(); // Обновить экран (можно убрать-излишне)
                    break;

            }
        }
    }
}
