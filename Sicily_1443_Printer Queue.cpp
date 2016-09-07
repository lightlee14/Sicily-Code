#include <iostream>

using namespace std;

struct printwork
{
	int priority;
	bool has_printed;
}q[105];

bool has_higher_priority(printwork a, printwork *p, int n)
{
	int i;
	for ( i = 0; i < n; i ++ ) if ( p[i].priority > a.priority && !p[i].has_printed ) return true;
	return false;
}

int main()
{
	int t;
	
	cin >> t;
	while ( t --)
	{
		int n, myjob, i, first = 0, times = 0;
		
		cin >> n >> myjob;
		for ( i = 0; i < n; i ++ )
		{
			cin >> q[i].priority;
			q[i].has_printed = false;
		}
		
		i = 0;
		while ( ! q[myjob].has_printed )
		{
			if ( has_higher_priority(q[i], q, n) || q[i].has_printed ) i ++;
			else
			{
				q[i].has_printed = true;
				times ++;
				i ++;
			}
			
			if ( i == n ) i = 0;
		}
		
		cout << times << endl; 
	}
	
	return 0;
}
//注意逻辑判断，直接用类指针的形式模拟 
