// 1007.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

// Input: k 以及 k个整数
// 题目要求这k个整数序列中子序列和最大的那个子序列
// Output:最大子序列的和sum 以及 子序列中第一个和最后一个的整数值

// 由于要和最大的子序列 所以可以确定的是这个子序列头和尾都是正数
// 那么在读入数组的时候 将序列存在数组中 
// 以及将序列中正数下标存在positive数组中
// 从一个正数下标一直加到另一个正数下标 不断更新sum

int k, numbers[10000], positive[10000], sum = 0;
int posiNum = 0; // 正数总数
int first, last;

int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		numbers[i] = a;
		if (a > 0)
		{
			positive[posiNum++] = i;
		}
	}
	for (int j = 0; j < posiNum; j++)
	{
		for (int m = j + 1; m < posiNum; m++)
		{
			int max = 0, First, Last;
			First = positive[j];
			Last = positive[m];
			for (int i = First; i <= Last; i++)
			{
				max += numbers[i];
			}
			if (max > sum)
			{
				first = First;
				last = Last;
				sum = max;
			}
		}
	}
	if (last == (k - 2) && numbers[k - 1] > 0)
	{
		last = k - 1;
		sum += numbers[k - 1];
	}
	if (posiNum == 0)
	{
		cout << 0 << " " << numbers[0] << " " << numbers[k - 1];
	}
	cout << sum << " " << numbers[first] << " " << numbers[last];
	return 0;
}
