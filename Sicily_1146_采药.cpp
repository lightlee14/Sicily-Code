#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int dp[1055][115];

int main()
{
	int i, j, time, med, ti, vi;
	
	cin >> time >> med;
	memset(dp, 0, sizeof(dp));
	
	for ( i = 1; i <= med; i ++ )
	{
		cin >> ti >> vi;
		for ( j = 1; j <= time; j ++ )
		{
			if ( j >= ti ) dp[j][i] = max(dp[j][i - 1], dp[j-ti][i-1] + vi);
			else dp[j][i] = dp[j][i - 1];
		}
	}
	
	cout << dp[time][med] << endl;
	
	return 0;
}

/*
也可以用滚动数组的形式，是由上面的演变过来的，下一层自动覆盖上一层，因而不用dp[j][i] = dp[j][i - 1]
注意到覆盖的时候小的会对大的有影响，所以从后往前覆盖 

int ans[1050];
int main()
{
    int i, j, time, med, ti, vi;
    
    cin >> time >> med;
    memset(ans, 0, sizeof(ans));
    
    for ( i = 0; i < med; i ++ )
    {
        cin >> ti >> vi;
        for ( j = time; j > 0; j-- ) if ( j >= ti ) ans[j] = max(ans[j], ans[j - ti] + vi);
    }
    
    cout << ans[time] << endl;
*/
