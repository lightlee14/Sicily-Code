#include <stdio.h>
#include <string.h>

typedef long long ll;

#define MAXN (ll)1e16

ll a[85];
ll fh[85][85], fl[85][85];

bool amax(ll ah, ll al, ll bh, ll bl)
{
  if (ah != bh) return ah > bh;
  else return al > bl;
}

int main()
{
  int n, m;
  bool flag = true;

  while (scanf("%d%d", &n, &m) != EOF)
  {
    ll toth, totl;
    toth = totl = 0;

    for (int k = 0; k < n; ++k)
    {
      memset(fh, 0, sizeof(fh));
      memset(fl, 0, sizeof(fl));

      for (int i = 1; i <= m; ++i) scanf("%lld", &a[i]);
      for (int j = 1; j <= m; ++j)
        for (int i = j; i > 0; --i)
        {
          if (i == j) fl[i][j] = a[i];
          else
          {
            ll ah = fh[i+1][j]*2;
            ll al = fl[i+1][j]*2 + a[i];
            if (al > MAXN)
            {
              ah += al / MAXN;
              al %= MAXN;
            }

            ll bh = fh[i][j-1]*2;
            ll bl = fl[i][j-1]*2 + a[j];
            if (bl > MAXN)
            {
              bh += bl / MAXN;
              bl %= MAXN;
            }

            if (amax(ah, al, bh, bl))
            {
              fh[i][j] = ah;
              fl[i][j] = al;
            }
            else
            {
              fh[i][j] = bh;
              fl[i][j] = bl;
            }
          }
        }
      toth += fh[1][m] * 2;
      totl += fl[1][m] * 2;
      if (totl > MAXN)
      {
        toth += totl / MAXN;
        totl %= MAXN;
      }
    }
    if (flag) flag = false;
    else printf("\n");

    if (toth) printf("%lld%016lld\n", toth, totl);
    else printf("%lld\n", totl);
  }

  return 0;
}