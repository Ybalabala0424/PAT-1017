// 1008.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

// 题目求得是电梯运行的时间
// 开始时停在第0层
// 上升一层需要6s，下降一层需要4s，停下来需要5s

int main() {
	int n, a, b, time = 0, temp = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a > temp)
		{
			time += 6 * (a - temp);
		}
		else
		{
			time += 4 * (temp - a);
		}
		temp = a;
		time += 5;
	}
	cout << time;
	return 0;
}