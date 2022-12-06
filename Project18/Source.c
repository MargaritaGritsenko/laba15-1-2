#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100
#define M 100
double** elements(double ptr_array[][M], int n, int m);
int print_elements(double ptr_array[][M], int n, int m);
double otd_element(double ptr_array[][M], int n, int m);
int naiti_element(double ptr_array[][M], int n, int m);
double** transport(double ptr_massive[][M], int x, int y, double ptr_array[][M]);
double sr_ar(double ptr_array[][M], int n, int m);
int pari(double ptr_array[][M], int n, int m);
int maximal_znach(double ptr_array[][M], int n, int m);
main()
{
	setlocale(LC_ALL, "RU");
	int i, j;
	int array[N][M];
	int massive[N][M];
	int n, m, menu = 9, row, col, x=7, y=7;
	printf("������� ���������� ����� � ��������: ");
	scanf("%d%d", &row, &col);
	n = row;
	m = col;
	elements(array,n,m);
	transport(massive, n, m, array);
	while (menu != 0)
	{
		printf("1-����� �������\n2-�������� ������� �� ������ �������, ������������� � ������������� ������� (����� �������)\n3-����� �������� �������� ����� ���������, ������� �� ���������\n4-������ ����� �� �������\n5-������� �������������� ��������� ��������� ������, ������� ����\n6-������� ����� ��� ���������� �������� ���������,  ������������x � ����� ������ � � ����� �������\n7-���������� ������������� ��������\n0-�����\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			print_elements(array, n, m);
			break;
		case 2:
			otd_element(array, n, m);
			break;
		case 3:
			naiti_element(array, n, m);
			break;
		case 4:
			print_transport(massive, n, m);
			break;
		case 5:
			sr_ar(array, n, m);
			break;
		case 6:
			pari(array, n, m);
			break;
		case 7:
			maximal_znach(array, n, m);
			break;
		}
	}
}
double ** elements(double ptr_array[][M], int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (i <= j) *(*(ptr_array + i) + j) = i + rand() % (j - i + 2);
			else *(*(ptr_array + i) + j) = j + rand() % (i - j + 2);
		}
	}
}
int print_elements(double ptr_array[][M], int n, int m)
{
	for (int k = 0; k < m; k++)
	{
		printf("\t%d", k);
	}
	printf("\n");
	printf("__");
	for (int k = 0; k < m; k++)
	{
		printf("________");
	}
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		printf("%d| ", i);
		for (int j = 0; j < m; j++)
		{
			printf("\t%.1lf", *(*(ptr_array + i) + j));
		}
	}
	printf("\n");
}
double otd_element(double ptr_array[][M], int n, int m)
{
	double x;
	x = *(*(ptr_array + rand() % n) + m - 2);
	printf("%.1lf\n", x);
}
int naiti_element(double ptr_array[][M], int n, int m)
{
	int x=10000,z=10000;
	double y;
	printf("������� ��������:");
	scanf("%lf", &y);
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m; j++) {
			if ((i == j) && (y == *(*(ptr_array + i) + j)))
			{
				x = i;
				z = j;
			}
		}
	}
	if (x != 10000 && y != 10000)
		printf("����� ������� ���� � ������ %d � ������� %d\n", x, z);
	else printf("����� ������� �����������\n");
}
double** transport(double ptr_massive[][M], int n, int m, double ptr_array[][M])
{
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < m+1; j++)
		{
			*(*(ptr_massive + i) + j) = *(*(ptr_array + j) + i);
		}
	}
}
int print_transport(double ptr_massive[][M], int n, int m)
{
	int x = n, y = m;
	for (int k = 0; k < x; k++)
	{
		printf("\t%d", k);
	}
	printf("\n");
	printf("__");
	for (int k = 0; k < x; k++)
	{
		printf("________");
	}
	for (int i = 0; i < y; i++)
	{
		printf("\n");
		printf("%d| ", i);
		for (int j = 0; j < x; j++)
		{
			printf("\t%.1lf", *(*(ptr_massive + i) + j));
		}
	}
	printf("\n");
}
double sr_ar(double ptr_array[][M], int n, int m)
{
	double srar;
	int sum = 0, cnt = 0;
	for (int j = 0; j < m + 1; j++)
	{
		int k = (*(*(ptr_array + 4) + j));
		if (!(k % 3))
		{
			sum += k ;
			cnt += 1;
		}
	}
	srar = sum / cnt;
	printf("%.1lf\n", srar);
	return 0;
}
int pari(double ptr_array[][M], int n, int m)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < m; j++)
		{
			if ((*(*(ptr_array + i) + j)) == (*(*(ptr_array + (i + 1)) + j)) || (*(*(ptr_array + i) + j)) == (*(*(ptr_array + i) + (j + 1))))
				cnt += 1;
			else if ((*(*(ptr_array + i) + j)) == (*(*(ptr_array + (i + 1)) + j)) && (*(*(ptr_array + i) + j)) == (*(*(ptr_array + i) + (j + 1))))
				cnt += 1;
		}
	}
	printf("%d\n", cnt);
}
int maximal_znach(double ptr_array[][M], int n, int m)
{
	int max = 0,x,y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((*(*(ptr_array + i) + j)) > max)
			{
				max = (*(*(ptr_array + i) + j));
				x = i;
				y = j;
			}
		}
	}
	printf("������������ �������� %d � ������������ (%d;%d)\n", max, x, y);
}

