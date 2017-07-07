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
	int d;
	cin >> d;

	int n, m;
	cin >> n >> m;

	vector < int [4] > A(n);
	for(int i=0; i<d; i++)
		cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3];

	for(int i=0; i<d; i++)
	{
		for(int j=0; j<4; j++)
			cerr << A[i][j] << " ";
		cerr << endl;
	}

	vector <int> L, R, T, B;

	for(int i=0; i<d; i++)
	{
		L.pb(min(A[i][0], A[i][2]));
		R.pb(max(A[i][0], A[i][2]));

		B.pb(min(A[i][1], A[i][3]));
		T.pb(max(A[i][1], A[i][3]));
	}

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	sort(B.begin(), B.end());
	sort(T.begin(), T.end());
 
	for(int i=0; i<d; i++)
		cerr << L[i] << " ";
	cout << endl;

	for(int i=0; i<d; i++)
		cerr << R[i] << " ";
	cout << endl;
	
	for(int i=0; i<d; i++)
		cerr << T[i] << " ";
	cout << endl;
	
	for(int i=0; i<d; i++)
		cerr << B[i] << " ";
	cout << endl;
	

	int l, r, t, b;
	cin >> l >> r >> t >> b;

	// l++;
	// r++;
	// t++;
	// b++;

	for(int i=0; i<d; i++)
	{
		int cl = lower_bound(
				L.begin(), 
				L.end(), 
				max(A[i][0], A[i][2])) - L.begin();

		int cr = upper_bound(
				R.begin(),
				R.end(),
				min(A[i][0], A[i][2])) - R.begin();

		cr = d - cr;

		int ct = upper_bound(
				T.begin(),
				T.end(),
				min(A[i][1], A[i][3])) - T.begin();

		// ct = d - ct;

		int cb = lower_bound(
				B.begin(),
				B.end(),
				max(A[i][1], A[i][3])) - B.begin();


		cerr << cl << " " << cr << " " << ct << " " << cb << endl;

		if(cl == l and cr == r and ct == t and cb == b)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return (0-0);	
}