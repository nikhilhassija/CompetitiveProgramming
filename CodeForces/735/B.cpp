#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli n, n1, n2;
	cin >> n >> n1 >> n2;

	lli A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	sort(A, A+n);
	reverse(A, A+n);

	if(n1 > n2)
		swap(n1,n2);

	lli sumn1 = 0;
	lli sumn2 = 0;
	for(int i=0;i<n1;i++)
		sumn1 += A[i];

	for(int i=0;i<n2;i++)
		sumn2 += A[i+n1];

	double avgn1 = sumn1;
	avgn1 /= n1;

	double avgn2 = sumn2;
	avgn2 /= n2;

	double ans = avgn1 + avgn2;

	printf("%.9f\n", ans);
}