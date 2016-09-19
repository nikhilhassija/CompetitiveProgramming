#include <bits/stdc++.h>
 
using namespace std;
 
void shuffle(int *, int);
 
int main()
{
	int n,p;
	cin >> n >> p;
 
	int A[n-1];
	for(int i=1;i<n;i++)
		A[i-1] = i;
 
 	int x = rand() % 1000;
	for(int i=0;i<x;i++)
		shuffle(A,n-1);

	sort(A,A+p-1);
 
	for(int i=1;i<p;i++)
		printf("%d ",A[i-1]);
	printf("\n");
		
	int y = rand() % 1000;
	for(int i=0;i<y;i++)
		shuffle(A,n-1);

	sort(A,A+p-1);
 
	for(int i=1;i<p;i++)
		printf("%d ",A[i-1]);
	printf("\n");
}
 
void shuffle(int * A, int n)
{
	srand(time(NULL));
 
	for(int i=1;i<n;i++)
	{
		int j = rand() % i;
		swap(A[i],A[j]);
	}
} 