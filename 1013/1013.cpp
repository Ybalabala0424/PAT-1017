// 1013.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Input: N 城市总数 M 高速数路 K 检查的城市数
// M行 代表两个连接的高速路标志
// 一行K个数 表示我们关注的城市标志

// 题目考的是当删除一个城市和其连接的道路的时候，其他几个剩余的城市至少要
// 添加多少个路线才能让它们重新变为连通图
// Tips:
// 添加的最少的路线就是 图的连通分量数-1
// 如何求图的连通分量数： 采用dfs，求叶子节点数即图的连通分量数
int n, m, k;
int s[1010][1010] = { 0 }, city;
bool visit[1010];

void dfs(int k)
{
	visit[k] = true;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false && s[k][i] == 1)
			dfs(i);
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		s[a][b] = s[b][a] = 1;
	}
	for (int j = 0; j < k; j++)
	{
		cin >> city;
		fill(visit, visit + 1010, false);
		int cc = 0;
		visit[city] = true;
		for (int j = 1; j <= n; j++)
		{
			if (visit[j] == false)
			{
				dfs(j);
				cc++;
			}
		}
		if (cc > 0)
			cout << cc - 1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}