#include <stdio.h>

int binary[85];

int main()
{
    int t, n, i, j, temp;
    long long ans;
    
    scanf("%d", &t);
    while ( t -- )
    {
        scanf("%d", &n);
        for ( i = 0; i < 85; i ++ ) binary[i] = 0;
        
        for ( i = 0; i < n; i ++ )
		{
			scanf("%d",&temp);
			
			//统计各个位数上1和0的个数 
			j = 0;
			while (temp)
			{
				binary[j++] += temp % 2;
				temp >>= 1;
			} 
		}
        
        ans = 0;
        j = 1;
        for ( i = 0; i < 85; i ++ )
        {
        	ans += (long long)binary[i] * ( n - binary[i] ) * j;//注意不加long long的话数据会爆的
        	j *= 2;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
