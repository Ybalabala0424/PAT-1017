// 走迷宫.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int n, m;
int a[16][16];
int startx, starty, endx, endy,result=0;
int changex[5] = { -1, 0, 1, 0 };
int changey[5] = { 0,1,0,-1 };
struct node 
{
	int row;
	int line;
};
vector<node> nodeArr;

void dfs(int x, int y)
{
	if (x == endx&&y==endy)
	{
		cout << "(" << startx << "," << starty << ")";
		for (int i = 0; i < nodeArr.size(); i++)
		{
			cout << "->(" << nodeArr[i].row << "," << nodeArr[i].line << ")";
		}
		++result;
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nodex, nodey;
			nodex = x + changex[i];
			nodey = y + changey[i];
			if (a[nodex][nodey] == 1)
			{
				a[nodex][nodey] = 0;
				node m = { nodex,nodey };
				nodeArr.push_back(m);
				dfs(nodex, nodey);
				a[nodex][nodey] = 1;
				nodeArr.pop_back();
			}
			
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> startx >> starty >> endx >> endy;
	a[startx][starty] = 0;
	dfs(startx, starty);
	if (result==0)
	{
		cout << "-1";
	}
}
