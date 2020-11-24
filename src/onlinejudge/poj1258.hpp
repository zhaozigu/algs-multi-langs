#pragma once
#include <algorithm>
#include <limits>
#include <cstring>
using std::max;
using std::min;

const int kMaxN = 1000;
const int INF = std::numeric_limits<int>::max();

class Solve
{
public:
  Solve(int n_)
  {
    n = n_;
  }

  int Prim()
  {
    memset(use, false, sizeof(use));
    use[0] = true;
    for (int i = 0; i < n; ++i)
    {
      dis[i] = INF;
    }
    dis[0] = INF; // 定义出发点的dist值
    int ans = 0;

    // 其他节点与出发点的边长定义为该节点与生成树的最短边长
    for (int i = 1; i < n; i++)
    {
      dis[i] = g[0][i];
    }

    // 拓展生成树的 n - 1 条边
    for (int i = 1; i < n; i++)
    {
      // 寻找与生成树相连边最短的节点 tmp
      int tmp = 0;
      for (int k = 1; k < n; k++)
      {
        if (dis[k] < dis[tmp] && !use[k])
          tmp = k;
      }
      ans += dis[tmp]; // 最短边计入生成树的边长和，节点 tmp 进入生成树
      use[tmp] = true;

      for (int k = 1; k < n; k++)
      {
        if (!use[k])
          dis[k] = min(dis[k], g[k][tmp]);
      }
    }
    return ans;
  }

  int *operator[](size_t x)
  {
    return g[x];
  }

private:
  int n;
  // 标记是否已经加入最小生成树
  bool use[kMaxN];
  // 记录未标记的节点i加入最小生成树的最小权值
  int dis[kMaxN];
  int g[kMaxN][kMaxN];
};
