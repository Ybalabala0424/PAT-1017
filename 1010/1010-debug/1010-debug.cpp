// 1010-debug.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;

// 由于题目中input存在a-z的情况 所以选择用字符串string读入

long long num2Dec(char* p, long long radix)
{
	long long len = strlen(p);
	long long m = 1;
	long long num = 1;
	long long sum = 0;
	for (long long i = len - 1; i >= 0; i--)
	{
		if (p[i] >= 'a' && p[i] <= 'z')
			num = p[i] - 'a' + 10;
		else if (p[i] >= '0' && p[i] <= '9')
			num = p[i] - '0';
		sum += num * m;
		m *= radix;
	}
	return sum;
}

long long findLowRadix(char* p)
{
	long long len = strlen(p);
	long long low = 0;
	long long num;
	for (long long i = len - 1; i >= 0; i--)
	{
		if (p[i] >= 'a' && p[i] <= 'z')
			num = p[i] - 'a' + 10;
		else if (p[i] >= '0' && p[i] <= '9')
			num = p[i] - '0';
		if (num + 1 > low)
			low = num + 1;
	}
	return low;

}

int compare(char* p, long long radix, long long target)
{
	long long len = strlen(p);
	long long m = 1;
	long long num = 1;
	long long sum = 0;
	for (long long i = len - 1; i >= 0; i--)
	{
		if (p[i] >= 'a' && p[i] <= 'z')
			num = p[i] - 'a' + 10;
		else if (p[i] >= '0' && p[i] <= '9')
			num = p[i] - '0';
		sum += num * m;
		m *= radix;
		if (sum > target)  //avoid  overflow
			return 1;
	}

	if (sum > target)
		return 1;
	else if (sum < target)
		return -1;
	else
		return 0;

}

long long binarySearch(char* p, long long low, long long high, long long top)
{
	long long mid = low;
	long long tmp;

	while (low <= high)
	{
		tmp = compare(p, mid, top);
		if (tmp > 0)
		{
			high = mid - 1;
		}
		else if (tmp < 0)
		{
			low = mid + 1;
		}
		else
			return mid;
		mid = (low + high) / 2;
	}

	return -1;
}

int main()
{
	char n1[11], n2[11], temp[11], target[11];
	long long tag;
	long long radix, least = 0, max, sum = 0;
	cin >> n1;
	cin >> n2;
	cin >> tag;
	cin >> radix;
	if (tag == 1)
	{
		strcpy_s(temp,n2);
		strcpy_s(target, n1);
		// 计算n1的十进制数 radix为n1的基数
		sum = num2Dec(n1, radix);
	}
	else if (tag == 2)
	{
		strcpy_s(temp, n1);
		strcpy_s(target, n2);
		// 计算n2的十进制数 radix为n2的基数
		sum = num2Dec(n2, radix);
	}
	// 判断下界
	least = findLowRadix(temp);
	// 判断上界
	max = (radix + 1 > least + 1) ? radix + 1 : least + 1;
	// 找使两个数相等的基数 使用二分查找法
	long long res = binarySearch(temp, least, max, sum);
	if (res == -1)
		cout << "Impossible";
	else
		cout << res;
	return 0;
}
