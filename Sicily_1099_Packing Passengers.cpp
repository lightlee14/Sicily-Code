#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	ll tot, count = 0;

	while (scanf("%lld", &tot) != EOF && tot)
	{
		ll a, b, c, d, x, y;
		bool has = true;
		bool flag = false;

		scanf("%lld%lld%lld%lld", &a, &c, &b, &d);
		if (c == 0 || d == 0)
		{
			if (d == 0 && c == 0) has = false;
			else if (d == 0 && c != 0)
			{
				if (tot % c) has = false;
				else x = tot / c;
			}
			else if (c == 0 && d != 0)
			{
				if (tot % d) has = false;
				else y = tot / d;
			}
		}
		else
		{
			if (a*d <= b*c)
			{
				swap(a, b);
				swap(c, d);
				flag = true;
			}
			if (a*d == b*c) y = tot / d;
			else y = min(tot / d, a*tot/(a*d-c*b));
			x = (tot - y*d) / c;
			while (x*c + y*d != tot && y > 0)
			{
				--y;
				x = (tot - y*d) / c;
			}
			if (y == 0 && x*c + y*d != tot) has = false;
		}

		count ++;
		printf("Data set %lld: ", count);
		if (!has) printf("cannot be flown\n");
		else
		{
			if (flag) printf("%lld aircraft A, %lld aircraft B\n", y, x);
			else printf("%lld aircraft A, %lld aircraft B\n", x, y);
		}
	}

	return 0;
}