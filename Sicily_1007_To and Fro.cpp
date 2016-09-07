#include<stdio.h>
#include<cstring>

int n;
char s[205];

void reverse(char s[],int n,int m)
{
    int i,j;
    char s2[205];
    for (i=n;i<m;i++) s2[i]=s[i];
    for (j=n;j<m;j++)
    {
        s[j]=s2[i-1];
        i--;
    }
}

int main()
{
    int i,j,len;
    while (scanf("%d",&n) && n!=0)
    {
        scanf("%s",s);
        len=strlen(s);
        
        for (i=0;i<len/(2*n);i++) reverse(s,n+i*2*n,(1+i)*2*n);  //жьее 
        for (i=0;i<n;i++)
        {
            for (j=0;j<len/n;j++) printf("%c",s[i+j*n]);
        }
        
        printf("\n");
    }
    
    return 0;
}
