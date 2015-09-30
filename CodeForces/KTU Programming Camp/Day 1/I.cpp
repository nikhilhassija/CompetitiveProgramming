#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	vector <string> A(3);
	cin>>A[0]>>A[1]>>A[2];
	vector <string> S(6);
	S[0].resize(A[0].size()+1,0);
	for(i=A[0].size()-1;i>=0;i--)
	{
		S[i] += 2*(A[i]-'0');
	}
	return 0;
}