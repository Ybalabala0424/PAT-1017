// Student List for Course.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int n, k;

bool cmp(string a,string b)
{
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<string>> course;
	cin >> n >> k;
	course.resize(k+1);
	for (int i = 1; i <= n; i++)
	{
		string name;
		int sum;
		cin >> name >> sum;
		for (int j = 1; j <= sum; j++)
		{
			int coursei;
			cin >> coursei;
			course[coursei].push_back(name);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cout << i << " " << course[i].size() << endl;
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++)
		{
			cout << course[i][j] << endl;
		}
	}
}