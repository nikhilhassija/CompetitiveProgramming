#include <bits/stdc++.h>

using namespace std;

const int MAX_H = 1e7 + 5;
int H[MAX_H];

int main()
{
	memset(H,0,sizeof(H));
	H[0] = 3;

	int n[3];
	for(int i=0;i<3;i++)
		cin>>n[i];

	vector < vector <int> > A;
	A.resize(3);

	for(int i=0;i<3;i++)
	{
		A[i].resize(n[i]);
		for(int j=0;j<n[i];j++)
			cin>>A[i][j];

		reverse(A[i].begin(),A[i].end());

		int sum = 0;
		for(int j=0;j<n[i];j++)
		{
			sum += A[i][j];
			H[sum]++;
		}
	}

	for(int i=MAX_H-1;i>=0;i--)
		if(H[i] == 3)
		{
			printf("%d\n",i);
			break;
		}
}