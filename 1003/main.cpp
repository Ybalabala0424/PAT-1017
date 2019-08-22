// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;
int n, m, C1, C2;
int rescueNum[501], rescueSum[501], roadNum[501], relation[501][501];
const int Inf = 99999999;
bool visit[501] = { true };

int main()
{
    // 读取第一行的四个数字 城市数、道路书、所在城市标识、救援城市标识
    cin >> n >> m >> C1 >> C2;
    // 获取每个城市的救援队数量
    for (int i = 0; i < n; i++)
        cin >> rescueNum[i];
    // 初始化邻接矩阵
    fill(relation[0], relation[0] + 501 * 501, Inf);
    // 获取城市之间的点对关系 形成邻接矩阵
    for (int i = 0; i < m; i++)
    {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        relation[c1][c2] = relation[c2][c1] = l;
    }

    // 设置所在城市bool为true 即在接下来的遍历中不可以再次遍历
    visit[C1] = false;
    roadNum[C1] = 1;
    for (int i = 0; i < n; i++)
    {
        int min = Inf;
        int minPoint = -1;
        // 为了在可选择的点中找到路径最小的点
        for (int j = 0; j < n; j++)
        {
            if (visit[j] && relation[C1][j] < min)
            {
                min = relation[C1][j];
                minPoint = j;
            }
        }
        if (minPoint == -1) break;
        visit[minPoint] = false;
        // 更新点点之间的路径长度
        for (int k = 0; k < n; k++)
        {
            if (relation[minPoint][k] != Inf)
            {
                if (relation[C1][minPoint] + relation[minPoint][k] < relation[C1][k])
                {
                    relation[C1][k] = relation[C1][minPoint] + relation[minPoint][k];
                    roadNum[k] = roadNum[minPoint];
                    rescueSum[k] = rescueSum[minPoint] + rescueNum[k];
                }
                else if (relation[C1][minPoint] + relation[minPoint][k] == relation[C1][k])
                {
                    roadNum[k] +=  roadNum[minPoint];
                    if (rescueSum[minPoint] + rescueNum[k] > rescueSum[k])
                        rescueSum[k] = rescueSum[minPoint] + rescueNum[k];
                }
            }
        }
    }
    cout << roadNum[C2] << " " << rescueSum[C2];
    return 0;
}

