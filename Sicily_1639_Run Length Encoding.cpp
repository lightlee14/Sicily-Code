#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in, ans = "";
    
    //getline读入一整行，如果是cin>>in，是不会读入空行的。。这样会PE很多次。。 
    while ( getline(cin,in) )
    {
        int i, j, num = 0;
        
        ans.clear();
        for ( i = 0; i < in.size(); i ++)
        {
            if ( num > 50 ) break;//注意题目有坑。。有11111111111111111111111111A的情况 
			if ( in[i] >= '0' && in[i] <= '9' ) num = num * 10 + in[i] - '0';
            else
            {
                if ( num != 0)
				{
					for ( j = 0; j < num; j ++ ) ans += in[i];
					num = 0;
				}
                else ans += in[i];
            }
        }
        
        if ( num > 50 ) cout << "TOO LONG\n";
        else if ( ans.size() > 50) cout << "TOO LONG\n";
        else cout << ans << endl;
        
    }
    
    return 0;
}
