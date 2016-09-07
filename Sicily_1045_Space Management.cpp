#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool has[1005][1005], ending[1005];
int toX[2005], toY[2005], s[1005][1005];
int px[1005], py[1005], ord[1005];

int cmpx(const int a, const int b) { return px[a] < px[b]; }
int cmpy(const int a, const int b) { return py[a] < py[b]; }

int main()
{
  int n;

  scanf("%d", &n);
  while (n--)
  {
    int m, x0, y0, x1, y1;
    memset(has, 0, sizeof has);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
      scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
      x1 += x0;
      y1 += y0;
      px[i * 2] = x0; px[i * 2 + 1] = x1;
      py[i * 2] = y0; py[i * 2 + 1] = y1;
      ord[i * 2] = i * 2; ord[i * 2 + 1] = i * 2 + 1;
      ending[i * 2 + 1] = i * 2;
    }

    sort(ord, ord + 2 * m, cmpx);
    for (int i = 0; i < 2 * m; ++i) toX[i] = px[ord[i]], px[ord[i]] = i;
    sort(ord, ord + 2 * m, cmpy);
    for (int i = 0; i < 2 * m; ++i) toY[i] = py[ord[i]], py[ord[i]] = i;
    for (int i = 0; i < 2 * m-1; ++i)
    {
      for (int j = 0; j < 2 * m-1; ++j)
      {
        s[i][j] = (toX[i + 1] - toX[i]) * (toY[j + 1] - toY[j]);
      }
    }

    for (int p = 0; p < m; ++p)
    {
      int m = 2 * p;
      for (int i = px[m]; i < px[m + 1]; ++i)
        for (int j = py[m]; j < py[m + 1]; ++j) has[i][j] = true;
    }

    int ans = 0;
    for (int i = 0; i < 1005; ++i)
      for (int j = 0; j < 1005; ++j) if (has[i][j]) ans += s[i][j];

    printf("%d\n", ans);
  }

  return 0;
}