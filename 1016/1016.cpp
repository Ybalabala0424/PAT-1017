// 1016.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

// Input：
// 24个整数 表示多少cents/minute每个小时
// N 记录数（一个月内的记录）
// N条记录 string mm:dd:hh:mm string(on-line/off-line)
// 根据记录求每个人当月的花费
int toll[24], month;
int n;// 记录数
struct node
{
	int time;
	int day;
	int hour;
	int minute;
	string status;
};
struct person
{
	string name;
	vector<node> records;
};
vector<person> p;

int searchInx(vector<person> p,string personName)
{
	for (int i = 0; i < p.size(); i++)
		if (p[i].name == personName)
			return i;
	return -1;
}
void bubble_sort(vector<node> a, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (a[j].time > a[j+1].time)
			{
				node temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void bubble_Sort(vector<person> a, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (a[j].records[0].time > a[j + 1].records[0].time)
			{
				person temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int day, hour, minute;
int main()
{
	for (int i = 0; i < 24; i++)
		scanf_s("%d", &toll[i]);
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int time;
		string Time;
		string personName, status;
		cin >> personName;
		scanf_s("%d:%d:%d:%d", &month, &day, &hour, &minute);
		cin >> status;
		time = minute + hour * 60 + day * 60 * 12;
		int index = searchInx(p, personName);
		if (index == -1)
		{
			vector<node> record;
			record.push_back({ time, day, hour, minute, status });
			p.push_back({ personName, record});
		}
		else
		{
			int end = p[index].records.size();
			if (status == p[index].records[end - 1].status)
			{
				if (status == "on-line")
				{
					p[index].records.pop_back();
					p[index].records.push_back({ time, day, hour, minute, status });
				}
			}
			else
			{
				p[index].records.push_back({ time, day, hour, minute, status });
				end += 1;
			}
			bubble_sort(p[index].records, p[index].records.size());
		}
	}
	bubble_Sort(p, p.size());
	for (int i = 0; i <= p.size(); i++)
	{
		float sum = 0.0;
		cout << p[i].name << " " << month << endl;
		for (int j = 0; j < p[i].records.size(); j = j+2)
		{
			int d1 = p[i].records[j].day;
			int h1 = p[i].records[j].hour;
			int m1 = p[i].records[j].minute;
			int d2 = p[i].records[j + 1].day;
			int h2 = p[i].records[j + 1].hour;
			int m2 = p[i].records[j + 1].minute;
			int dis = p[i].records[j + 1].time - p[i].records[j].time;
			float cost = toll[h1] * m1 + toll[h2] * m2;
			for (int i = 1; i < h2 - h1; i++)
				cost += 60 * toll[h1 + i];
			printf_s("%02d:%02d:%02d ", d1, h1, m1);
			printf_s("%02d:%02d:%02d ", d2, h2, m2);
			printf_s("%d $%.2f\n", dis, cost/100);
			sum += cost;
		}
		printf_s("Total amount: $%.2f\n", sum);
	}
}