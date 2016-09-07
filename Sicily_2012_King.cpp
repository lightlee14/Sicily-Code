#include <stdio.h>
#include <cstring>


bool a_can_beat_b(char beat[][1005], int n, int a, int b)
{
	int i;
	for ( i = 0; i < n; i ++ ) if ( beat[a][i] == '1' )
	{
		if ( beat[i][b] == '1' ) return true;
	}
	return false;
}

bool is_king(char beat[][1005], int len, int num)
{
    int i;
    for ( i = 0; i < len; i ++ )
    {
        if ( beat[num][i] == '0' && i != num )
        {
        	if ( !a_can_beat_b(beat, len, num, i) ) return false;
        }
    }
    return true;
}

void find_king(char beat[][1005], int n)
{
    for ( int i = 0; i < n; i ++ )
    {
        if ( is_king(beat, n, i) )
        {
        	cout << i + 1 << endl;
        	return;
        }
    }
    
    cout << -1 << endl;
    return;
}

char beat[1005][1005];

int main()
{
    int n;
    
    while ( scanf("%d",&n) != EOF )
    {
        int i, j;
        for ( i = 0; i < n; i ++ ) scanf("%s",beat[i]);
        
        find_king(beat, n);
    }
    
    return 0;
}
