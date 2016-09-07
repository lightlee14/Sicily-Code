#include <iostream>

using namespace std;

class sortAlgorithm
{
	public:
		virtual void sort(int p[], int sz) = 0 ;
		~sortAlgorithm() { }
};

class sortArray
{
	public:
		sortArray(int [], int);
		~sortArray();
		void setParam(int [], int);
		void setAlgorithm(sortAlgorithm *);
		void sortIt();
	private:
		int *p;
		int size;
		sortAlgorithm *sa;
		friend ostream& operator<<(ostream&, sortArray&);
};

class simpleSelection : public sortAlgorithm
{
	public:
		void sort(int p[], int sz)
		{
			for (int i = 0; i < sz - 1; i ++)
			{
				int minj = i, min = p[i];
				
				for (int j = i + 1; j < sz; j ++)
				{
					if ( min > p[j] )
					{
						minj = j;
						min = p[j];
					}
				}
				
				p[minj] = p[i];
				p[i] = min;
			}
		}
};

class bubleSort : public sortAlgorithm
{
	public:
		void sort(int p[], int sz)
		{
			for (int i = 0; i < sz - 1; i ++)
			for (int j = i + 1; j < sz; j ++) if ( p[i] > p[j] )
			{
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
};

sortArray :: sortArray(int a[], int sz)
{
	size = sz;
	p = new int[sz];
	
	for ( int i = 0; i < sz; i ++) p[i] = a[i];
}

sortArray :: ~sortArray()
{
	delete []p;
}

void sortArray::setParam(int a[], int sz)
{
	size = sz;
	delete []p;
	p = new int[sz];
	
	for ( int i = 0; i < sz; i ++) p[i] = a[i];
}

void sortArray :: setAlgorithm(sortAlgorithm * al)
{
	sa = al;
}

void sortArray :: sortIt()
{
	sa->sort(p,size);
}

ostream& operator<<(ostream& output, sortArray& arr)
{
	int i;
	
	for (i = 0; i < arr.size - 1; i ++) output << arr.p[i] << ' ';
	output << arr.p[i] << endl;
	
	return output;
}
 
int main()
{
	int A[ ] = {12, 2, 33,12, 64, 9, 90, 1, 23, 11};
	sortArray sarray(A, 10);
	sortAlgorithm *pa;
	
	pa = new simpleSelection;
	sarray.setAlgorithm(pa);
	cout << sarray;
	sarray.sortIt();
	cout << sarray;
	delete pa;
   
    int B[ ] = {98, 999, 121, 32, 893, 112, 64, 99, 190, 11, 123, 111};
    sarray.setParam(B, 12);
    pa = new bubleSort;
    sarray.setAlgorithm(pa);
    cout << sarray;
    sarray.sortIt();
    cout << sarray;
    delete pa;
   
    return 0;
}
