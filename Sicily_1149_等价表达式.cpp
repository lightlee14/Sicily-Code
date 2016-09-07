#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;
const int maxn = 1005;
const ll MOD = 100000+7;

//key
ll power(ll a, ll b)
{
  if (b == 0) return 1;
  return a*power(a, b-1);
}

int priority(char c)
{
  if (c == '+' || c == '-') return 1;
  if (c == '*') return 2;
  if (c == '^') return 3;
}

string deal(string s)
{
  int n = 0, len = s.size();
  string res = "";
  stack<char> tmp;
  while (!tmp.empty()) tmp.pop();

  for (int i = 0; i < len; ++i)
  {
    if (s[i] == '(') tmp.push(s[i]);
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '^')
    {
      if (tmp.empty()) tmp.push(s[i]);
      else
      {
        char c = tmp.top();
        if (c == '(' || priority(c) < priority(s[i])) tmp.push(s[i]);
        else
        {
          while (!tmp.empty())
          {
            char t = tmp.top();
            if (t == '(' || priority(t) < priority(s[i])) break;
            tmp.pop();
            res += ' ';
            res += t;
          }
          tmp.push(s[i]);
        }
      }
    }
    if (s[i] == ')')
    {
      while (!tmp.empty() && tmp.top() != '(')
      {
        char t = tmp.top();
        tmp.pop();
        res += ' ';
        res += t;
      }
      if (tmp.empty()) return "";
      if (!tmp.empty() && tmp.top() == '(') tmp.pop();
    }
    if (s[i] == 'a') res += " a";
    if (s[i] >= '0' && s[i] <= '9' && (i == 0 || s[i - 1] < '0' || s[i - 1] > '9')) res += ' ', res += s[i];
    if (s[i] >= '0' && s[i] <= '9' && i > 0 && s[i - 1] >= '0' && s[i - 1] <= '9') res += s[i];
  }
  while (!tmp.empty())
  {
    res += ' ';
    char c = tmp.top();
    tmp.pop();
    res += c;
  }

  return res;
}

bool cal(string s, ll *res)
{
  stack<ll> num[maxn];
  for (int i = 0; i < maxn; ++i) while (!num[i].empty()) num[i].pop();
  int len = s.size();
  ll tmp = 0;

  for (int i = 0; i < len; ++i)
  {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '^')
    {
      for (int j = 0; j < maxn; ++j)
      {
        ll a, b;
        if (!num[j].empty()) a = num[j].top();
        else return false;
        num[j].pop();
        if (!num[j].empty()) b = num[j].top();
        else return false;
        num[j].pop();
        //cout << a << ' ' << b << ' ' << s[i] << endl;
        if (s[i] == '+') num[j].push(a + b);
        else if (s[i] == '-') num[j].push(b - a);
        else if (s[i] == '*') num[j].push(a*b);
        else if (s[i] == '^') num[j].push(power(b, a));
      }
    }
    else if (s[i] == 'a')
      for (int j = 0; j < maxn; ++j) num[j].push(j);
    else if (s[i] >= '0' && s[i] <= '9')
    {
      tmp *= 10;
      tmp += (ll)(s[i] - '0');
      if (s[i+1] < '0' || s[i+1] > '9')
      {
        for (int j = 0; j < maxn; ++j) num[j].push(tmp);
        tmp = 0;
      }
    }
  }
  for (int j = 0; j < maxn; ++j)
  {
    if (!num[j].empty())
      res[j] = num[j].top();
    else
      return false;
  }

  return true;
}

ll res[maxn + 10], tmp[maxn + 10];

int main()
{
  string s;
  getline(cin, s);
  string d = deal(s);
  // << d << ',' << endl;
  cal(d, res);
  //for (int i = 0; i < 5; ++i) cout << res[i] << ' ';

  int n;
  cin >> n;
  getchar();
  for (int i = 0; i < n; ++i)
  {
    getline(cin, s);
    string ds = deal(s);
    cout << ds << '.' << endl;
    if (ds == "") continue;
    if (!cal(ds, tmp)) continue;

    bool equal = true;
    for (int j = 0; j < maxn; ++j) if (fabs(res[j] - tmp[j]) > 1e-9)
    {
      equal = false;
      break;
    }
    if (equal) cout << (char)(i + 'A');
  }
  cout << endl;

  return 0;
}