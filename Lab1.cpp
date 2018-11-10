#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include<stdio.h>

using namespace std;

struct Set
{
	char M[10][255];
};

char universum[10][25] = { "Medved","Volk","Giena","Gornostay","Dingo","Irbis","Kakomitsli","Krokodil","Lev","Leopard" };

Set* AddSet(Set *set, int n) //������� ���������
{
	if (n == 0)
		set = new Set[n + 1];
	else
	{
		Set* set1 = new Set[n + 1];
		for (int i = 0; i < n; i++)
			set1[i] = set[i];
		delete[] set;
		set = set1;
	}cout << "��������� S[" << n << "]" << "�������" << endl;
	cout << endl;
	return set;
}

void Init(Set *s, int N)   //������������� ��������
{
	short int k = -1, n;
	cout << "������� ������ ���������, ������� �� ������ �������������������: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 255; j++)
			s[n].M[i][j] = NULL;
	cout << "������������ ��������� S[" << n << "] ��������" << endl;
	cout << endl;
}

void Show(const Set* s, int N)  //�������� ���������
{
	short int k = -1, n;
	cout << "������� ������ ���������, ������� �� ������ �������: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n;
	cout << "����� ��������� S[" << n << "]: " << endl;
	unsigned short int j = 0, i = 0;
	while (s[n].M[i][0] != NULL)
	{
		while (s[n].M[i][j] != NULL)
		{
			cout << s[n].M[i][j];
			j++;
		}
		cout << endl;
		i++;
		j = 0;
	}
	cout << endl;
}

void AddElementToSet(Set* s, int N) //�������� �������� � ���������
{
	unsigned short int x, n;
	short int k = -1;
	cout << "������� ������ ���������, � ������� �� ������ �������� ��������: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n;
	cout << "������� ���������� ���������, ������� �� ������ �������� � ��������� ";
	cin >> x;
	char t[255];
	cin.getline(s[n].M[0], 255);
	short int d = 0;
	for (int i = 0; i < x; i++)
	{
		cout << i + 1 << " ������� ���������: ";
		cin.getline(t, 255);
		for (int i = 0; i<10; i++)
			if (strcmp(universum[i], t) == 0)
			{
				strncpy(s[n].M[d], t, 255);
				d++;
			}
	}
	cout << "���� ��������� �������, ��������� " << "S[" << n << "] ���������" << endl;
	cout << endl;
}

bool IsEmpty(Set* s, int N)  //������ �� ���������
{
	bool Empty = false;
	short int k = -1, n;
	cout << "������� ������ ���������, ������� �� ������ ��������� �� �������: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n;
	if (s[n].M[0][0] == NULL) Empty = true;
	if (Empty == true) cout << "��������� S[" << k << "] ������" << endl;
	else
		cout << "��������� S[" << k << "] ��������" << endl;
	cout << endl;
	return Empty;
}

bool Has(Set* s, int N)  //����������� �� ������� ���������
{
	unsigned short int x, n;
	short int k = -1;
	cout << "������� ������ ���������, � ������� �� ������ ��������� ������� �����: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n;
	char t[255];
	bool has = false;
	cout << "������� �����, ������� �� ������ ��������� �� ������� � ���������" << endl;
	cin.getline(t, 255);
	cin.getline(t, 255);
	if (strcmp(t, s[n].M[0]) == 0) has = true;
	if (has == true) cout << "����� ���� � ��������� " << "S[" << n << "] " << endl;
	cout << endl;

	return has;
}

void UnionSet(Set* s, int N)  //����������� ��������
{
	unsigned short int x, n1, n2, n3;
	short int k = -1;
	cout << "������� 3 ������� ��������, ����� ����� �� �����������, ��������� ��������� � 3-�" << endl;;
	cout << "���������: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n1 >> n2 >> n3;
	unsigned short int q = 0, m = 0;
	while (s[n1].M[m][0] != NULL)
	{
		strncpy(s[n3].M[m], s[n1].M[m], 255);
		m++;
	}
	unsigned short int i = 0, c = 0;

	while (s[n2].M[i][0] != NULL)
	{
		unsigned short int j = 0;
		while (s[n3].M[j][0] != NULL)
		{
			if (strcmp(s[n2].M[i], s[n3].M[j]) != 0) q++; j++;
		}
		if (q == j) {
			strncpy(s[n3].M[c + m], s[n2].M[i], 255); c++;
		}q = 0;
		i++;
	}
	cout << "����������� ��������� S[" << n1 << "]" << " � S[" << n2 << "] ������� � �������� � S[" << n3 << "]" << endl;
	cout << endl;
}

