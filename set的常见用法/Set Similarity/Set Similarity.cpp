// Set Similarity.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<set<int>> sets;
	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		set<int> one;
		for (int j = 1; j <= m; j++)
		{
			int integer;
			cin >> integer;
			one.insert(integer);
		}
		sets.push_back(one);
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		int sum = sets[num1 - 1].size() + sets[num2 - 1].size();
		set<int> result;
		set_union(sets[num1 - 1].begin(), sets[num1 - 1].end(), sets[num2 - 1].begin(), sets[num2 - 1].end(), inserter(result,result.begin()));
		int num = result.size();
		double ans = (double)(sum - num) / num * 100;
		printf_s("%.1f%%\n", ans);
	}
}
