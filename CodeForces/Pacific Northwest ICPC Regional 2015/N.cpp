#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	vector <int> S;
	vector <int> B;

	while(n--)
	{
		int x;
		string R;

		cin>>x>>R;
		if(R == "SAFE")
			S.push_back(x);
		else
			B.push_back(x);
	}

	sort(S.begin(),S.end());
	sort(B.begin(),B.end());

	if(S.size() == 0)
		printf("2 ");
	else
		printf("%d ",S[S.size()-1]+1);

	if(B.size() == 0)
		printf("%d\n",k-1);
	else
		printf("%d\n",B[0]-1);
}