void CrossingSet(Set* s, int N) //����������� ��������
{
	unsigned short int x, n1, n2, n3;
	short int k = -1;
	cout << "������� 3 ������� ��������, ����� ����� �� �����������, ��������� ��������� � 3-�" << endl;;
	cout << "���������: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n1 >> n2 >> n3;
	unsigned short int i = 0, d = 0;
	while (s[n2].M[i][0] != NULL)
	{
		unsigned short int j = 0;
		while (s[n1].M[j][0] != NULL)
		{
			if (strcmp(s[n2].M[i], s[n1].M[j]) == 0) { strncpy(s[n3].M[d], s[n1].M[j], 255); d++; }
			j++;
		}
		i++;
	}
	cout << "����������� ��������� S[" << n1 << "]" << " � S[" << n2 << "] ������� � �������� � S[" << n3 << "]" << endl;
	cout << endl;
}

void ResidualSet(Set* s, int N)  //�������� ��������
{
	unsigned short int x, n1, n2, n3;
	short int k = -1;
	cout << "������� 3 ������� ��������, ����� ����� �� ��������, ��������� ��������� � 3-�" << endl;
	cout << "���������: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n1 >> n2 >> n3;
	short int q = 0;
	unsigned short int i = 0, d = 0;
	while (s[n1].M[i][0] != NULL)
	{
		unsigned short int j = 0;
		while (s[n2].M[j][0] != NULL)
		{
			if (strcmp(s[n1].M[i], s[n2].M[j]) == 0)
				q++;
			j++;
		}
		if (q != 1) {
			strncpy(s[n3].M[d], s[n1].M[i], 255);

			d++;
		}
		i++;			q = 0;
	}
	cout << "�������� ��������� S[" << n1 << "]" << " � S[" << n2 << "] ������� � �������� � S[" << n3 << "]" << endl;
	cout << endl;
}

void AdditionSet(Set* s, int N)   //���������� ��������
{
	unsigned short int x, n, n1;
	short int k = -1;
	cout << "������� ������ ���������, ���������� �������� �� ������ ����� � ������ � ���������, � ������� ���������: " << endl;
	cout << "���������: ";
	while (k != N)
	{
		k++;
		cout << "S[" << k << "] ";
	}
	cout << ":";
	cin >> n >> n1;
	unsigned short int i = 0, d = 0, c = 0;
	while (universum[i][0] != NULL)
	{
		for (int j = 0; j<10; j++) {
			if (strcmp(s[n].M[i], universum[j]) == 0) d++;
		}
		if (d == 0) { strncpy(s[n1].M[c], universum[i], 255); c++; }
		i++;
		d = 0;
	}
	cout << "���������� ��������� S[" << n << "] ������� � �������� �  S[" << n1 << "]" << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n = -1, c = 0;
	Set *s = 0;
	cout << "���� ���������:" << endl;
	cout << "������� 0, ����� ��������� ��������� �� �������" << endl;
	cout << "������� 1, ����� ������� ���������" << endl;
	cout << "������� 2, ����� ������������������� ���������" << endl;
	cout << "������� 3, ����� �������� �������� � ���������" << endl;
	cout << "������� 4, ����� �������� ���������� ���������" << endl;
	cout << "������� 5, ����� ��������� ������� ��������� � ���������� ������ � ���������" << endl;
	cout << "������� 6, ����� ����� ����������� ���� ��������" << endl;
	cout << "������� 7, ����� ����� ����������� ���� ��������" << endl;
	cout << "������� 8, ����� ����� �������� ���� ��������" << endl;
	cout << "������� 9, ����� ����� ����������" << endl;
	cout << "������� 10, ����� ��������� ������ ���������" << endl;
	cout << endl;
	while (c != 10)
	{
		cout << "������� �������� ��� �������� �� ����: ";
		cin >> c;
		if (c == 0) IsEmpty(s, n);
		if (c == 1)
		{
			n++;
			s = AddSet(s, n);
		}
		if (c == 2) Init(s, n);
		if (c == 3) AddElementToSet(s, n);
		if (c == 4) Show(s, n);
		if (c == 5)	Has(s, n);
		if (c == 6) CrossingSet(s, n);
		if (c == 7) UnionSet(s, n);
		if (c == 8) ResidualSet(s, n);
		if (c == 9) AdditionSet(s, n);
	}
	delete[] s;
	return 0;
}
