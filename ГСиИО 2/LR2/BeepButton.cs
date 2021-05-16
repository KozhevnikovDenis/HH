using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;
using System.Windows.Forms;
using System.Media; // Для звука 


namespace MyCompany.UserControls
{
    public partial class BeepButton : Button
    {
        public BeepButton()
        {
            InitializeComponent();
        }

        public BeepButton(IContainer container)
        {
            container.Add(this);

            InitializeComponent();
        }
        protected override void OnClick(EventArgs e)
        {
            // Проиграть системный звук
            SystemSounds.Exclamation.Play();// Сочный через внешние динамики
            //SystemSounds.Beep.Play();     // Простой через внешние динамики
            //System.Console.Beep();        // Простой через внутренний динамик
                                            // Подняться до базового класса Control,
                                            // чтобы сгенерировать его событие Click и
                                            // запустить наш будущий обработчик ButtonOnClick
            base.OnClick(e);
        }
    }
}
