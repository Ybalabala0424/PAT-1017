// 组合加判断素数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int n, k, count = 0;
int a[21], b[21];
bool visit[21];
vector<int> p;
bool isPrime(int num)
{
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void dfs(int depth)
{
	if (depth == k+1)
	{
		int num = 0;
		for (int i = 1; i <= k; i++)
			num += b[i];
		// 判断是否为素数
		if (isPrime(num))
			p.push_back(num);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == false && a[i] > b[depth - 1])
			{
				b[depth] = a[i];
				visit[i] = true;
				dfs(depth + 1);
				visit[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1);
	cout << p.size() << endl;
}