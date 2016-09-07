#include <stdio.h>  
#include <math.h>  
#include <algorithm>  
  
using namespace std;  
  
int main()  
{  
  int n;  
  
  scanf("%d", &n);  
  for (int i = 0; i < n; ++i)  
  {  
    int a, b, s, e;  
  
    scanf("%d%d%d%d", &a, &b, &s, &e);  
    if (a < b) swap(a, b);  
    int s1 = ((s + e) * (e - s + 1) / 2 + b - a); //计算较小的和  
    int i1 = (sqrt((2*s-1)*(2*s-1) + 4*s1)-2*s+1) / 2; // 按不等式解出数字个数  
  
    if (s1 < 0 || s1 % 2 || i1 < 0) printf("not possible\n");  
    else  
    {  
      if ((2*e-i1+1)*i1 >= s1) printf("possible\n");  
      else printf("not possible\n");  
    }  
  }  
  
  return 0;  
}