using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;
using System.Windows.Forms;

namespace MyCompany.Kozhevnikov
{
    public partial class ArrowButton : ClickmaticButton
    {
        public ArrowButton()
        {
            InitializeComponent();

            // Отключение фокуса ввода
            this.SetStyle(ControlStyles.Selectable, false);
        }

        public ArrowButton(IContainer container)
        {
            container.Add(this);

            InitializeComponent();

            // Отключение фокуса ввода
            this.SetStyle(ControlStyles.Selectable, false);
        }


        // Управление ориентацией стрелки на кнопке
        System.Windows.Forms.ScrollButton scrollButton = System.Windows.Forms.ScrollButton.Right;
        public System.Windows.Forms.ScrollButton ScrollButton
        {
            set
            {
                scrollButton = value;
                this.Invalidate(); // Перерисовать
            }
            get { return scrollButton; }
        }


        // Отрисовка кнопки в стиле со стрелкой
        protected override void OnPaint(PaintEventArgs pevent)
        {
            base.OnPaint(pevent); // Отправляем к базовому методу или вообще убираем!!!
            Graphics gr = pevent.Graphics; // Извлекаем контекст устройства
                                           // Кнопка в контакте с мышью и курсор находится в области чувствительности
            bool mouseInButton = this.Capture && this.ClientRectangle.Contains(this.PointToClient(MousePosition));
            // Флаг состояния кнопки для управления ее стилем отрисовки
            System.Windows.Forms.ButtonState buttonState = 
                !this.Enabled ? ButtonState.Inactive // Если кнопка недоступна
                : (mouseInButton ? ButtonState.Pushed // Если доступна и нажата
                : ButtonState.Normal); // Если доступна и отпущена
                                       // Рисуем кнопку как кнопку со стрелкой
            ControlPaint.DrawScrollButton(gr, this.ClientRectangle,
            scrollButton, // В какую сторону рисовать стрелку
            buttonState); // Каким стилем рисовать
        }


        // Повторяем отрисовку при потере или восстановлении контакта с мышью
        protected override void OnMouseCaptureChanged(EventArgs e)
        {
            base.OnMouseCaptureChanged(e);

            this.Invalidate(); // Инициировать перерисовку
        }
    }
}
