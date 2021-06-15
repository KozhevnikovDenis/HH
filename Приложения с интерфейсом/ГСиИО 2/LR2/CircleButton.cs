using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace MyCompany.UserControls
{
    public partial class CircleButton : Button
    {
        public CircleButton()
        {
            InitializeComponent();

            Init();
        }

        public CircleButton(IContainer container)
        {
            container.Add(this);

            InitializeComponent();

            Init();
        }

        // Начальные настройки для выполнения в конструкторе
        private void Init()
        {
            // Извещаем операционную систему, что будем сами
            // заботиться об отрисовке компонента
            this.SetStyle(ControlStyles.UserPaint, true);

            // Игнорировать системное сообщение WM_ERASEBKGND
            // очистки окна, чтобы уменьшить нежелательное мерцание
            this.SetStyle(ControlStyles.AllPaintingInWmPaint, true);

            // Наружный отступ по контуру кнопки
            this.Margin = new Padding(this.Font.Height);

            // Подстраиваться под размер надписи
            this.AutoSize = true;
        }

        // Вычисление контура кнопки при изменении ее размеров
        protected override void OnResize(EventArgs args)
        {
            // Объект для размещения контура
            GraphicsPath path = new GraphicsPath();

            // Размещаем эллипс
            path.AddEllipse(this.ClientRectangle);

            // Создаем объект рисования и адресуем его кнопке
            this.Region = new Region(path);

            // Вызываем предка для инициации OnPaint()
            // или Invalidate()
            base.OnResize(args);
            // this.Invalidate();
        }

        // Отрисовка круглой кнопки
        protected override void OnPaint(PaintEventArgs args)
        {
            // Адресовались к контексту графического устройства
            Graphics gr = args.Graphics;
            // Настраиваем качество рисования - сглаживать контуры
            gr.SmoothingMode = SmoothingMode.AntiAlias;

            // Флаг попадания курсора внутрь кнопки при ее нажатии
            bool bPressed = this.Capture & // Связь с мышью есть!
            ((Control.MouseButtons & MouseButtons.Left) != 0) & // Нажата левая кнопка мыши
            // Нажатый курсор попал внутрь описывающего прямоугольника
            this.ClientRectangle.
            Contains(this.PointToClient(Control.MousePosition));

            Rectangle rect = this.ClientRectangle; // Псевдоним// Отрисовка внутренней части кнопки
                                                   // При нажатии она становится темнее
            GraphicsPath path = new GraphicsPath();// Заготовили контур для заливки
            path.AddEllipse(rect); // Вписали эллипс в клиентскую область кнопки
            PathGradientBrush gradient = new PathGradientBrush(path);// Создали градиент для заливки
            int k = bPressed ? 2 : 1;// Для нажатой кнопки сдвинем центр градиента вправо и вниз
                                     // Располагаем центр радиального градиента левее и выше центра кнопки
            gradient.CenterPoint = new PointF(
            k * (rect.Left + rect.Right) / 3,
            k * (rect.Top + rect.Bottom) / 3);
            // Настраиваем цвет радиального градиента
            gradient.CenterColor = bPressed ? Color.PowderBlue : Color.White;// Центр
            gradient.SurroundColors = new Color[] { Color.SkyBlue };// Окраина
            gr.FillRectangle(gradient, rect); // Залить градиентом
                                              // Отрисовка контура кнопки, утолщенного для активных кнопок
                                              // Создаем кисть с линейным градиентом, изменяющимся по диагонали
            Brush brush = new LinearGradientBrush(
            rect,
            Color.FromArgb(0, 0, 255),
            Color.FromArgb(0, 0, 128),
            LinearGradientMode.ForwardDiagonal);
            // Создаем перо для рисования градиентной кистью
            Pen pen = new Pen(
            brush,
            (this.IsDefault ? 3 : 1) * gr.DpiX / 72);// Если кнопка имеет фокус ввода - контур толще
            gr.DrawEllipse(pen, rect); // Нарисовать контур

            // Отображение надписи в центре прямоугольника кнопки
            // Для недоступной кнопки цвет надписи должен быть бледносерым
            StringFormat strFormat = new StringFormat();
            // Определение точки привязки в центре текстового блока
            strFormat.Alignment =
            strFormat.LineAlignment =
            StringAlignment.Center;
            brush = this.Enabled ? SystemBrushes.WindowText // Для активной
            : SystemBrushes.GrayText;// Для неактивной
            gr.DrawString(this.Text, this.Font, brush, rect, strFormat);

            // Отображение пунктира вокруг текста, если кнопка имеет фокус
            if (this.Focused)
            {
                SizeF sizeText = gr.MeasureString(
                this.Text,
                this.Font,
                PointF.Empty,
                StringFormat.GenericTypographic);
                pen = new Pen(this.ForeColor);// Текущий цвет
                pen.DashStyle = DashStyle.Dash;// Пунктир
                gr.DrawRectangle(
                pen,
                rect.Left + rect.Width / 2 - sizeText.Width / 2,
                rect.Top + rect.Height / 2 - sizeText.Height / 2,
                sizeText.Width,
                sizeText.Height);
            }

            // Метод диспетчеризации своего события - для тренировки
            if (this.Paint != null)// Если есть хоть одна подписка
                this.Paint(this, args);// Инициируем событие

        }
        new public event PaintEventHandler Paint;// Объявляем свое событие в классе
    }
}
