// 1017.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

// 先收集信息 time procTime
// 按time排序
// 顺序分配到k个窗口 取最小值 vector接上

struct node
{
	int time;
	int procTime;
	int wait;
	bool comp;
};
bool func(node a, node b)
{
	return (a.time < b.time);
}
bool Func(node a, node b)
{
	return ((a.procTime+a.time+a.wait) > (b.procTime+b.time+b.wait));
}
int over = 0;
int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);
	vector<node> a;
	int h, m, s, procTime;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d:%d:%d %d", &h, &m, &s, &procTime);
		int time = h * 3600 + m * 60 + s;
		if (time > 61200)
			a.push_back({ time,procTime * 60,0,false });
		else
			a.push_back({ time,procTime * 60,0,true });
		
	}
	sort(a.begin(), a.end(), func);
	vector<node> b;
	for (int i = 0; i < k; i++) 
	{
		a[i].wait = (a[i].time >= 28800) ? 0 : (28800 - a[i].time);
		b.push_back(a[i]);
	}
	do
	{
		sort(b.begin(), b.end(), Func);
		over++;
		if (a[k + over - 1].time < b[b.size() - 1].time + b[b.size() - 1].wait + b[b.size() - 1].procTime)
			a[k + over - 1].wait = b[b.size() - 1].time + b[b.size() - 1].wait + b[b.size() - 1].procTime - a[b.size() + over - 1].time;
		else
			a[k + over - 1].wait = 0;
		b.pop_back();
		if ((k+over-1)<=n && a[k + over - 1].comp == true)
			b.push_back(a[k + over - 1]);
	} while (k + over - 1 < n - 1);
	float sum = 0;
	int com = 0;
	for (int i = 0; i < n; i++)
		if (a[i].comp == true)
		{
			sum += a[i].wait;
			com++;
		}
			
	sum = sum / 60 / com;
	printf_s("%.1f", sum);
}