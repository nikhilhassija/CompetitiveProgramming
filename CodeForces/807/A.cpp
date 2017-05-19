#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

int main()
{
	int n;
	cin >> n;

	int A[n], B[n];

	for(int i=0; i<n; i++)
		cin >> A[i] >> B[i];

	int ans = 0;

	for(int i=0; i<n; i++)
		ans += (A[i] != B[i]);

	if(ans)
		printf("rated\n");
	else
	{
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				ans += (A[i] < A[j]);

		if(ans)
			printf("unrated\n");
		else
			printf("maybe\n");
	}

	return (0-0);	
}