// 1018.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

// Input: 
// Cmax 每个站点的最大可容忍数 N 站点总数 Sp 问题站点的下标 M 道路数
// N个数 Ci 指对应站点的已有自行车数
// M行记录 Si Sj Tij 站点Si到站点Sj的时间Tij
int Cmax, n, index, m;
vector<int> cb;
int e[501][501];
int before[501];
int main()
{
	cin >> Cmax >> n >> index >> m;
	for (int i = 1; i <= n; i++)
	{
		int bikeNum;
		cin >> bikeNum;
		cb.push_back(bikeNum);
	}
	for (int i = 0; i < m; i++)
	{
		int s1, s2, t;
		cin >> s1 >> s2 >> t;
		e[s1][s2] = e[s2][s1] = t;
	}
	for (int k = 0; k <= n; k++)
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
			{
				if (e[i][j] > e[i][k] + e[k][j])
				{
					e[i][j] = e[i][k] + e[k][j];
					before[j] = k;
				}
				else
					before[j] = i;
					
			}

}