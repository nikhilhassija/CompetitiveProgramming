#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w,h,b;
	cin>>w>>h>>b;

	int A[h+2][w+2];
	int B[h+2][w+2];
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>A[i][j];

	for(int i=0;i<h+2;i++)
	{
		A[i][0]   = A[i][w];
		A[i][w+1] = A[i][1];
	}

	for(int i=0;i<w+2;i++)
	{
		A[0][i]   = A[h][i];
		A[h+1][i] = A[1][i];
	}

	while(b--)
	{
		int C[] = {-1,0,1};

		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				int sum = 0;

				for(int a=0;a<3;a++)
					for(int b=0;b<3;b++)
						sum += A[i+C[a]][j+C[b]];

				B[i][j] = sum;
			}
		}

		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				A[i][j] = B[i][j];

		for(int i=0;i<h+2;i++)
		{
			A[i][0]   = A[i][w];
			A[i][w+1] = A[i][1];
		}

		for(int i=0;i<w+2;i++)
		{
			A[0][i]   = A[h][i];
			A[h+1][i] = A[1][i];
		}
	}

	unordered_set <int> S;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			S.insert(A[i][j]);

	cout<<S.size()<<endl;
}