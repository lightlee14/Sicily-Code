#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int pro[10005];

class cmp
{
public:
  bool operator ()(const int& lhs, const int& rhs) const { return lhs < rhs; }
};

int main()
{
  ios::sync_with_stdio(false);
  priority_queue<int, vector<int>, cmp> maxQueue;
  priority_queue<int, vector<int>, greater<int> > minQueue;
  queue<int> removal;
  int maxCost, listLen;
  bool flag = true;

  while (cin >> maxCost >> listLen)
  {
    if (flag) flag = false;
    else cout << '\n';

    memset(pro, 0, sizeof pro);
    int p = 1;
    int t, count = 0;

    while (!removal.empty()) removal.pop();
    for (int i = 0; i < listLen; ++i)
    {
      cin >> t;
      removal.push(t);
    }

    bool end = false;
    while (!maxQueue.empty()) maxQueue.pop();
    while (!minQueue.empty()) minQueue.pop();
    while(!end)
    {
      char comm;

      cin >> comm;
      if (comm == 'e') end = true;
      else if (comm == 'r')
      {
        count ++;
        t = -1; // init
        if (p == 1)
        {
          while (!minQueue.empty())
          {
            t = minQueue.top();
            minQueue.pop();
            if (pro[t] > 0) break;
          }
        }
        else
        {
          while (!maxQueue.empty())
          {
            t = maxQueue.top();
            maxQueue.pop();
            if (pro[t] > 0) break;
          }
        }

        bool print = count == removal.front();
        if (print)
        {
          cout << t << '\n';
          removal.pop();
          if (t != -1) pro[t] --;
        }
      }
      else if (comm == 'a')
      {
        cin >> t;
        maxQueue.push(t);
        minQueue.push(t);
        pro[t]++;
      }
      else if (comm == 'p')
      {
        cin >> t;
        p = t;
      }
    }
  }
  

  return 0;
}