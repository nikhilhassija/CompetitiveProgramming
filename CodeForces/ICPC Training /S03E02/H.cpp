#include <bits/stdc++.h>

using namespace std;

int main()
{
	int k;
	cin >> k;

	vector <int> A[k];
	memset(A,0,sizeof(A));

	string S;
	cin >> S;

	for(int i=0;i<S.size();i++)
		if(S[i]-'0')
			A[(i+1)%k].push_back(i+1);

	for(int i=0;i<k;i++)
		if(A[i].size() && A[(i+1)%k].size())
		{
			int a = *min_element(A[i].begin(),A[i].end());;
			int b = *max_element(A[(i+1)%k].begin(),A[(i+1)%k].end());;

			if(b > a)
			{
				printf("%d %d\n",a,b);
				return 0;
			}
		}

	printf("0 0\n");
}