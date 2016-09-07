#include<stdio.h>
#include<math.h>

bool hNumber(int n);

int main()
{
	int i,n,count=0;
	
	scanf("%d",&n);
	for (i = 1; i <= n; i++) if (hNumber(i)) count++;
	printf("%d\n",count);
	
	return 0;
}

bool hNumber(int n)
{
	int pre,cur,next;
	
	if (n < 100) return true;
	
	cur = n % 10;  //Ä£Äâ 
	n /= 10;
	pre = n % 10;
	n /= 10;
	while (n)
	{
		next = cur;
		cur = pre;
		pre = n % 10;
		n /= 10;
		if (cur != pre + next && cur != (pre > next ? pre - next : next - pre) )
		 return false;
	}
	
	return true;
}
