using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MyCompany.Kozhevnikov.ChildrenForms;

namespace MyCompany.Kozhevnikov
{
    public partial class Start : Form
    {
        // Массив сообщений всплывающих подсказок для LinkLabel
        String[] strTips =
            {
                 "Тест для компонента кнопки,\n" +
                 "генерирующей щелчки мыши",
                 "Тест для компонента скроллирующей кнопки \n" +
                 "со стрелками, генерирующей щелчки мыши",
                 "Тест для компонента текстового \n" +
                 "поля со счетчиком"
            };

        // Массив ссылок для объектов всплывающих подсказок
        ToolTip[] tips =
            {
                 new ToolTip(),
                 new ToolTip(),
                 new ToolTip()
            };
        public Start()
        {
            InitializeComponent();

            // Привязка всплывающих подсказок к запускающим кнопкам
            tips[0].SetToolTip(Form1, strTips[0]);
            tips[1].SetToolTip(Form2, strTips[1]);
            tips[2].SetToolTip(Form3, strTips[2]);

            // Настройка ToolTip
            for (int i = 0; i < tips.Length; i++)
            {
                tips[i].IsBalloon = true;// Использовать окно подсказки
                tips[i].ToolTipIcon = ToolTipIcon.Info;// Иконки
                tips[i].ToolTipTitle = "Упражнение " + (i + 1); // Заголовок
                tips[i].ForeColor = Color.Magenta; // Цвет текста
                tips[i].BackColor = Color.LightGoldenrodYellow; // Цвет фона
            }
        }

        Form frm;

        private void OnLinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            // Повышаем полномочия ссылки и извлекаем закрепленное имя формы
            string formName = (string)((LinkLabel)sender).Tag;
            // Читаем коллекцию запущенных форм
            FormCollection fc = Application.OpenForms;
            bool IsRun = false;
            // Перебираем коллекцию
            foreach (Form form in fc)
            {
                // Имя очередной запущенной формы сравниваем с закрепленным за кнопкой
                if (form.Name == formName)
                {
                    IsRun = true; // Нашли, что форма запущена, поднимаем флаг
                    frm = form; // Сохраняем ссылку на запущенную форму для фокуса
                    break; // Выходим из цикла
                }
            }
            // Если форма не запущена - запускаем
            if (!IsRun)
            {
                switch (formName)
                {
                    case "Form1":
                        frm = new Form1();
                        break;
                    case "Form2":
                        frm = new Form2();
                        break;
                    case "Form3":
                        frm = new Form3();
                        break;
                }
                this.AddOwnedForm(frm); // Сделать новую frm подчиненной Start
             // frm.Owner = this; // Альтернативный способ назначить владельца
                frm.ShowInTaskbar = false; // Не отображать метку окна в панели задач
                frm.Show(); // Показать новую форму
            }
            else
                frm.Focus(); // Передать фокус запущенной форме
        }
    }
}
