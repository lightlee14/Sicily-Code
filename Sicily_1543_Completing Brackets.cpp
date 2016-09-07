#include<stdio.h>
#include<string.h>

char s[55];

int main()
{
	int i, len, count;
	
	while ( scanf("%s",s) != EOF)
	{
		count = 0;
		len = strlen(s);
		
		for (i = 0; i < len; i ++)
		{
			if ( s[i] == '[' ) count ++;
			if ( s[i] == ']' ) count --;
			if ( count < 0)
			{
				printf("[");
				count ++;
			}
		}
		
		printf("%s",s);
		for (i = 0; i < count; i ++) printf("]");
		printf("\n");
	}
	
	return 0;
}
