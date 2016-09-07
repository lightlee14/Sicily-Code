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
			
			//ͳ�Ƹ���λ����1��0�ĸ��� 
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
        	ans += (long long)binary[i] * ( n - binary[i] ) * j;//ע�ⲻ��long long�Ļ����ݻᱬ��
        	j *= 2;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
