using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Windows.Forms;

namespace MyCompany.UserControls
{
    public class MyDialogBox
    {
        public static DialogResult Show(string strMessage, string strCaption)
        {
            // Создаем диалоговое окно
            MyDialogForm frm = new MyDialogForm();
            // Заголовок окна
            frm.Text = strCaption;
            // Содержимое текстовой метки
            frm.lblMessage.Text = strMessage;
            // Отобразить диалоговое окно в модальном режиме,
            // а после его закрытия вернуть выбор пользователя
            // вызывающему коду
            return frm.ShowDialog();// Выполняем диалоговое окно
                                    // и возвращаем статус нажатой кнопки
        }

        public static DialogResult ShowAuthor(string strMessage, string strCaption)
        {
            // Создаем диалоговое окно
            MyDialogFormAuthor frm = new MyDialogFormAuthor();
            // Заголовок окна
            frm.Text = strCaption;
            // Содержимое текстовой метки
            frm.lblMessage.Text = strMessage;
            // Отобразить диалоговое окно в модальном режиме,
            // а после его закрытия вернуть выбор пользователя
            // вызывающему коду
            return frm.ShowDialog();// Выполняем диалоговое окно
                                    // и возвращаем статус нажатой кнопки
        }
    }
}
