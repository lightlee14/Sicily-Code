#include <stdio.h>

int gcd(int a, int b);

int main()
{
	int i,n,a,b;
	
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d %d %d\n", i + 1, a * b / gcd(a,b), gcd(a,b));
	}
	
	return 0;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b,a % b);
}
