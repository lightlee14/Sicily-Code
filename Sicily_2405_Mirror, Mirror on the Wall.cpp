#include<stdio.h>
#include<string.h>

int f(char c)
{
	if (c == 'b' || c == 'd' || c == 'p' || c == 'q')
	 return 1;
	
	if (c == 'i' || c == 'o' || c == 'v' || c == 'x' || c == 'w')
	 return 2;
	
	return 0;
}

bool is_invalid(char *s)
{
	int i,len = strlen(s);
	
	for (i = 0; i < len; i++)
	 if (f(s[i]) == 0) return true;
	
	return false;
}

void print(char c)
{
	if (c == 'b') printf("d");
	if (c == 'd') printf("b");
	if (c == 'p') printf("q");
	if (c == 'q') printf("p");
	
	if (f(c) == 2) printf("%c",c);
}

char s[1000];

int main()
{
	int i,len;
	
	while (scanf("%s",s) != EOF && s[0]!='#')
	{
		if ( is_invalid(s) ) printf("INVALID\n");
		else
		{
			len = strlen(s);
			for (i = len - 1; i >= 0; i--) print(s[i]);
			printf("\n");
		}
	}
	
	return 0;
}
