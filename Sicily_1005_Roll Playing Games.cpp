#include <stdio.h>
#include <string.h>

int n, r, m, v[15], c[15], res[10], min;
int dp[2][1005];

bool search(int cur, int start)
{
  for (int i = 0; i < m; ++i) if (c[i] < 0) return false;
  if (cur == r)
  {
    for (int i = 0; i < m; ++i)
      if (c[i] != 0) return false;

    return true;
  }
  for (int i = start; i <= 50; ++i)
  {
    res[cur] = i;
    for (int j = 0; j < m; ++j)
    {
      if (min + i > v[j] && c[j] != 0) return false;
      if (v[j] - i > 0) c[j] -= dp[0][v[j] - i];
    }

    if (search(cur + 1, i)) return true;
    for (int j = 0; j < m; ++j) if (v[j] - i > 0) c[j] += dp[0][v[j] - i];
  }

  return false;
}

int main()
{
  while (scanf("%d", &n) != EOF && n)
  {
    int f, vf;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i)
    {
      scanf("%d", &f);

      for (int j = 0; j < f; ++j)
      {
        scanf("%d", &vf);

        if (i == 1) dp[1][vf] += 1;
        else for (int k = vf; k <= i*50; ++k) if (dp[0][k-vf] > 0)
        {
          dp[1][k] += dp[0][k-vf];
        }
      }
      memcpy(dp[0], dp[1], sizeof(int)*1005);
      memset(dp[1], 0, sizeof(int)*1005);
    }
    scanf("%d%d", &r, &m);
    for (int i = 0; i < m; ++i) scanf("%d%d", &v[i], &c[i]);
    min = 0;
    while(dp[0][min] == 0) min++;

    if (search(0, 1))
    {
      printf("Final die face values are");
      for (int i = 0; i < r; ++i) printf(" %d", res[i]);
      printf("\n");
    }
    else printf("Impossible\n");
  }

  return 0;
}