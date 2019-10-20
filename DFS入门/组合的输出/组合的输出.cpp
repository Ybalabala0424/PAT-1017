// 组合的输出.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
bool visit[22] = { false };
int n, r;
int p[22];

void dfs(int depth)
{
	if (depth == r+1)
	{
		for (int i = 1; i <= r-1; i++)
			cout << p[i] << " ";
		cout << p[r] << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false && i > p[depth-1])
		{
			p[depth] = i;
 			visit[i] = true;
			dfs(depth + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	cin >> n >> r;
	dfs(1);
	return 0;
}