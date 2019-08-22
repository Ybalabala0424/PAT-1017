// 1011.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

// 找出每一行中最大的数并确定他的标志
// 计算总和

char signal[3] = { 'W','T','L'};
int tar[3];
double profit = 1;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		double a[3];
		for (int j = 0; j < 3; j++)
			cin >> a[j];
		double* b;
		b = max_element(a, a+3);
		tar[i] = b - a;
		profit *= *b;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << signal[tar[i]]<< " ";
	}
	profit *= 0.65;
	profit -= 1;
	profit *= 2;
	printf_s("%0.2f", profit);
}