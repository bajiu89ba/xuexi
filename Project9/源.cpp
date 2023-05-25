#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void OPT(int B[30], int a[5], int m, int n, int &w)
{
	int k = 0,i=0,j=0;
	int temp = 1;
	int flag[5]={0,0,0,0,0};
	int count = 0;
	a[0] = B[0];
	cout << B[0] << "\t\t";
	for (int z = 0; z < n; z++)
	{
		cout << a[z] << " ";
	}
	cout << "\t\t";
	cout << "T" << endl;
	w++;
	for (i = 1; temp<n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] == B[i])
				k = 1;
		}
		if (k == 0)
		{
			a[temp] = B[i];
			temp++;
		}
		cout << B[i] << "\t\t";
		for (int z = 0; z < n; z++)
		{
			cout << a[z]<<" ";
		}
		cout << "\t\t";
		if (k == 1)
			cout << "F" << endl;
		if (k == 0)
		{
			cout << "T" << endl;
			w++;
		}
		k = 0;
	}
	for (i; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j] == B[i])
				k = 1;
		}
		if (k == 0)
		{
			for (j = i; j < m; j++)
			{
				for (int z = 0; z < n; z++)
				{
					if (B[j] == a[z] && flag[z] == 0)
					{
						flag[z] = 1;
						count++;
					}
				}
				if (count == n - 1||j==m-1)
				{
					for (int z = 0; z < n; z++)
					{
						if (flag[z] == 0)
						{
							a[z] = B[i];
							break;
						}
					}
					break;
				}
			}
			for (int z = 0; z < n; z++)
				flag[z] = 0;
			count = 0;
		}
		cout << B[i] << "\t\t";
		for (int z = 0; z < n; z++)
		{
			cout << a[z] << " ";
		}
		cout << "\t\t";
		if (k == 1)
			cout << "F" << endl;
		if (k == 0)
		{
			cout << "T" << endl;
			w++;
		}
		k = 0;
	}
}

void FIFO(int B[30], int a[5], int m, int n, int &w)
{
	int k = 0, i = 0, j = 0;
	int max = 0, t = 0;
	int temp = 1;
	int flag[5] = {0};
	int count = 0;
	a[0] = B[0];
	flag[0]++;
	cout << B[0] << "\t\t";
	for (int z = 0; z < n; z++)
	{
		cout << a[z] << " ";
	}
	cout << "\t\t";
	cout << "T" << endl;
	w++;
	for (i = 1; temp < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] == B[i])
			{
				k = 1;
				for (int z = 0; z < temp; z++)
				{
					flag[z]++;
				}
			}
		}
		if (k == 0)
		{
			a[temp] = B[i];
			temp++;
			for (int z = 0; z < temp; z++)
			{
				flag[z]++;
			}
		}
		cout << B[i] << "\t\t";
		for (int z = 0; z < n; z++)
		{
			cout << a[z] << " ";
		}
		cout << "\t\t";
		if (k == 1)
			cout << "F" << endl;
		if (k == 0)
		{
			cout << "T" << endl;
			w++;
		}
		k = 0;
	}
	for (i; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j] == B[i])
			{
				for (int z = 0; z < n; z++)
				{
					flag[z]++;
				}
				k = 1;
			}
		}
		if (k == 0)
		{
			for (j = 0; j < n; j++)
			{
				if (flag[j] >= max)
				{
					max = flag[j];
					t = j;
				}
			}
			max = 0;
			a[t] = B[i];
			flag[t] = 0;
			for (j = 0; j < n; j++)
			{
				flag[j]++;
			}
		}
		cout << B[i] << "\t\t";
		for (int z = 0; z < n; z++)
		{
			cout << a[z] << " ";
		}
		cout << "\t\t";
		if (k == 1)
			cout << "F" << endl;
		if (k == 0)
		{
			cout << "T" << endl;
			w++;
		}
		k = 0;
	}
}

