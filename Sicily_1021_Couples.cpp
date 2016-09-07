#include<stdio.h>

int a[200005];
int main()
{
    int i,j,x,y,n,m;
    while (scanf("%d",&n) && n!=0)
    {
        m=1;
        for (i=0;i<200005;i++) a[i]=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            a[x]=i+1;
            a[y]=i+1;
            if (x==y-1)
            {
                a[x]=0;
                a[y]=0;
                while (x>=0 && y<200005)
                {
                    if (a[x]==0) x--;
                    if (a[y]==0) y++;
                    if (a[x]==a[y] && a[x]!=0)
                    {
                        a[x]=0;
                        a[y]=0;
                    }
                    if (a[x]!=a[y] && a[x]!=0 && a[y]!=0) break;
                }
            }
        }
        
        for (i=0;i<200005;i++) if (a[i])
        {
            printf("No\n");
            m=0;
            break;
        }
        if (m) printf("Yes\n");
    }
    
    return 0;
}
