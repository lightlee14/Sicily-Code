#include <stdio.h>

int digit[15];

int main()
{
	int i,n,number,temp;
	
	scanf("%d",&n);
	while (n--)
	{
		for (i = 0; i < 15; i++) digit[i] = 0;
		
		scanf("%d",&number);
		for (i = 1; i <= number; i++)
		{
			temp=i;
			while (temp)
			{
				digit[temp % 10] += 1;
				temp /= 10;
			}
		}
		
		for (i = 0; i < 9; i++) printf("%d ",digit[i]);
		printf("%d\n",digit[9]);
	}
	
	return 0;
}
