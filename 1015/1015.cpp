// 1015.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
using namespace std;

// Input： N 数值 D 基数
// 判断N在D下是否为反转素数
// 判断N是不是素数，N在D的基数上反转后的值是不是素数

// 难点：
// 1. 如何判断素数
// 2. 如何得到D基数下的值
// 3. 如何反转
string N;
bool flag;

bool isprime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int n, c, d;
	scanf_s("%d %d", &n, &d);
	while (n > 0)
	{
		if (isprime(n) == false)
			printf_s("No\n");
		else
		{
			int arr[100], length = 0;
			int revn = 0;
			while (n != 0)
			{
				arr[length] = n % d;
				n = n / d;
				length++;
			}
			// 把基数值转成十进制
			int e = 0;
			for (int i = length - 1; i >= 0; i--)
			{
				revn += arr[i] * pow(d, e);
				e++;
			}
			if (isprime(revn) == false)
				cout << "No\n";
			else
				cout << "Yes\n";
		}
		scanf_s("%d %d", &n, &d);
	}
	return 0;
}
