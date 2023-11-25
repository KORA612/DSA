#include <iostream>
using namespace std;

void f(int **a,int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<m; j++)
		{
			a[i][j] += (i==j) ? 1 : 0;             // a
			a[i][j] -= (i+j == m-1) ? 1 : 0;       // b
			a[i][j] += (i<j && i+j<=m-2) ? 2 : 0;  // c
			a[i][j] -= (i>j && i+j>=m) ? 2 : 0;    // d
			a[i][j] += (i>j && i+j<=m-2) ? 3 : 0;  // e
			a[i][j] -= (i<j && i+j>=m) ? 3 : 0;    // f
		}
	}
}
void print(int **a,int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<m; j++)
		 cout << a[i][j] << "  ";
		cout << endl;
	}
}

int main()
{
	int n = 5,m=1;
	
	int **A;
	A = new int *[n];
	for(int i=0; i<n; i++)
	 A[i] = new int[n];
	
	for(int i=0; i<n; i++)
	 for(int j=0; j<n; j++)
	  A[i][j] = m++;
	  
	print(A,n);
	
	f(A,n);
	
	print(A,n);
	
	
	for( int i = 0 ; i<n ; i++ )
	 delete [ ] A[i];
	delete [ ] A;
		
	return 0;
}

// NOT TOTALLY ORIGINAL