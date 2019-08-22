// 1009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
float k1, k2, result[2001] = { 0.0 };
int e1[10] = { 0 }, e2[10] = { 0 };
float c1[10] = { 0 }, c2[10] = { 0 };
// 题目要求算多项式相乘结果
// Input: 两行内容 
// k: 多项式参数个数
// 将第一行的k1个多项式系数和第二行的k2个多项式系数分别进行相乘 k1*k2个结果
// 多项式指数相加 将系数相乘值存进result数组中


int main()
{
	int ex1, ex2, num = 0;
	float co1, co2;
	cin >> k1;
	for (int i = 0; i < k1; i++)
	{
		cin >> ex1;
		cin >> co1;
		e1[i] = ex1;
		c1[i] = co1;
	}
	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		cin >> ex2;
		cin >> co2;
		e2[i] = ex2;
		c2[i] = co2;
	}
	for (int i = 0; i < k1; i++)
	{
		for (int j = 0; j < k2; j++)
		{
			int e;
			float c;
			e = e1[i] + e2[j];
			c = c1[i] * c2[j];
			if (result[e] == 0) num++;
			result[e] += c;
		}
	}
	cout << num;
	for (int i = 2000; i >= 0; i--)
	{
		if (result[i] != 0.0)
		{
			cout << " " << i << " ";
			printf_s("%0.1f", result[i]);
		}
	}
	return 0;
}
