// n皇后问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int n;
bool a[11][11] = { false };
int tag[11][11] = { 0 };
vector<vector<int>> plans;
int plan[11];

void dfs(int depth)
{
	if (depth == n+1)
	{
		vector<int> p;
		for (int i = 1; i <= n; i++)
			p.push_back(plan[i]);
		plans.push_back(p);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[depth][i] == false)
			{
				plan[depth] = i;
				for (int j = 1; j <= n; j++)
				{
					if (!tag[depth][j])
					{
						a[depth][j] = true;
						tag[depth][j] = depth;
					}
					if (!tag[j][i])
					{
						a[j][i] = true;
						tag[j][i] = depth;
					}
				}
				for (int k = 1; k <= n-i; k++)
				{
					if (!tag[depth - k][i + k])
					{
						a[depth - k][i + k] = true;
						tag[depth - k][i + k] = depth;
					}
					if (!tag[depth - k][i + k])
					{
						a[depth - k][i + k] = true;
						tag[depth - k][i + k] = depth;
					}
					if (!tag[depth + k][i + k])
					{
						a[depth + k][i + k] = true;
						tag[depth + k][i + k] = depth;
					}
				}
				for (int m = 1; m <= i-1; m++)
				{
					if (!tag[depth - m][i - m])
					{
						a[depth - m][i - m] = true;
						tag[depth - m][i - m] = depth;
					}
					if (!tag[depth + m][i - m])
					{
						a[depth + m][i - m] = true;
						tag[depth + m][i - m] = depth;
					}
				}
				dfs(depth + 1);
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						if (tag[i][j] == depth)
						{
							tag[i][j] = 0;
							a[i][j] = false;
						}
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	memset(tag, 0, sizeof(tag));
	dfs(1);
	// 已经全部遍历了情况
	// 仍需要判断有可行方案或者no solute
	if (plans.size() == 0)
		cout << "no solute";
	else
	{
		for (int i = 0; i < plans.size(); i++)
		{
			for (int j = 0; j < plans[i].size() - 1; j++)
				cout << plans[i][j] << " ";
			cout << plans[i][plans[i].size() - 1] << endl;
		}
	}
}
