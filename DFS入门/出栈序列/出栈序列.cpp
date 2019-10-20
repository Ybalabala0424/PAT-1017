// 出栈序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int result = 0, n;

void dfs(int in, int out)
{
	if (out == n)
	{
		++result;
	}
	else
	{
		if (!in)
		{
			dfs(in + 1, out);
		}
		else if(in && (in+out)<n)
		{
			dfs(in + 1, out);
			dfs(in - 1, out + 1);
		}
		else if ((in+out) ==n)
		{
			dfs(in - 1, out + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs(0, 0);
	cout << result;
}
