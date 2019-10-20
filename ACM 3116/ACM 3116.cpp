// ACM 3116.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
struct node {
	int data;
	struct node* next;
};


int main()
{
	// 关闭数据流
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	struct node* p, * q, * a[5001];
	while (cin >> n >> m) {
		memset(a, NULL, sizeof(a));
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			if (a[u] == NULL)
			{
				p = (struct node*)malloc(sizeof(struct node));
				p->data = v;
				p->next = NULL;
				a[u] = p;
			}
			else
			{
				p = (struct node*)malloc(sizeof(struct node));
				p->data = v;
				p->next = NULL;
				a[u]->next = p;
			}
		}
		int q1;
		cin >> q1;
		for (int i = 0; i < q1; i++)
		{
			int a1, b1;
			bool flag =false;
			cin >> a1 >> b1;
			q = a[a1];
			while (q!=NULL)
			{
				if (q->data==b1)
				{
					flag = true;
					break;
				}
				q = q->next;
			}
			if (flag == true)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}

	return 0;
}
