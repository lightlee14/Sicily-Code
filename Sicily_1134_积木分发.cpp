#include <iostream>
#include <algorithm>

using namespace std;

struct littleChildren
{
	int block_in_hand;
	int block_need;
}child[10005];

bool comp(littleChildren a, littleChildren b) { return a.block_need < b.block_need; }

bool all_can_take_photo(littleChildren * child, int block_in_hand, int count_of_children)
{
	int i;
	for ( i = 0; i < count_of_children; i ++)
	{
		if ( block_in_hand < child[i].block_need ) return false;
		block_in_hand += child[i].block_in_hand;
	}
	return true;
}

int main()
{
	int n, s, i;
	
	while ( cin >> n >> s && n )
	{
		for ( i = 0; i < n; i ++ ) cin >> child[i].block_in_hand >> child[i].block_need;
		
		sort(child, child + n, comp);
		if ( all_can_take_photo(child, s, n) ) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}
