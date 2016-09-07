#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, k;
int a[105], dp[105][205][3], s[105][105];
// dp[cur][i][j] cur is the cur node, i is the next node in tree, j means come back to cur or not

void solve(int cur, int fa, int step)
{
  for (int i = 1; i <= n; ++i) if (s[cur][i] && i != fa)
  {
    solve(i, cur, step-1);
    for (int j = step; j >= 0; --j)
    {
      for (int kk = j; kk > 0; --kk)
      {
        if (kk >= 2)
        {
          dp[cur][j][0] = max(dp[cur][j][0], dp[cur][j-kk][0] + dp[i][kk-2][0]);
          dp[cur][j][1] = max(dp[cur][j][1], dp[cur][j-kk][1] + dp[i][kk-2][0]);
        }
        if (kk >= 1)
          dp[cur][j][1] = max(dp[cur][j][1], dp[cur][j-kk][0] + dp[i][kk-1][1]);
      }
    }
  }
}

int main()
{
  while (~scanf("%d%d", &n, &k))
  {
    memset(dp, 0, sizeof dp);
    memset(s, 0, sizeof s);

    for (int i = 1; i <= n; ++i)
    {
      scanf("%d", &a[i]);
      // dp initialize
      for (int j = 0; j <= k; ++j) dp[i][j][0] = dp[i][j][1] = a[i];
    }
    for (int i = 0; i < n-1; ++i)
    {
      int a, b;
      scanf("%d%d", &a, &b);
      s[a][b] = s[b][a] = 1;
    }
    solve(1, -1, k);

    printf("%d\n", max(dp[1][k][0], dp[1][k][1]));
  }

  return 0;
}