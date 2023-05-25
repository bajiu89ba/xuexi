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
			cout << "请输入页面访问序列长度（15-25，含端点）：" << endl;
			cin >> m;
			if (m > 25 || m < 15)
			{
				cout << "您输入的页面访问序列长度超出给定范围，请重新输入15-25（含端点）的数字：" << endl;
				cin >> m;
			}
			cout << "请输入物理块个数（3-5，含端点）：" << endl;
			cin >> n;
			if (n < 3 || n>5)
			{
				cout << "您输入的物理块个数超出给定范围，请重新输入3-5（含端点）的数字：" << endl;
				cin >> n;
			}
			cout << "请选择页面访问序列生成方式：1、用户输入；2、随机生成" << endl;
			cin >> q;
			if (q == 1)
			{
				cout << "请输入0-5数字组成的无规律字符串作为页面访问序列，长度为" << m << endl;
				for (int i = 0; i < m; i++)
				{
					cin >> B[i];
				}
				for (int i = 0; i < m; i++)
				{
					if (B[i] > 5 || B[i] < 0)
					{
						cout << "您输入的序列有误，请重新输入0-5数字组成的无规律字符串作为页面访问序列，长度为" << m << endl;
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
			cout << "页面访问序列为：";
			for (int i = 0; i < m; i++)
			{
				cout << B[i];
			}
			cout << endl;
			cout << "物理块个数为：" << n << endl;
		}
		cout << "请选择要执行的页面选择算法：1、OPT；2、FIFO；3、LRU；4、CLOCK" << endl;
		cin >> q;
		if (q < 1 || q>4)
		{
			cout << "您输入的不在可选择范围，请从新输入" << endl;
			cin >> q;
		}
		if (q == 1)
		{
			cout << "访问页面\t物理块\t\t    缺页中断" << endl;
			OPT(B, a, m, n, w);
			cout << "页面访问序列总长" << m << "，OPT算法共发生缺页中断" << w << "次，缺页率为" << w << "/" << m << endl;
			w = 0;
		}
		if (q == 2)
		{
			cout << "访问页面\t物理块\t\t    缺页中断" << endl;
			FIFO(B, a, m, n, w);
			cout << "页面访问序列总长" << m << "，FIFO算法共发生缺页中断" << w << "次，缺页率为" << w << "/" << m << endl;
			w = 0;
		}
		if (q == 3)
		{
			cout << "访问页面\t物理块\t\t    缺页中断" << endl;
			LRU(B, a, m, n, w);
			cout << "页面访问序列总长" << m << "，LRU算法共发生缺页中断" << w << "次，缺页率为" << w << "/" << m << endl;
			w = 0;
		}
		if (q == 4)
		{
			cout << "访问页面\t物理块\t\t    缺页中断" << endl;
			CLOCK(B, a, m, n, w);
			cout << "页面访问序列总长" << m << "，CLOCK算法共发生缺页中断" << w << "次，缺页率为" << w << "/" << m << endl;
			w = 0;
		}
		for (int z = 0; z < n; z++)
		{
			a[z] = -1;
		}
		cout << "本次计算已完成，请选择：1、继续尝试其他算法；2、更换数据；3、结束程序" << endl;
		cin >> p;
	} while (p != 3);

	return 0;
}
