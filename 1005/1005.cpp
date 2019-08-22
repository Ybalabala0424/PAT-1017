
// 1005.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// 先获取input值
// 采用取余法 将每一位的数值存到数组中去 并利用digit++来获取最大位数
// 求出数组从下标为0的数加到最大位数的值
// 再次采用取余法以及利用d++来获取和的最大位数
// 反向输出值

int n, k[1001], K[1001];
int digit = 0, d = 0, sum = 0;
string L[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
	cin >> n;
	while (n != 0)
	{
		int m;
		m = n % 10;
		k[++digit] = m;
		n = n / 10;
	}
	for (int i = 1; i <= digit; i++)
	{
		sum += k[i];
	}
	while (sum != 0)
	{
		int a;
		a = sum % 10;
		K[++d] = a;
		sum = sum / 10;
	}
	cout << L[K[d]];
	for (int i = d - 1; i > 0; i--)
	{
		int b = K[i];
		cout << " " << L[b];
	}
}