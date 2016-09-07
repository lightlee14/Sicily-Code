#include<stdio.h>
#include<string.h>

char st[5005];
int arr[5005];

int main()
{
    int i,len;
    
    while (scanf("%s",st)!=EOF && st[0]!='0')
    {
        len=strlen(st);
        for (i=0;i<len;i++) arr[i]=0;
        arr[0]=arr[1]=1;
        
        for (i=1;i<len;i++) //DP
        {
            if (st[i]=='0') arr[i+1]=arr[i-1];  //判断类似于1101的特殊情况 
            else if (st[i-1]<'2' && st[i-1]>'0') arr[i+1]=arr[i]+arr[i-1];
            else if (st[i-1]=='2' && st[i]<='6') arr[i+1]=arr[i]+arr[i-1];
            else arr[i+1]=arr[i];
        }
        printf("%d\n",arr[len]);
    }
    
    return 0;
}
