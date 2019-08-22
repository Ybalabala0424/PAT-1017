// 1004.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
// node数组用于记录点点之间的父子关系
// leave数组用于记录每一层的叶子节点数
int node[510][510], leave[510];
int maxnum = -1;

// 读取节点总数n和非叶子节点数m
// 读取m行 记录每一个非叶子节点其子节点数及点点之间的父子关系
// 读取时用二维数组记录，二维第一个数字为子节点数，之后跟子节点标记
// 本题目的是获取每一层的叶子节点数
// 采用深度遍历搜索，从根节点出发遍历，每下一个节点就多一个层次（depth++）
// 如果该层次找到叶子节点，则leave[depth]++

void bfs(int tag, int depth)
{
	if (node[tag][0] == 0)
	{
		leave[depth] += 1;
		maxnum = max(maxnum, depth);
		return;
	}
	else
	{
		for (int i = 1; i <= node[tag][0]; i++)
		{
			int sonTag = node[tag][i];
			int m = depth;
			bfs(sonTag, ++m);
		}
	}
}

int main()
{
	// 读取节点总数n和非叶子结点数m
	cin >> n >> m;
	// 初始化node和leave数组
	fill(node[0], node[0] + 510 * 510, 0);
	fill(leave, leave + 510, 0);
	// 读取点点之间的父子关系
	for (int i = 0; i < m; i++)
	{
		int id, num;
		cin >> id >> num;
		node[id][0] = num;
		for (int j = 1; j <= num; j++)
		{
			int sonNode;
			cin >> sonNode;
			node[id][j] = sonNode;
		}
	}
	// 查找每一层的叶子节点
	for (int k = 1; k <= node[1][0]; k++)
	{
		bfs(node[1][k], 2);
	}
	cout << leave[1];
	for (int i = 2; i <= maxnum; i++)
	{
		cout << " " << leave[i];
	}
	return 0;
}
