#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int res[205][205];
int a[205];

int dp(int i, int j)
{
  if (res[i][j] != -1)
    return res[i][j];
  if (i == j) return res[i][j] = 0;

  int ans = 0;
  for (int k = i; k < j; ++k)
    ans = max(ans, dp(i, k) + dp(k+1, j) + a[i]*a[j+1]*a[k+1]);

  return res[i][j] = ans;
}

int main()
{
  int n;

  while (scanf("%d", &n) != EOF)
  {
    memset(res, -1, sizeof res);

    for (int i = 1; i <= n; ++i)
    {
      scanf("%d", &a[i]);
      a[n+i] = a[i];
    }
    //a[2*n+1] = a[1];

    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = max(res, dp(i, i+n-1));
    printf("%d\n", res);
  }
  
  return 0;
}