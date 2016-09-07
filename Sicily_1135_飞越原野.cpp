#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

vector<int> v[10005], flyTo[10005], energy[10005];
int fly[10005][105], vis[10005][105];
int s[105][105];

int main()
{
  int n, m, d, count, stop;
  memset(fly, -1, sizeof(fly));
  memset(s, 0, sizeof(s));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 10005; ++i) v[i].resize(0), flyTo[i].resize(0), energy[i].resize(0);

  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0; i < n; ++i)
  {
    char tmp[105];
    scanf("%s", tmp);
    for (int j = 0; j < m; ++j)
      if (tmp[j] == 'P') s[i][j] = 1;
  }
  // for (int i = 0; i < n; ++i)
  // {
  //   for (int j = 0; j < m; ++j) printf("%d", s[i][j]);
  //   printf("\n");
  // }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) if (s[i][j])
    {
      int cur = i*m+j;

      if (j-1 >= 0 && s[i][j-1]) v[cur].push_back(i*m+j-1);
      if (j+1 < m && s[i][j+1]) v[cur].push_back(i*m+j+1);
      if (i-1 >= 0 && s[i-1][j]) v[cur].push_back((i-1)*m+j);
      if (i+1 < n && s[i+1][j]) v[cur].push_back((i+1)*m+j);

      // printf("%d->", cur);
      // for (int k = 0; k < v[cur].size(); ++k)printf(" %d", v[cur][k]);
      // printf("\n");

      // fly edge
      for (int k = 1; k <= d; ++k)
      {
        if (j-k >= 0 && s[i][j-k]) flyTo[cur].push_back(i*m+j-k), energy[cur].push_back(k);
        if (j+k < m && s[i][j+k]) flyTo[cur].push_back(i*m+j+k), energy[cur].push_back(k);
        if (i-k >= 0 && s[i-k][j]) flyTo[cur].push_back((i-k)*m+j), energy[cur].push_back(k);
        if (i+k < n && s[i+k][j]) flyTo[cur].push_back((i+k)*m+j), energy[cur].push_back(k);
      }
    }

  // bfs search
  queue<int> q;
  while (!q.empty()) q.pop();
  q.push(0);
  fly[0][0] = count = 0;
  vis[0][0] = 1;
  stop = n*m-1;
  while (!q.empty())
  {
    int cur = q.front();
    int mag = cur % (d+1);
    cur /= (d+1);
    // printf("%d-%d-%d\n", cur, mag, fly[cur][mag]);
    if (cur == stop) count ++;
    if (count == d+1) break;
    q.pop();

    int len = v[cur].size();
    for (int i = 0; i < len; ++i)
    {
      int next = v[cur][i];
      if (!vis[next][mag])
      {
        vis[next][mag] = 1;
        fly[next][mag] = fly[cur][mag] + 1;
        q.push(next*(d+1)+mag);
      }
    }

    len = flyTo[cur].size();
    for (int i = 0; i < len; ++i)
    {
      int next = flyTo[cur][i];
      int ener = energy[cur][i];
      if (mag+ener <= d && !vis[next][mag+ener])
      {
        vis[next][mag+ener] = 1;
        fly[next][mag+ener] = fly[cur][mag] + 1;
        q.push(next*(d+1)+mag+ener);
      }
    }
  }

  int ans = -1;
  bool flag = false;
  for (int i = 0; i <= d; ++i) if (fly[stop][i] != -1)
  {
    int tmp = fly[stop][i];
    if (flag) ans = ans > tmp ? tmp : ans;
    else ans = tmp;
    flag = true;
  }

  if (flag) printf("%d\n", ans);
  else printf("impossible\n");

  return 0;
}