void LRU(int B[30], int a[5], int m, int n, int &w)
{
	int k = 0, i = 0, j = 0;
	int temp = 1;
	int flag[5] = { 0,0,0,0,0 };
	int count = 0;
	a[0] = B[0];
	cout << B[0] << "\t\t";
	for (int z = 0; z < n; z++)
	{
		cout << a[z] << " ";
	}
	cout << "\t\t";
	cout << "T" << endl;
	w++;
	for (i = 1; temp < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] == B[i])
				k = 1;
		}
		if (k == 0)
		{
			a[temp] = B[i];
			temp++;
		}
		cout << B[i] << "\t\t";
		for (int z = 0; z < n; z++)
		{
			cout << a[z] << " ";
		}
		cout << "\t\t";
		if (k == 1)
			cout << "F" << endl;
		if (k == 0)
		{
			cout << "T" << endl;
			w++;
		}
		k = 0;
	}
	for (i; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j] == B[i])
				k = 1;
		}
		if (k == 0)
		{
			for (j = i; j > 0; j--)
			{
				for (int z = 0; z < n; z++)
				{
					if (B[j] == a[z] && flag[z] == 0)
					{
						flag[z] = 1;
						count++;
					}
				}
				if (count == n - 1 || j == 1)
				{
					for (int z = 0; z < n; z++)
					{
						if (flag[z] == 0)
						{
							a[z] = B[i];
							break;
						}
					}
					break;
				}
			}
			for (int z = 0; z < n; z++)
				flag[z] = 0;
			count = 0;
		}
		cout << B[i] << "\t\t";
		for (int z = 0; z < n; z++)
		{
			cout << a[z] << " ";
		}
		cout << "\t\t";
		if (k == 1)
			cout << "F" << endl;
		if (k == 0)
		{
			cout << "T" << endl;
			w++;
		}
		k = 0;
	}
}

void CLOCK(int B[30], int a[5], int m, int n, int &w)
{
	int k = 0, i = 0, j = 0;
	int temp = 1;
	char flag[5]={' '};
	int count = 0;
	int t = 0;
	a[0] = B[0];
	flag[0] = '*';
	cout << B[0] << "\t\t";
	for (int z = 0; z < n; z++)
	{
		cout << a[z] << flag[z] << " ";
	}
	cout << "\t\t";
	cout << "T" << endl;
	w++;
	for (i = 1; temp < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] == B[i])
			{
				flag[j] = '*';
				k = 1;
				t = j;
			}
		}
		if (k == 0)
		{
			a[temp] = B[i];
			flag[temp] = '*';
			temp++;
			t = temp;
			if (t == n)
				t = t % n;
		}
		cout << B[i] << "\t\t";
		for (int z = 0; z < n; z++)
		{
			cout << a[z] << flag[z] << " ";
		}
		cout << "\t\t";
		if (k == 1)
			cout << "F" << endl;
		if (k == 0)
		{
			w++;
			cout << "T" << endl;
		}
		k = 0;
	}
	for (i; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j] == B[i])
			{
				t = j;
				flag[t] = '*';
				k = 1;
			}
		}
		if (k == 0)
		{
			for(int z=0;z<n;z++)
			{
				if (flag[t] == '*')
				{
					flag[t] = ' ';
					t++;
					if (t == n)
						t = t % n;
				}
				if (flag[t] != '*')
				{
					a[t] = B[i];
					flag[t] = '*';
					t++;
					if (t == n)
						t = t % n;
					break;
				}
			}
		}

		cout << B[i] << "\t\t";
		for (int z = 0; z < n; z++)
		{
			cout << a[z] << flag[z] << " ";
		}
		cout << "\t\t";
		if (k == 1)
			cout << "F" << endl;
		if (k == 0)
		{
			cout << "T" << endl;
			w++;
		}
		k = 0;
	}
}

