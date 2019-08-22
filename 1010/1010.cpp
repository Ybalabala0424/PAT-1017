// 1010.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 题目要求找出两个数之间的基数
// Input: N1 N2 tag radix基数
// tag为1表示N1的基数为radix，反之N2的基数为radix
// 先通过tag和radix算出一个的十进制数
//   踩坑1：
//    input中的数字可以是10位数，数值可以很大，另外radix也可以数值很大
//    因此需要把radix相关的变量以及n1、n2都设置为long long
// 取出另一个数的每个位数值 Radix<radix 在其中进行运算
//   踩坑2：
//     1. 上界判断错误 没有考虑到下界
//        下界由题目可得是每一位中数值的最大数+1 每一位的数值都小于其radix
//        上界不一定是给定的radix基数+1
//        有可能下界的值大于radix基数+1 因此需要进行判断
//     2. 遍历找出radix 很可能会运算超时 又加上是简单的遍历单调区间
//        所以采用二分查找
//   二分查找时，不可直接计算出某个radix下数的值，因为可能会导致longlong溢出
//   所以需要使用特定的compare函数，在累加的过程中判断是否大于另一个数
// 当运算结果等于十进制数时，则输出基数
//    踩坑3:
//      没有考虑到a-z的情况
const int inf = 99999999;

int main()
{
	long long n1, n2, radix, temp, sum = 0, target; // sum表示给出基数值那个值的十进制数
	int tag;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 1)
	{
		temp = n1;
		target = n2;
	}
	else
	{
		temp = n2;
		target = n1;
	}
	int e = 0;
	while (temp != 0)
	{
		int a = temp % 10;
		int b = pow(radix, e);
		sum += a * b;
		temp = temp / 10;
		e++;
	}
	vector<int> v(11);
	int num = 0;
	while (target != 0)
	{
		int a = target % 10;
		v[num] = a;
		num++;
		target = target / 10;
	}
	int all = 0, k = 2;
	while (k <= radix && all != sum)
	{
		for (int j = 0; j < num; j++)
		{
			all += v[j] * pow(k, j);
		}
		k++;
	}
	if (k > radix)
	{
		cout << "Impossible";
	}
	else
	{
		cout << k - 1;
	}
	return 0;
}