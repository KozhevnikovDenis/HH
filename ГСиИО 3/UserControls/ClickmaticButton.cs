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
    public partial class ClickmaticButton : Button// : Component
    {
        public ClickmaticButton()
        {
            InitializeComponent();
        }

        public ClickmaticButton(IContainer container)
        {
            container.Add(this);

            InitializeComponent();
        }


        // Переопределение унаследованного метода диспетчеризации
        // события MouseMove увода курсора за область чувствительности элемента
        protected override void OnMouseMove(MouseEventArgs mevent)
        {
            base.OnMouseMove(mevent);

            // Приостанавливаем или возобнавляем запущенный таймер логическим выражением
            timer.Enabled = this.Capture
            // Связь с мышью установлена
            && (MouseButtons & MouseButtons.Left) != 0
            // Распознавать левую кнопку необязательно
            && this.ClientRectangle.Contains(mevent.Location)
            // Курсор над кнопкой
            && this.ClientRectangle.Contains(this.PointToClient(MousePosition));
            // То же самое!
        }


        // Переопределение унаследованного метода диспетчеризации
        // события MouseDown нажатия кнопки мыши для запуска таймера
        protected override void OnMouseDown(MouseEventArgs mevent)
        {
            base.OnMouseDown(mevent); // Отправляем к базовому методу

            // Если нажата левая кнопка мыши (побитовое умножение)
            if ((mevent.Button & MouseButtons.Left) != 0)
            {
                timer.Interval = DELAY; // Задержка для момента нажатия
                timer.Start(); // Запустить таймер
            }
        }


        // Поля характеристик работы таймера
        readonly int DELAY = 250 * (1 + SystemInformation.KeyboardDelay);
        readonly int SPEED = 405 - 12 * SystemInformation.KeyboardSpeed;

        private void timer_Tick(object sender, EventArgs e)
        {
            timer.Interval = SPEED; // Устанавливаем новый интервал генерации тиков
            this.OnClick(EventArgs.Empty); // Генерируем щелчок на элементе кнопки с пустым фактическим параметром
        }

        // Переопределение унаследованного метода диспетчеризации
        // события MouseUp отпускания кнопки мыши для остановки таймера
        protected override void OnMouseUp(MouseEventArgs mevent)
        {
            base.OnMouseUp(mevent); // Отправляем к базовому методу

            timer.Stop(); // Стоп таймер
        }
    }
}