int main()
{
	int m, n, q, p=2, w = 0;
	int B[30];
	int a[5]={-1,-1,-1,-1,-1};
	do
	{
		if(p==2)
		{
			cout << "������ҳ��������г��ȣ�15-25�����˵㣩��" << endl;
			cin >> m;
			if (m > 25 || m < 15)
			{
				cout << "�������ҳ��������г��ȳ���������Χ������������15-25�����˵㣩�����֣�" << endl;
				cin >> m;
			}
			cout << "����������������3-5�����˵㣩��" << endl;
			cin >> n;
			if (n < 3 || n>5)
			{
				cout << "�������������������������Χ������������3-5�����˵㣩�����֣�" << endl;
				cin >> n;
			}
			cout << "��ѡ��ҳ������������ɷ�ʽ��1���û����룻2���������" << endl;
			cin >> q;
			if (q == 1)
			{
				cout << "������0-5������ɵ��޹����ַ�����Ϊҳ��������У�����Ϊ" << m << endl;
				for (int i = 0; i < m; i++)
				{
					cin >> B[i];
				}
				for (int i = 0; i < m; i++)
				{
					if (B[i] > 5 || B[i] < 0)
					{
						cout << "�������������������������0-5������ɵ��޹����ַ�����Ϊҳ��������У�����Ϊ" << m << endl;
						for (int i = 0; i < m; i++)
						{
							cin >> B[i];
						}
						break;
					}
				}
			}
			if (q == 2)
			{
				for (int i = 0; i < m; i++)
				{
					B[i] = rand() % 6;
					Sleep(0);
				}
			}
			cout << "ҳ���������Ϊ��";
			for (int i = 0; i < m; i++)
			{
				cout << B[i];
			}
			cout << endl;
			cout << "��������Ϊ��" << n << endl;
		}
		cout << "��ѡ��Ҫִ�е�ҳ��ѡ���㷨��1��OPT��2��FIFO��3��LRU��4��CLOCK" << endl;
		cin >> q;
		if (q < 1 || q>4)
		{
			cout << "������Ĳ��ڿ�ѡ��Χ�����������" << endl;
			cin >> q;
		}
		if (q == 1)
		{
			cout << "����ҳ��\t�����\t\t    ȱҳ�ж�" << endl;
			OPT(B, a, m, n, w);
			cout << "ҳ����������ܳ�" << m << "��OPT�㷨������ȱҳ�ж�" << w << "�Σ�ȱҳ��Ϊ" << w << "/" << m << endl;
			w = 0;
		}
		if (q == 2)
		{
			cout << "����ҳ��\t�����\t\t    ȱҳ�ж�" << endl;
			FIFO(B, a, m, n, w);
			cout << "ҳ����������ܳ�" << m << "��FIFO�㷨������ȱҳ�ж�" << w << "�Σ�ȱҳ��Ϊ" << w << "/" << m << endl;
			w = 0;
		}
		if (q == 3)
		{
			cout << "����ҳ��\t�����\t\t    ȱҳ�ж�" << endl;
			LRU(B, a, m, n, w);
			cout << "ҳ����������ܳ�" << m << "��LRU�㷨������ȱҳ�ж�" << w << "�Σ�ȱҳ��Ϊ" << w << "/" << m << endl;
			w = 0;
		}
		if (q == 4)
		{
			cout << "����ҳ��\t�����\t\t    ȱҳ�ж�" << endl;
			CLOCK(B, a, m, n, w);
			cout << "ҳ����������ܳ�" << m << "��CLOCK�㷨������ȱҳ�ж�" << w << "�Σ�ȱҳ��Ϊ" << w << "/" << m << endl;
			w = 0;
		}
		for (int z = 0; z < n; z++)
		{
			a[z] = -1;
		}
		cout << "���μ�������ɣ���ѡ��1���������������㷨��2���������ݣ�3����������" << endl;
		cin >> p;
	} while (p != 3);

	return 0;
}
