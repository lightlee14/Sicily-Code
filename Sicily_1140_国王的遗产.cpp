#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 30005;
int res, minNum, startNode, total, rootID;
bool hasRoot;

struct Node
{
  vector<int> next;
  int tot, minID;
}node[maxn];

vector<int> u[maxn];
bool used[maxn];

void build(int root)
{
  used[root] = -1; // under used
  node[root].next.resize(0);
  node[root].tot = 1;
  node[root].minID = root;

  int len = u[root].size();
  for (int i = 0; i < len; ++i) if (used[u[root][i]] == 0)
  {
    int cur = u[root][i];
    build(cur);
    node[root].next.push_back(cur);
    node[root].tot += node[cur].tot;
    node[root].minID = min(node[root].minID, node[cur].minID);
  }
  used[root] = 0; // used end
}

void search(int root)
{
  vector<int> &next = node[root].next;
  int len = next.size();

  for (int i = 0; i < len; ++i)
  {
    int cur = next[i];
    int rest = total - node[cur].tot;
    if (node[cur].tot >= rest)
    {
      if (rest < res) continue;
      else if (rest > res || (rest == res && node[cur].minID > node[startNode].minID))
      {
        res = rest;
        hasRoot = true;
        minNum = rootID;
        startNode = cur;
      }
    }
    else
    {
      if (node[cur].tot < res) continue;
      else if (node[cur].tot > res || (!hasRoot && node[cur].minID < minNum))
      {
        res = node[cur].tot;
        hasRoot = false;
        minNum = node[cur].minID;
        startNode = cur;
      }
    }
    search(cur);
  }
}

void token(int root, int v)
{
  vector<int> &next = node[root].next;
  int len = next.size();

  for (int i = 0; i < len; ++i)
  {
    int cur = next[i];
    token(cur, v);
  }
  used[root] = v;
}

int main()
{
  int n, k, gone = 0;
  for (int i = 0; i < maxn; ++i) u[i].resize(0);
  memset(used, 0, sizeof(used));

  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i)
  {
    int x, y;

    scanf("%d%d", &x, &y);
    u[x].push_back(y);
    u[y].push_back(x);
  }

  for (int i = 0; i < k-1; ++i)
  {
    int root = 1;

    while (used[root] && root < n) root++;
    build(root);
    // printf("root->%d:\n", root);
    // for (int j = 1; j <= n; ++j)
    // {
    //   printf("%d-next:", j);
    //   for (int k = 0; k < node[j].next.size(); ++k) printf(" %d", node[j].next[k]);
    //   printf("\n");
    //   printf("%d-tot: %d\n", j, node[j].tot);
    //   printf("%d-minID: %d\n", j, node[j].minID);
    // }
    // system("pause");
    res = 0;
    total = node[root].tot;
    rootID = root;
    search(root);
    // printf("%d-%d-%d-%d\n", res, minNum, startNode, hasRoot);
    if (hasRoot) token(root, 1), token(startNode, 0);
    else token(startNode, 1);

    printf("%d ", res);
    gone += res;
  }
  printf("%d\n", n - gone);

  return 0;
}