// 出栈序列统计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int c = 0;

void DFS(int in, int out)
{
	if (out == 0)
	{
		++c;
	}
	else if (in == 0)//如果已经入栈没有元素，则入栈元素，待入栈元素少一个
	{
		DFS(in + 1, out - 1);
	}
	else if (out)//如果入栈有元素且待入栈也有元素，则分两种情况，一种是继续入栈，一种是出栈
	{
		DFS(in + 1, out - 1);
		DFS(in - 1, out);
	}

}

int main()
{
	int n;
	while (cin >> n)
	{
		c = 0;
		DFS(0, n);
		cout << c << endl;
	}
	return 0;
}