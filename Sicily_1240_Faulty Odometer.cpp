#include <stdio.h>
#include <math.h>

int has_four(int n);

int main()
{
	int i,n,count;
	while (scanf("%d",&n) && n != 0)
	{
		count = 0;
		printf("%d: %d\n",n,has_four(n));
	}
	
	return 0;
}

int has_four(int n)
{
	int i=n,count=0,m=0;
	
	while (n)
	{
		if (n % 10 < 4) i-= count * (n % 10);
		else i -= count * (n % 10 - 1) + (int)pow(10,m);
		n /= 10;
		count = count * 9 + (int)pow(10,m);
		m++;
	}
	return i;
}
