// LAB-8.1.5.cpp
// Сушинський Ігор
// Лабораторна робота №8.1
// Пошук та заміна символів у літерному рядку.
// Варіант 20
// 2 завдання
// Ітераційний спосіб

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* Change(char* str)
{
	size_t len = strlen(str);

	if (len < 3)
		return str;

	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;

	tmp[0] = '\0';

	size_t i = 0;

	while (i < len && str[i + 2] != 0)
	{
		if (str[i] == ',' && str[i + 2] == '-')
		{
			strcat(t, "**");
			t += 4;
			i += 3;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';

	strcpy(str, tmp);

	return tmp;
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	char str[101];

	cout << "Ввести лiтерний рядок:" << endl;
	cin.getline(str, 100);

	char* dest = new char[151];
	dest = Change(str);

	cout << "Модифiкований лiтерний рядок (result): " << dest << endl;

	return 0;
}