function Min()
{
    
    d=document
    var a = Number(d.form1.a.value)
    var b = Number(d.form1.b.value)
    var result = Math.min(a,b)
    d.form1.result.value=result
}

function Max()
{
    d=document
    var a = Number(d.form1.a.value)
    var b = Number(d.form1.b.value)
    var result = Math.max(a,b)
    d.form1.result.value=result
}

function Eq()
{
    d=document
    var a = Number(d.form1.a.value)
    var b = Number(d.form1.b.value)
    if(a==b)
    d.form1.result.value='Равны'
    if(a!=b)
    d.form1.result.value='Не равны'
}

function Yes()
{
    var name = 'Денис'
    var admin = name
    d=document
    d.form2.result.value=admin
}

function No()
{
    var name = 'Как хотите'
    var admin = name
    d=document
    d.form2.result.value=admin
}

function Age()
{    
    d=document
    var age = Number(d.form3.age.value)
    var cnfrm = confirm('Вы уверены?')
    if (cnfrm)
    alert('Ваш возраст: ' + age + ' сохранен')
    if (!cnfrm)
    alert('Введите возраст заново')
}

function Subm()
{
    var cnfrm = confirm('Вы уверены?')
    if (cnfrm)
    alert('Данные сохранены и отправлены')
    if (!cnfrm)
    alert('Сохранение и отправка прерваны')
}