#include<stdio.h>

int sort(int *a, int n)
{
	int i,j,count,min,minj;
	
	count = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = a[i];
		minj = i;
		
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				count++;
				min = a[j];
				minj = j;
			}
		}
		
		a[minj] = a[i];
		a[i] = min;
	}
	
	return count;
}

int a[105];

int main()
{
	int i,n,t;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i = 0; i < n; i++) scanf("%d",&a[i]);
		printf("%d\n",sort(a,n));
	}
	
	
	return 0;
}
