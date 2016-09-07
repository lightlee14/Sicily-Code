#include <iostream>
#include <math.h>
#include <iomanip>
#define PI 3.141592653589793

using namespace std;

class Geometry
{
	public:
		Geometry(double);
		Geometry(double , double);
		double area(void);
		double circumference(void);
		double diagonal(void);
	private:
		double m1,m2;
};

Geometry :: Geometry(double m)
{
	m1 = m;
	m2 = 0;
}

Geometry :: Geometry(double m,double n)
{
	m1 = m;
	m2 = n;
}

double Geometry :: area(void)
{
	if (m2 == 0) return PI * m1 * m1;
	return m1 * m2;
}

double Geometry :: circumference(void)
{
	if (m2 == 0) return PI * m1 * 2;
	return 2 * (m1 + m2);
}

double Geometry :: diagonal(void)
{
	return sqrt(m1 * m1 + m2 * m2);
}

int main()
{
	int n;
	double r;
	
	cin >> n;
	while (n--)
	{
		cin >> r;
		Geometry c1(r);
		cout << fixed << setprecision(4) << c1.area() << ' ' << fixed << setprecision(4) << c1.circumference() <<endl;
		Geometry s(2*r,2*r);
		cout << fixed << setprecision(4) << s.area() << ' ' << fixed << setprecision(4) << s.circumference() << \
		 ' ' << fixed << setprecision(4) << s.diagonal() <<endl;
		Geometry c2(s.diagonal() / 2);
		cout << fixed << setprecision(4) << c2.area() << ' ' << fixed << setprecision(4) << c2.circumference() <<endl;
		cout << fixed << setprecision(4) << (s.diagonal() / 2) * (s.diagonal() / 2) * sqrt (9*3) << \
		 ' ' << fixed << setprecision(4) << (s.diagonal() / 2) * sqrt (36*3) <<endl;
	}
	
	return 0;
}
