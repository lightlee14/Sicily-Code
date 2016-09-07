#include <iostream>
#include <cstring>

using namespace std;

char s[1015];
int ans[1018];

int main()
{
    int i, j, len;
    
    cin >> s;
    for ( i = 0; i < 1008; i ++) ans[i] = 0;
    
    len = strlen(s);
    j = 4;
    for ( i = len - 1; i >= 0; i --) ans[j ++ ] = s[i] - '0';//左移4位
    
    j = 0;
    for ( i = len - 1; i >= 0; i --) ans[j ++ ] += s[i] - '0';//加原来的数字 
    
    for ( i = 0; i < 1008; i ++) if ( ans[i] > 1 )
    {
        ans[i + 1] += ans[i] / 2;
        ans[i] %= 2;
    }
    
    //输出 
    while ( ans[i] == 0 && i > 0 ) i --;
    while ( i >= 0 ) cout << ans[i--];
    cout << endl;
    
    return 0;
}
