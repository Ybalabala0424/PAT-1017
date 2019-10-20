// 1019.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, b;
vector<int> s;
int main()
{
	cin >> n >> b;
	while (n!=0)
	{
		int c = n % b;
		n = n / b;
		s.push_back(c);
	}
	bool flag = true;
	for (int i = 0; i < s.size()/2; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
			flag = false;
	}
	printf_s("%s\n", flag == true ? "Yes" : "No");
	cout << s[s.size()-1];
	for (int i = s.size()-2; i >= 0; i--)
		cout <<" " << s[i];
}
