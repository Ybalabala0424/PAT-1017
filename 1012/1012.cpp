// 1012.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// N M N个学生的成绩信息 M个学生需要查成绩
// 输出M个学生成绩最好的排名记录及科目
// 如果没有该学生信息则输出N/A
// 学生学号6位

// 用结构体进行存储
// 对成绩进行sort排序，用伪函数作为排序方法，四次排序，并记录排名
// 按照ACME记录成绩

int n, m;
struct node
{
	int id, bestId;
	string bestClass;
	int score[4], rank[4];
}stu[2005];
int flag,K[2005];
bool cmp1(node a, node b) { return a.score[flag] > b.score[flag]; }
string name[4] = { "A","C","M","E" };

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
		stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
	}
	for (flag = 0; flag < 4; flag++)
	{
		sort(stu, stu + n, cmp1);
		stu[0].rank[flag] = 1;
		for (int i = 1; i < n; i++)
		{
			stu[i].rank[flag] = i + 1;
			if (stu[i].score[flag] == stu[i - 1].score[flag])
			{
				stu[i].rank[flag] = stu[i - 1].rank[flag];
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		int a[4] = { stu[j].rank[0],stu[j].rank[1] ,stu[j].rank[2] ,stu[j].rank[3] };
		int* b;
		b = min_element(a, a + 4);
		stu[j].bestId = *b;
		stu[j].bestClass = name[b - a];

	}
	for (int i = 0; i < m; i++)
	{
		int id;
		cin >> id;
		K[i] = id;
	}
	for (int i = 0; i < m; i++)
	{
		int flag = 0;
		for (int k = 0; k < n; k++)
		{
			if (stu[k].id == K[i])
			{
				cout << stu[k].bestId << " " << stu[k].bestClass << endl;
				flag = 1;
			}
		}
		if (!flag)
		{
			cout << "N/A" << endl;
		}
	}
}
