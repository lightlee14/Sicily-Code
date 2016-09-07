#include<iostream>

using namespace std;

bool equal_amount_of_4_and_7(int n)
{
    int count4 = 0,count7 = 0;
    
    while (n)
    {
        int temp = n % 10;
        n /= 10;
        
        if ( temp != 4 && temp != 7) return false;
        if ( temp == 4 ) count4 ++;
        if ( temp == 7 ) count7 ++;
    }
    
    if ( count4 == count7 ) return true;
    return false;
}

long long ans[100];

int main()
{
    int t, i = 0;
    long long n;
    
    for (n=47;n<=77774444;n++ ) if ( equal_amount_of_4_and_7(n) ) ans[i++] = n;
    ans[i] = 4444477777;
    cin >> t;
    while ( t-- )
    {
    	cin >> n;
    	i = 0;
    	while ( n > ans[i]) i++;
    	cout << ans[i] << endl;
    }
    
    return 0;
}
