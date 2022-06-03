#include<iostream>
#include<Windows.h>
using namespace std;

//#define TABLE


int StringLength(const char str[]);
void inverse(char str[]);
void shrink(char str[]);
bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
int to_int_number (char str[]);
bool is_bin_number(const char str[]);
int bin_to_dec (char str[]);
bool is_hex_number(char str[]);
int hex_to_dec (char str[]);



void main()
{

#ifdef TABLE
	setlocale(LC_ALL, "");

	//char key = 0;
	for (int i = -128; i < 128; i++)
	{
		cout << i << "-" << char(i) << "\n";
		//key++;
	}
#endif


#ifndef TABLE
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	//char str[] = "Hello";
	//cout << str << endl;
	cout << (int)'я' << endl;
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << "Введенная строка имеет длину " << StringLength(str) << " символов" << endl;
	cout << endl << "Инверсия регистра" << endl;
	inverse(str);
	cout << str << endl;
	cout << endl << "Удаление лишних пробелов" << endl;
	shrink(str);
	cout << str << endl;
	
	if (is_palindrome(str))cout << endl << "Это палиндром" << endl;
	else cout << endl << "Это не палиндром" << endl;

	if (is_int_number(str))
	{
		cout << endl << "Это десятичное число" << endl;
		cout << "Числовое значение: " << to_int_number(str) << endl;
		int a = 5;
		int b = to_int_number(str) + a;
		cout << "Проверка: " << to_int_number(str) << " + " << a << " = " << b << endl;
	}
	else cout << endl << "Это не десятичное число" << endl;

	if (is_bin_number(str))
	{
		cout << endl << "Это двоичное число" << endl;
		cout << "Десятичное значение двоичного числа: " << bin_to_dec(str) << endl;
	}
	else cout << endl << "Это не двоичное число" << endl;

	if (is_hex_number(str))
	{
		cout << endl << "Это шестнадцатеричное число" << endl;
		cout << "Десятичное значение шестнадцатеричного числа: " << hex_to_dec(str) << endl;
	}
	else cout << endl << "Это не шестнадцатеричное число" << endl;



#endif
}

int StringLength(const char str[])
{
	/*int i = 0;
	for (; str[i]; i++);
	return i;*/

	int a = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		a += 1;
	}
	return a;
}

void inverse(char str[])
{
	for (int i = 0; str[i] != 0; i++)
	{
		if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= -32 && str[i] <= 0))
		{
			if (str[i] != 32)str[i] = str[i] - 32;
		}
		else if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= -64 && str[i] <= -33))
		{
			if (str[i] != 32)str[i] = str[i] + 32;
		}
	}
}

void shrink(char str[])
{
	for (int i = 1; str[i] != 0; i++)
	{
		while (str[i] == 32 && str[i - 1] == 32)
		{
			int a = i;
			while (str[a] != 0)
			{
				str[a] = str[a + 1];
				a++;
			}
		}
	}
	if (str[0] == 32)
	{
		int b = 0;
		while (str[b] != 0)
		{
			str[b] = str[b + 1];
			b++;
		}
	}
}


bool is_palindrome(const char str[])
{
	int a = StringLength(str);
	int b = a;
	bool palindrome = true;
	for (int i = 0; i < a / 2;)
	{
		if (((str[i] == 32 ? str[i + 1] : str[i]) != (str[b - 1] == 32 ? str[b - 2] - 32 : str[b - 1] - 32)) && (str[i] == 32 ? str[i + 1] : str[i]) != (str[b - 1] == 32 ? str[b - 2] : str[b - 1]) && (str[i] == 32 ? str[i + 1] : str[i]) != (str[b - 1] == 32 ? str[b - 2] + 32 : str[b - 1] + 32))
		{
			palindrome = false;
			break;
		}
		if (str[b - 1] == 32)b -= 2;
		else b--;
		if (str[i] == 32)i += 2;
		else i++;

	}
	return palindrome;
}




bool is_int_number(const char str[])
{
	bool dec_number = true;
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] < 48 || str[i] > 57)
		{
			dec_number = false;
			break;
		}
	}
	return dec_number;
}

int to_int_number(char str[])
{
	int value = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		int a = str[i] - 48;
		value += a;
		if (str[i + 1] != 0) value *= 10;
	}
	return value;
}


bool is_bin_number(const char str[])
{
	bool bin_number = true;
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] != 48 && str[i] != 49)
		{
			bin_number = false;
			break;
		}
	}
	return bin_number;
}


int bin_to_dec(char str[])
{
	int number = to_int_number(str);
	int value = 0;
	int counter = 0;
	for (int i = 0; number; i++)
	{
		int c = 1;
		for (int i = 0; i < counter; i++)
		{
			c *= 2;
		}
		int a = 0;
		if (number % 10 != 0)
		{
			a = (counter == 0 ? 1 : c);
		}
		counter++;
		number /= 10;
		value += a;
	}
	return value;
}

bool is_hex_number(char str[])
{
	inverse(str);
	bool hex_number = true;
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] < 48 || (str[i] > 57 && str[i] < 65) || str[i] > 70)
		{
			hex_number = false;
			break;
		}
	}
	return hex_number;
}

int hex_to_dec(char str[])
{
	int a = StringLength(str);
	int value = 0;
	int counter = 0;
	int number;
	for (int i = a - 1; i >= 0; i--)
	{
		if (str[i] >= 48 && str[i] <= 57) number = int(str[i]) - 48;
		else if (str[i] == 65)number = 10;
		else if (str[i] == 66)number = 11;
		else if (str[i] == 67)number = 12;
		else if (str[i] == 68)number = 13;
		else if (str[i] == 69)number = 14;
		else if (str[i] == 70)number = 15;
		int c = 1;
		for (int i = 0; i < counter; i++)
		{
			c *= 16;
		}
		int a = number * (counter == 0 ? 1 : c);
		counter++;
		value += a;
	}
	return value;


}



