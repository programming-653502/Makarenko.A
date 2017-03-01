// Прога.Лаба1.2.16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
string number(int);
string ten(int);
string hundred(int);
int main()
{
	setlocale(LC_ALL,"Russian");
	string j = "";
	string s;
	int k=0;
	a:cout << "Введите целое число(от -999 до 999)!\n";
	cin >> s;
	int o = 0;
	if (s.length()<=4)
	for (int i = s.length() - 1; i >= 0; i--,o++)
	{
		char q = char(s[i]);
		switch (q)
		{
		/* case '0': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '1': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '2': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '3': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '4': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '5': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '6': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '7': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '8': {k = k + int(s[i])*int(pow(10, o)); break; }
		case '9': {k = k + int(s[i])*int(pow(10, o)); break; }
		*/
		case '0': {break; }
		case '1': {break; }
		case '2': {break; }
		case '3': {break; }
		case '4': {break; }
		case '5': {break; }
		case '6': {break; }
		case '7': {break; }
		case '8': {break; }
		case '9': {break; }
		case '-': 
		{
		j = "-"; 
		s.erase(i, 1);
		break; 
		}
		default: {cout << "Error! Недопустимый ввод!(Введена буква, используйте только цифры(от 0 до 9)) Попробуйте снова!\n"; goto a; }
		} 
	}
	else
	{
		cout << "Error! Недопустимый ввод! Попробуйте снова!\n";
		goto a;
	}                  
	k = stoi(s);
	s = "";
	cout << j;
	if (k / 100 != 0)
	{
		s = s + hundred(k/100);
		k = k % 100;
	}
	if (k / 10 != 0)
	{
		s = s + ten(k/10);
		k = k % 10;
	}
	s=s+number(k);
	cout << s;
	system("pause");
	return 0;
}
string number(int k)
{
	string s = "";
	if (k > 0)
	{
		int m = k % 10;
		switch (m)
		{
		case 1: {s = "I"; break; }
		case 2: {s = "II"; break; }
		case 3: {s = "III"; break; }
		case 4: {s = "IV"; break; }
		case 5: {s = "V"; break; }
		case 6: {s = "VI"; break; }
		case 7: {s = "VII"; break; }
		case 8: {s = "VIII"; break; }
		case 9: {s = "IX"; break; }
		default: {break; }
		}
	}
	return s;
}
string ten(int k)
{
	string s = "";
	if (k > 0)
	{
		int m = k % 10;
		switch (m)
		{
		case 1: {s = "X"; break; }
		case 2: {s = "XX"; break; }
		case 3: {s = "XXX"; break; }
		case 4: {s = "XL"; break; }
		case 5: {s = "L"; break; }
		case 6: {s = "LX"; break; }
		case 7: {s = "LXX"; break; }
		case 8: {s = "LXXX"; break; }
		case 9: {s = "XC"; break; }
		default: {break; }
		}
	}
	return s;
}
string hundred(int k)
{
	string s = "";
	if (k > 0)
	{
		int m = k % 10;
		switch (m)
		{
		case 1: {s = "C"; break; }
		case 2: {s = "CC"; break; }
		case 3: {s = "CCC"; break; }
		case 4: {s = "CD"; break; }
		case 5: {s = "D"; break; }
		case 6: {s = "DC"; break; }
		case 7: {s = "DCC"; break; }
		case 8: {s = "DCCC"; break; }
		case 9: {s = "CM"; break; }
		default: {break; }
		}
	}
	return s;
}
