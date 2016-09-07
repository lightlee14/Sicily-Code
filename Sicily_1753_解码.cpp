#include<stdio.h>
#include<string.h>

void decode(char * s)
{
	int i,j,num,count,len;
	char cur;
	
	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (s[i+1] < '0' || s[i+1] > '9') printf("%c",s[i]);
		else
		{
			count = 0;
			j = i + 1;
			
			while (s[j] >= '0' && s[j] <= '9')
			{
				j++;
				count++;
			}
			
			// get times and change i
			cur = s[i];
			num = 0;
			while (count--)
			{
				num *= 10;
				i++;
				num += s[i] - '0';
			}
			
			for (j = 0; j < num; j++) printf("%c",cur);
		}
	}
	
	printf("\n");
}

char st[10005];
int main()
{
	while (scanf("%s",st) && strcmp(st,"XXX") != 0) decode(st);
	
	return 0;
}
