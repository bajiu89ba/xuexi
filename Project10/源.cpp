#include<iostream> 
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void randperm(int a[20], int Num)
{
	vector<int> temp;
	for (int i = 0; i < 200; i++)
	{
		temp.push_back(i + 1);
	}
	random_shuffle(temp.begin(), temp.end());
	for (int i = 0; i < Num; i++)
	{
		a[i] = temp[i];
	}
}

void FCFS(int a[20],int b[20],int n)
{
	cout << "��ѡ����FCFS�㷨��ִ�н�����£�" << endl;
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

void SSTF(int a[20],int b[20],int n)
{
	int min = 200;
	int c[20] = { 0 };
	int w = 0;
	int z = 0;
	cout << "��ѡ����SSTF�㷨��ִ�н�����£�" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (abs(a[j] - a[w]) < min && c[j] == 0)
			{
				min = abs(a[j] - a[w]);
				z = j;
			}
		}
		w = z;
		c[w] = 1;
		b[i] = a[w];
		min = 200;
	}
}

void SCAN(int a[20], int b[20], int n)
{
	int c[20];
	int w = 0;
	int z = 0;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		c[i] = a[i];
	}
	sort(c, c + n);
	for (int i = 0; i < n; i++)
	{
		if (a[0] == c[i])
			w = i;
	}
	cout << "�����ѡ��ǰ��ͷ�˶�����1���ɵ͵��ߣ�2���ɸߵ���" << endl;
	cin >> p;
	if (p == 1)
	{
		cout << "��ѡ����SCAN�㷨����ǰ��ͷ�˶�����Ϊ�ɵ͵��ߣ�ִ�н�����£�" << endl;
		for (int i = w; i < n; i++)
		{
			b[z++] = c[i];
		}
		for (int i = w-1; i >= 0; i--)
		{
			b[z++] = c[i];
		}
	}
	if (p == 2)
	{
		cout << "��ѡ����SCAN�㷨����ǰ��ͷ�˶�����Ϊ�ɸߵ��ͣ�ִ�н�����£�" << endl;
		for (int i = w; i >= 0; i--)
		{
			b[z++] = c[i];
		}
		for (int i = w+1; i < n; i++)
		{
			b[z++] = c[i];
		}
	}
}

void CSCAN(int a[20], int b[20], int n)
{
	int c[20];
	int w = 0;
	int z = 0;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		c[i] = a[i];
	}
	sort(c, c + n);
	for (int i = 0; i < n; i++)
	{
		if (a[0] == c[i])
			w = i;
	}
	cout << "�����ѡ��ǰ��ͷ�˶�����1���ɵ͵��ߣ�2���ɸߵ���" << endl;
	cin >> p;
	if (p == 1)
	{
		cout << "��ѡ����CSCAN�㷨����ǰ��ͷ�˶�����Ϊ�ɵ͵��ߣ�ִ�н�����£�" << endl;
		for (int i = w; i < n; i++)
		{
			b[z++] = c[i];
		}
		for (int i = 0; i < w; i++)
		{
			b[z++] = c[i];
		}
	}
	if (p == 2)
	{
		cout << "��ѡ����CSCAN�㷨����ǰ��ͷ�˶�����Ϊ�ɸߵ��ͣ�ִ�н�����£�" << endl;
		for (int i = w; i >= 0; i--)
		{
			b[z++] = c[i];
		}
		for (int i = n-1; i > w; i--)
		{
			b[z++] = c[i];
		}
	}
}

void shuchu(int b[20],int n,int& m)
{
	cout << "��ǰ�ŵ���\t\t��һ�ŵ���\t\t���Բ�" << endl;
	for (int i = 0; i < n-1; i++)
	{
		cout << b[i] << "\t\t\t" << b[i + 1] << "\t\t\t" << abs(b[i] - b[i + 1]) << endl;
		m = m + abs(b[i] - b[i + 1]);
	}
	cout << b[n - 1] << "\t\t\t...\t\t\t..." << endl;
}

int main()
{
	int q = 0;
	int a[20];
	int n = 0;
	int b[20];
	int m = 0;
	int u = 2;
	
	do{
		if(u != 1)
		{
			cout << "���������Ѱ�����г��ȣ�10-20�����˵㣩��" << endl;
			cin >> n;
			if (n > 20 || n < 10)
			{
				cout << "������Ĵ���Ѱ�����г��ȳ���������Χ������������10-20�����˵㣩�����֣�" << endl;
				cout << "���������Ѱ�����г��ȣ�10-20�����˵㣩��" << endl;
				cin >> n;
			}
			srand((int)time(0));
			randperm(a, n);
			cout << "���̷�������Ϊ��";
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << ",";
			}
			cout << endl;
		}
		cout << "��ѡ��Ҫִ�еĴ���Ѱ���㷨��1��FCFS��2��SSTF��3��SCAN��4��CSACN" << endl;
		cin >> q;
		if (q > 4 || q < 1)
		{
			cout << "������Ĵ���Ѱ���㷨����������Χ������������Ҫִ�еĴ���Ѱ���㷨��1��FCFS��2��SSTF��3��SCAN��4��CSACN" << endl;
			cin >> q;
		}
		if (q == 1)
		{
			FCFS(a, b, n);
			shuchu(b, n, m);
			cout << "Ѱ�������ܳ�Ϊ" << m << ",FCFS�㷨��ƽ��Ѱ������Ϊ" << m << "/" << n << endl;
		}
		if (q == 2)
		{
			SSTF(a, b, n);
			shuchu(b, n, m);
			cout << "Ѱ�������ܳ�Ϊ" << m << ",SSTF�㷨��ƽ��Ѱ������Ϊ" << m << "/" << n << endl;
		}
		if (q == 3)
		{
			SCAN(a, b, n);
			shuchu(b, n, m);
			cout << "Ѱ�������ܳ�Ϊ" << m << ",SCAN�㷨��ƽ��Ѱ������Ϊ" << m << "/" << n << endl;
		}
		if (q == 4)
		{
			CSCAN(a, b, n);
			shuchu(b, n, m);
			cout << "Ѱ�������ܳ�Ϊ" << m << ",CSCAN�㷨��ƽ��Ѱ������Ϊ" << m << "/" << n << endl;
		}
		cout << "���μ�������ɣ���ѡ��1���������������㷨��2���������ݣ�3����������" << endl;
		cin >> u;
	} while (u!= 3);
	return 0;
}
