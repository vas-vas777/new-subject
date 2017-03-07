#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	FILE *p, *p1;
	unsigned  i = 0, j = 0, k = 0, f = 0, e = 0, t = 0;
	char *s, *s1;
	s = new char[30];
	s1 = new char[30];
	fopen_s(&p, "Myfile.txt", "r");
	fopen_s(&p1, "Myfile2.txt", "r");
	char ch, ch1;
	ch = getc(p);
	ch1 = getc(p1);
    while (ch != EOF)
	{

		if (int(ch) == 10)
		{
			e++;

			s[i] = (e + '0');
			k = ++i;
			ch = getc(p);
		}
		else
		{
			s[i] = ch;
			k = ++i;
			ch = getc(p);
		}
	}
	e++;  if (((int)s[i] != 10) && (s[i] <= '0' || (s[i] >= '9'))) s[i] = (e + '0');
    e = 0;
	while (ch1 != EOF)
	{

		if (int(ch1) == 10)
		{
			e++;

			s1[f] = (e + '0');
			t = ++f;
			ch1 = getc(p1);
		}
		else
		{
			s1[f] = ch1;
			t = ++f;
			ch1 = getc(p1);
		}
	}
	e++; if (((int)s1[f] != 10) && (s1[f] <= '0' || (s1[f] >= '9'))) s1[f] = (e + '0');
	for (i = 0; i < k+1; ++i)
		cout << s[i];
	cout << endl;
	for (f = 0; f < t+1; ++i)
		cout << s1[f];
	cout << endl;
	j = 0;
	cout << "file1: ";
	for (i = 0; i < k; ++i)
	{
		for (f = 0; f < t; ++f)
		{
			if (s[i] == s1[f])
			{
				j = 0;
				break;
			}
			else j++;

			if (j == t)
			{
				if ((s[i] <= '0') || (s[i] >= '9'))
					cout << s[i];
				if ((s[i + 1] >= '0') && (s[i + 1] <= '9'))
					cout << s[i + 1];
				j = 0;
			}
		}
	}
    j = 0;
	cout << endl;
	cout << "file2: ";
	for (f = 0; f < t; ++f)
	{
		for (i = 0; i < k; ++i)
		{
			if (s1[f] == s[i])
			{
				j = 0;
				break;
			}
			else j++;
			if (j == k)
			{
				if ((s1[f] <= '0') || (s1[f] >= '9'))
					cout << s1[f];
				if ((s1[f + 1] >= '0') && (s1[f + 1] <= '9'))
					cout << s1[f + 1];
				j = 0;
			}
		}
	}
    fclose(p);
	fclose(p1);
	_getch();
	return 0;
}