
// 1006.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

// 读取总记录数m
// 分别读取m条记录
// 将进入时间和出去时间都转化成秒数并存在early和last中
// 记录对应的学生标记

int inf = 9999999999;
int m;
long early, last;
string persone, personl;

int main()
{
	cin >> m;
	early = inf;
	last = 0;
	for (int i = 0; i < m; i++)
	{
		string id;
		long in, out;
		int h1, h2, m1, m2, s1, s2;
		cin >> id;
		scanf_s("%d:%d:%d", &h1, &m1, &s1);
		in = s1 + m1 * 60 + h1 * 60 * 60;
		if (in<early)
		{
			early = in;
			persone = id;
		}
		scanf_s("%d:%d:%d", &h2, &m2, &s2);
		out = s2 + m2 * 60 + h2 * 60 * 60;
		if (out > last)
		{
			last = out;
			personl = id;
		}
	}
	cout << persone << " " << personl;
}