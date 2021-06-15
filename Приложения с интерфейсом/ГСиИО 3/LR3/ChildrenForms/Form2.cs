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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();// Выполнение кода, сгенерированного
                                  // визуальным конструктором оболочки
                                  // в декларативном режиме проектирования
                                  // и расположенного в файле Form2.Designer.cs
            // Настройка ориентации стрелок на скроллирующих кнопках
            arrowButton1.ScrollButton = ScrollButton.Right;
            arrowButton2.ScrollButton = ScrollButton.Left;
            arrowButton3.ScrollButton = ScrollButton.Up;
            arrowButton4.ScrollButton = ScrollButton.Down;
        }
    }
}
