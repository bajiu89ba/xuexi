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
	cout << "您选择了FCFS算法，执行结果如下：" << endl;
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
	cout << "您选择了SSTF算法，执行结果如下：" << endl;
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
	cout << "请继续选择当前磁头运动方向：1、由低到高；2、由高到低" << endl;
	cin >> p;
	if (p == 1)
	{
		cout << "您选择了SCAN算法，当前磁头运动方向为由低到高，执行结果如下：" << endl;
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
		cout << "您选择了SCAN算法，当前磁头运动方向为由高到低，执行结果如下：" << endl;
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
	cout << "请继续选择当前磁头运动方向：1、由低到高；2、由高到低" << endl;
	cin >> p;
	if (p == 1)
	{
		cout << "您选择了CSCAN算法，当前磁头运动方向为由低到高，执行结果如下：" << endl;
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
		cout << "您选择了CSCAN算法，当前磁头运动方向为由高到低，执行结果如下：" << endl;
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
	cout << "当前磁道号\t\t下一磁道号\t\t绝对差" << endl;
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
			cout << "请输入磁盘寻道序列长度（10-20，含端点）：" << endl;
			cin >> n;
			if (n > 20 || n < 10)
			{
				cout << "您输入的磁盘寻道序列长度超出给定范围，请重新输入10-20（含端点）的数字：" << endl;
				cout << "请输入磁盘寻道序列长度（10-20，含端点）：" << endl;
				cin >> n;
			}
			srand((int)time(0));
			randperm(a, n);
			cout << "磁盘访问序列为：";
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << ",";
			}
			cout << endl;
		}
		cout << "请选择要执行的磁盘寻道算法：1、FCFS；2、SSTF；3、SCAN；4、CSACN" << endl;
		cin >> q;
		if (q > 4 || q < 1)
		{
			cout << "您输入的磁盘寻道算法超出给定范围，请重新输入要执行的磁盘寻道算法：1、FCFS；2、SSTF；3、SCAN；4、CSACN" << endl;
			cin >> q;
		}
		if (q == 1)
		{
			FCFS(a, b, n);
			shuchu(b, n, m);
			cout << "寻道序列总长为" << m << ",FCFS算法的平均寻道长度为" << m << "/" << n << endl;
		}
		if (q == 2)
		{
			SSTF(a, b, n);
			shuchu(b, n, m);
			cout << "寻道序列总长为" << m << ",SSTF算法的平均寻道长度为" << m << "/" << n << endl;
		}
		if (q == 3)
		{
			SCAN(a, b, n);
			shuchu(b, n, m);
			cout << "寻道序列总长为" << m << ",SCAN算法的平均寻道长度为" << m << "/" << n << endl;
		}
		if (q == 4)
		{
			CSCAN(a, b, n);
			shuchu(b, n, m);
			cout << "寻道序列总长为" << m << ",CSCAN算法的平均寻道长度为" << m << "/" << n << endl;
		}
		cout << "本次计算已完成，请选择：1、继续尝试其他算法；2、更换数据；3、结束程序" << endl;
		cin >> u;
	} while (u!= 3);
	return 0;
}
