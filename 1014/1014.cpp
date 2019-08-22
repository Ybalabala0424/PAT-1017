// 1014.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

// Input: N 窗口数 M 黄线内最大容忍数 K 顾客数 Q 询问时间的顾客数
// K个整数 代表k个顾客每个接待所需时间 （min）
// Q个整数 代表Q个顾客的标记
// 8：00-17:00上班 17:00之后需要sorry
// 当顾客越过黄线了之后，顾客会选择更短的队伍去排队
// 当队长一样时，顾客会选择窗口数最小的那个去排队

int n, m, k, q;
int process[1001];
int timing[1001];
int out = 0;// 办理完后离开的人数 NM+out即下个人的标志
queue<int> qe[22];
const int inf = 999999;
int a = 1;
int length[22];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= k; i++)
		cin >> timing[i];
	if (k >= n*m)
	{
		// 黄线内顾客按窗口站好
		while (a < n * m + 1)
		{
			int num = (a % n == 0) ? n : a % n;
			qe[num].push(a);
			a++;
		}
		// 如果队列非空的话 就要首行取最小结束办理时间
		// 首行取最小结束办理时间
		int line[22];
		int* one;
		do
		{
			for (int i = 1; i <= n; i++)
			{
				if (qe[i].empty())
					line[i] = inf;
				else
					line[i] = timing[qe[i].front()];
			}
			one = min_element(line + 1, line + n + 1);
			// *one 为最小结束办理时间
			// one-line 为第几列队伍
			//if *one==inf 则可以判断首行全部为空
			if (*one != inf)
			{
				qe[one - line].pop();
			}
			if (!qe[one - line].empty())
				timing[qe[one - line].front()] += *one; // 更新首行元素的办理结束时间
			out++; // 办理结束的顾客数++

			// 判断黄线外是否还有客人在等待
			if (n * m + out <= k)
			{
				// 选取下一个顾客去排队
				int* l;
				for (int i = 1; i <= n; i++)
					length[i] = qe[i].size();
				l = min_element(length + 1, length + n + 1);
				// *l 为最短排队人数
				// l-length 为最短排队人数在的那条队伍标志
				qe[l - length].push(n * m + out);
			}
		} while (*one != inf);
	}
	else
	{
		while (a <= k)
		{
			int num = (a % n == 0) ? n : a % n;
			if(!qe[num].empty())
				timing[a] += timing[qe[num].back()];
			qe[num].push(a);
			a++;
		}
	}
	for (int j = 0; j < q; j++)
	{
		int qust, hour, minute;
		cin >> qust;
		hour = timing[qust] / 60 + 8;
		minute = timing[qust] % 60;
		if (timing[qust] <= 540)
			printf_s("%02d:%02d\n", hour, minute);
		else
			cout << "Sorry\n";
	}
	return 0;
}
