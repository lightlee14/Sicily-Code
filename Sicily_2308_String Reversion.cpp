#include<iostream>
#include<cstring>

using namespace std;

void reverse(int first, int last, char *s)
{
	char *temp = new char [last - first + 1];
	int i,j = 0;
	
	for (i = first; i <= last; i++) temp[j++] = s[i];
	for (i = first; i <= last; i++) s[i] = temp[--j];
}

char s[10000];

int main()
{
	int t,m,n,i;
	
	cin >> t;
	while (t--)
	{
		cin >> s;
		i = 0;
		m = 0;
		
		while (s[i] != '\0')
		{
			if (s[i] == '_')
			{
				n = i;
				reverse(m,n - 1,s);
				m = n + 1;
			}
			i++;
		}
		n = i;
		reverse(m,n - 1,s);
		
		cout << s << endl;
	}
	
	return 0;
}
