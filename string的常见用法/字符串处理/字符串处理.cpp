// 字符串处理.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
int dotIndex = 0, eIndex = 0;
bool resultFlag = false;

float processStr(string n)
{
	bool eflag = false;
	float result;
	string e = "";
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == '.')
		{
			dotIndex = i;
		}
		if (n[i]=='e'||n[i]=='E')
		{
			eIndex = i;
			eflag = true;
			resultFlag = true;
		}
		if (eflag)
		{
			e += n[i];
		}
	}
	if (eflag)
	{
		e.erase(e.begin(),++e.begin());
		float eNum = stof(e);
		string fore;
		for (int i = 0; i < eIndex; i++)
		{
			fore += n[i];
		}
		float forenum = stof(fore);
		result = forenum * pow(10, eNum);
	}
	else
	{
		result = stof(n);
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string n, m;
	while (cin >> n >> m)
	{
		float result1,result2,result;
		result1 = processStr(n);
		result2 = processStr(m);
		result = result1 + result2;
		if (resultFlag)
		{
			cout << setprecision(6) << scientific;
			cout << result << endl;
		}
		else
			cout << result;
	}
}
