#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct dancer
{
	int height;
	bool has_partner; 
};

dancer boys[1005], girls[1005];

bool comp(dancer a, dancer b) { return abs(a.height) > abs(b.height); }

bool find_partner(dancer &boy, int number_of_dancer)
{
	int max = -9999 , maxi = -1 , i;
	
	for ( i = 0; i < number_of_dancer; i ++)
	{
		if ( ! girls[i].has_partner )
		{
			int temp = girls[i].height + boy.height;
			if ( temp < 0 && temp > max  && girls[i].height * boy.height < 0) //������Ҳ����Ƕ��� 
			{
				max = temp;
				maxi = i;
			}
		}
	}
	
	//�ҵ����ʵ� 
	if ( maxi != -1 )
	{
		girls[maxi].has_partner = true;
		boy.has_partner = true;
		return true;
	}
	
	return false;
}

int main()
{
	int t, n, i, count;
	
	cin >> t;
	while ( t -- )
	{
		count = 0;
		cin >> n;
		
		for ( i = 0; i < n; i ++ )
		{
			cin >> boys[i].height;
			boys[i].has_partner = false;
		}
		
		for ( i = 0; i < n; i ++ )
		{
			cin >> girls[i].height;
			girls[i].has_partner = false;
		}
		
		//����ߵĿ�ʼѡ 
		sort(boys, boys + n, comp);
		
		for ( i = 0; i < n; i ++ ) if ( find_partner(boys[i], n) ) count++;
		
		cout << count << endl;
	}
	
	return 0;
} 
