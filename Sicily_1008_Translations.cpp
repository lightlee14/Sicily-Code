#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

int l1[55][55], l2[55][55], res[55], size;
bool used[55];

bool check(const vector<int>& a, const vector<int>& b)
{
  bool ans = true;
  for (int i = 0; i < a.size(); ++i) if (res[a[i]] != -1)
  {
    int j, m = res[a[i]];
    for (j = 0; j < b.size(); ++j) if (m == b[j]) break;
    if (j == b.size())
    {
      ans = false;
      break;
    }
  }
  return ans;
}

bool find(int n)
{
  if (n == size) return true;
  vector<int> npred, nsucc, mpred, msucc;
  npred.resize(0);
  nsucc.resize(0);
  for (int i = 0; i < size; ++i)
  {
    if (l1[i][n]) npred.push_back(i);
    if (l1[n][i]) nsucc.push_back(i);
  }

  for (int i = 0; i < size; ++i) if (!used[i])
  {
    mpred.resize(0);
    msucc.resize(0);
    for (int j = 0; j < size; ++j)
    {
      if (l2[j][i]) mpred.push_back(j);
      if (l2[i][j]) msucc.push_back(j);
    }
    if (npred.size() == mpred.size() && nsucc.size() == msucc.size())
    {
      if (check(npred, mpred) && check(nsucc, msucc))
      {
        res[n] = i; used[i] = true;
        if (find(n + 1)) return true;
        else res[n] = -1, used[i] = false;
      }
    }
  }
  return false;
}

int main()
{
  int n;
  bool flag = true;

  while (cin >> n && n)
  {
    memset(l1, 0, sizeof(l1));
    memset(l2, 0, sizeof(l2));
    memset(res, -1, sizeof(res));
    memset(used, 0, sizeof(used));
    map<string, int> lm1, lm2;
    lm1.clear();
    lm2.clear();
    string s1, s2, words1[55], words2[55];
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
      cin >> s1 >> s2;
      if (lm1.count(s1) == 0) lm1[s1] = count, words1[count++] = s1;
      if (lm1.count(s2) == 0) lm1[s2] = count, words1[count++] = s2;
      l1[lm1[s1]][lm1[s2]] = 1;
    }
    count = 0;
    for (int i = 0; i < n; ++i)
    {
      cin >> s1 >> s2;
      if (lm2.count(s1) == 0) lm2[s1] = count, words2[count++] = s1;
      if (lm2.count(s2) == 0) lm2[s2] = count, words2[count++] = s2;
      l2[lm2[s1]][lm2[s2]] = 1;
    }

    size = count;
    if (find(0))
    {
      map<string, string> ans;
      ans.clear();
      for (int i = 0; i < size; ++i) ans[words1[i]] = words2[res[i]];
      map<string, string>::iterator it;
      if (flag) flag = false;
      else cout << endl;
      for (it = ans.begin(); it != ans.end(); ++it) cout << it->first << '/' << it->second << endl;
    }
    else
      cout << "Can not find!" << endl;
  }

  return 0;
}