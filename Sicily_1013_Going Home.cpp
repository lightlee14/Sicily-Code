#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 105;

int home[maxn], men[maxn];
int W[maxn][maxn], n;
int Lx[maxn], Ly[maxn];
int left[maxn];
bool S[maxn], T[maxn];

int abs(int i) { return i > 0 ? i : -i; }

bool match(int i)
{
  S[i] = true;
  for (int j = 1; j <= n; ++j) if (Lx[i] + Ly[j] == W[i][j] && !T[j])
  {
    T[j] = true;
    if (!left[j] || match(left[j]))
    {
      left[j] = i;
      return true;
    }
  }
  return false;
}

void update()
{
  int a = 1<<30;
  for (int i = 1; i <= n; ++i) if (S[i])
    for (int j = 1; j <= n; ++j) if (!T[j])
      a = min(a, Lx[i] + Ly[j] - W[i][j]);
  for (int i = 1; i <= n; ++i)
  {
    if (S[i]) Lx[i] -= a;
    if (T[i]) Ly[i] += a;
  }
}

void KM()
{
  for (int i = 1; i <= n; ++i)
  {
    left[i] = Lx[i] = Ly[i] = 0;
    for (int j = 1; j <= n; ++j)
      Lx[i] = max(Lx[i], W[i][j]);
  }
  for (int i = 1; i <= n; ++i)
  {
    for (;;)
    {
      for (int j = 1; j <= n; ++j) S[j] = T[j] = 0;
      if (match(i)) break;
      else update();
    }
  }
}

int main()
{
  int N, M;
  while (scanf("%d%d", &N, &M) != EOF && !(N == 0 && M == 0) )
  {
    char c, s[105];
    int counth, countm;
    counth = countm = 0;
    memset(W, 0, sizeof(W));

    for (int i = 0; i < N; ++i)
    {
      scanf("%s", s);
      for (int j = 0; j < M; ++j)
      {
        c = s[j];
        if (c == 'H') home[counth++] = i*M + j;
        else if (c == 'm') men[countm++] = i*M + j;
      }
    }
    n = max(counth, countm);
    for (int i = 0; i < countm; ++i)
    {
      for (int j = 0; j < counth; ++j)
      {
        int tx = abs(home[j]/M - men[i]/M);
        int ty = abs(home[j]%M - men[i]%M);
        W[i+1][j+1] = -(tx + ty);
        //printf("(%d-%d) (%d-%d)->%d\n", men[i]/M, men[i]%M, home[j]/M, home[j]%M, W[i][j]);
      }
    }
    KM();
    int res = 0;
    for (int i = 1; i <= n; ++i) res += (Lx[i] + Ly[i]);
    printf("%d\n", -res);
  }

  return 0;
}