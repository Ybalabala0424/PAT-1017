// Course List for Student.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int n, k;
struct student {
	string name;
	vector<int> courses;
};

int searchIndex(vector<student> students,string name)
{
	bool flag = false;
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].name ==name)
		{
			flag = true;
			return i;
		}
	}
	if (flag == false)
	{
		return -1;
	}
}

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	vector<student> students;
	for (int i = 1; i <= k; i++)
	{
		int coursei, studentNum;
		cin >> coursei >> studentNum;
		for (int j = 1; j <= studentNum; j++)
		{
			string name;
			cin >> name;
			int index = searchIndex(students, name);
			if (index == -1)
			{
				student newStud;
				newStud.name = name;
				newStud.courses.push_back(coursei);
				students.push_back(newStud);
			}
			else
			{
				students[index].courses.push_back(coursei);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		int index = searchIndex(students, name);
		if (index == -1)
		{
			cout << name << " " << 0 << endl;
		}
		else
		{
			sort(students[index].courses.begin(),students[index].courses.end(),cmp);
			cout << name << " " << students[index].courses.size();
			for (int j = 0; j < students[index].courses.size(); j++)
			{
				cout << " " << students[index].courses[j];
			}
			cout << endl;
		}
	}
}