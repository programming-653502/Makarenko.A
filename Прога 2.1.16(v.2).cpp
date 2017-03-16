// Проге Лаб 2.1.16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
void input();
void output(int,int,int,int);
void pluss();
void minuss();
void umnog();
void delen();
void info();

int a1, b1, c1, d1, a2, b2, c2,d2,a3,b3,c3,d3;
int main()
{
	string s;

	setlocale(LC_ALL, "Russian");
a:cout << "Выберете,что нужно сделать:\n";
	cout << "1.Ввод двух полиномов 3 степени.\n";
	cout << "2.Вывод двух полиномов.\n";
	cout << "3.Сложение полиномов.\n";
	cout << "4.Вычитание полиномов.\n";
	cout << "5.Умножение полиномов.\n";
	cout << "6.Деление полиномов.\n";
	cout << "7.Информация о версии и авторе программы.\n";
	cout << "8.Выход из программы.\n";

	cin >> s;
	if (s.length() > 1) { cout << "Error! Недопустимый ввод!(Введена буква, используйте только цифры(от 1 до 8)) Попробуйте снова!\n"; goto a; }

	char q = char(s[0]);
	switch (q)
	{
	case '1': {break; }
	case '2': {break; }
	case '3': {break; }
	case '4': {break; }
	case '5': {break; }
	case '6': {break; }
	case '7': {break; }
	case '8': {break; }
	default: {cout << "Error! Недопустимый ввод!(Введена буква, используйте только цифры(от 1 до 8)) Попробуйте снова!\n"; goto a; }
	}
	int n = stoi(s);
	switch (n)
	{
	case 1:
	{	
		input();
		goto a;
	}
	case 2:
	{
		cout << "Полином 1-";
		output(a1, b1, c1, d1);
		cout << "Полином 2-";
		output(a2, b2, c2, d2);
		goto a;
	}
	case 3:
	{
		pluss();
		cout << "Ответ(сложения двух полиномов):";
		output(a3,b3,c3,d3);
		goto a;
	}
	case 4: 
	{
		minuss();
		cout << "Ответ(вычитание двух полиномов):";
		output(a3, b3, c3, d3);
		goto a;
	}
	case 5: 
	{
		umnog();
		goto a;
	}
	case 6: 
	{
		delen();
		goto a;
	}
	case 7: {info(); }
	case 8: {exit(0); }
	default: { cout << "Error! Недопустимый ввод!(Введена буква, используйте только цифры(от 1 до 8)) Попробуйте снова!\n"; goto a; }
	}
	system("pause");
	return 0;
}

void input()
{
	cout << "Полином имеет вид ax^3+bx^2+cx+d. Где a,b,c,d - коэфициенты.\n" << "Введите коэфициенты первого полинома:\n";
	cout << "a="; cin >> a1; 
	cout << "b="; cin >> b1; 
	cout << "c="; cin >> c1; 
	cout << "d="; cin >> d1;
	cout << "Введите коэфициенты второго полинома:\n";
	cout << "a="; cin >> a2;
	cout << "b="; cin >> b2;
	cout << "c="; cin >> c2;
	cout << "d="; cin >> d2;
}
void output(int q1,int w1, int e1, int r1)
{
	if (q1 != 0)cout << q1 << "x^3+";
	if (w1 != 0)cout << w1 << "x^2+";
	if (e1 != 0)cout << e1 << "x+";
	if (r1 != 0)cout << r1 << endl;	
}
void pluss() 
{
	a3 = a1 + a2;
	b3 = b1 + b2;
	c3 = c1 + c2;
	d3 = d1 + d2;
}

void minuss()
{
	cout << "Выберете что из чего вычитать:\n" << "1. Первый-Второй.\n"<<"2. Второй-Первый.\n"<<"Введите 1 или 2!\n";
	string s;
	k:cin >> s;
	
	if (s=="1")
	{
		a3 = a1 - a2;
		b3 = b1 - b2;
		c3 = c1 - c2;
		d3 = d1 - d2;
	} else
	if(s=="2")
	{
		a3 = a2 - a1;
		b3 = b2 - b1;
		c3 = c2 - c1;
		d3 = d2 - d1;
	}else
	{
		cout << " Неправильный ввод! Попробуйте снова!\n"; goto k;
	}
}
void umnog()
{
	cout << "Произведение полиномов=";
	if ((a1*a2) != 0) { cout << (a1*a2) << "x^6+"; }
	if ((a1*b2+a2*b1) != 0) { cout << (a1*b2 + a2*b1) << "x^5+"; }
	if ((a1*c2 + b2*b1+c1*a2) != 0) { cout << (a1*c2 + b2*b1 + c1*a2) << "x^4+"; }
	if ((a1*d2 + c2*b1 + c1*b2+d1*a2) != 0) { cout << (a1*d2 + c2*b1 + c1*b2 + d1*a2) << "x^3+"; }
	if ((d2*b1 + c1*c2 + d1*b2) != 0) { cout << (d2*b1 + c1*c2 + d1*b2) << "x^2+"; }
	if ((c1*d2+d1*c2) != 0) { cout << (c1*d2 + d1*c2) << "x+"; }
	if ((d1*d2) != 0) { cout << (d1*d2)<<endl; }
}
void delen()
{
	cout << "Деление полиномв=";
	a3 = a1 / a2;
	b3 = b1 / b2;
	c3 = c1 / c2;
	d3 = d1 / d2;
	output(a3,b3,c3,d3);
}

void info()
{
	cout << "Версия программы: Visual Studio 2017 RC Pro. Автор: Макаренко Андрей Дмитриевич." << endl;
}


