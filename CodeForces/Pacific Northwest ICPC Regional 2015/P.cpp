#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;

	vector <int> A(26,0);
	for(int i=0;i<S.size();i++)
		A[S[i]-'a']++;

	sort(A.rbegin(),A.rend());

	int k = 0;
	while(!A[k])
		k++;
	A.push_back(0);
	A.push_back(0);

	int ans = A[k] + A[k+1];
	ans = S.size() - ans;

	cout<<ans<<endl;
}