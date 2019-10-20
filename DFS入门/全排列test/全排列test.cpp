// 全排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int n;
int p[11] = { 0 };
bool vis[11] = { false };

void dfs(int num)
{
	if (num == n + 1)
	{
		for (int i = 1; i <= n - 1; i++)
		{
			cout << p[i] << " ";
		}
		cout << p[n] << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == false)
		{
			p[num] = i;
			vis[i] = true;
			dfs(num+1);
			vis[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	dfs(1);

	return 0;

}