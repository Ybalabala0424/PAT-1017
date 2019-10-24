// 求一元二次方程的根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	if (a==0)
	{
		cout << "请输入正确的a";
		return 0;
	}
	if (b*b-4*a*c<=0)
	{
		cout << "请输入正确的a,b,c";
		return 0;
	}
	double r1, r2;
	r1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
	r2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
	cout << "r1=";
	printf_s("%7.2f\n", r1);
	cout << "r2=";
	printf_s("%7.2f\n", r2);
}
