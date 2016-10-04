#include <bits/stdc++.h>

using namespace std;

string bitstring(int);

string better(string, string, string);
int bin(string);

int main()
{
	int n;
	cin >> n;

	vector <int> Y(n);
	for(int i=0;i<n;i++)
		cin >> Y[i];

	sort(Y.begin(),Y.end(),greater <int>());

	vector <string> A(n);
	for(int i=0;i<n;i++)
		A[i] = bitstring(Y[i]);


	string S,sub;
	map <string, string> M;

	for(int i=0;i<n;i++)
	{	
		S = A[i];
		
		cout << i << " -> " << S << " | " << bin(S) << endl;

		int r = 1;

		while(M.find(S.substr(0,r)) != M.end())
		{	
			cout << S << "r" << r << endl;

			if(S == better(S.substr(0,r),S,M[S.substr(0,r)]))
			{
				string temp = M[S.substr(0,r)];
				

				cout << "temp" << bin(temp) << endl;

				M[S.substr(0,r)] = S;
				
				r -= max(0,int(S.size() - temp.size()));
				
				S = temp;
			}

			r++;
		}

		cout << S << " | " << S.substr(0,r) << endl;
		M[S.substr(0,r)] = S;
	}

	for(auto it=M.begin();it != M.end();it++)
		cout << bin(it->first) << ' ';
	cout << '\n';
}


string bitstring(int x)
{
	string S = "";

	if(!x)
		return "0";

	while(x)
	{
		S.push_back((x%2) + '0');
		x /= 2;
	}

	reverse(S.begin(),S.end());

	return S;
}

string better(string pos, string a, string b)
{
	if(pos.size() == a.size())
		return a;

	if(a.size() > b.size())
		return a;

	if(b.size() > a.size())
		return b;

	if(a.size() == b.size())
	{
		for(int i=0;i<a.size();i++)
		{
			if(a[i] != b[i])
			{
				if(a[i] > b[i])
					return a;
				else
					return b;
			}
		}
	}
}

int bin(string S)
{
	int x = 0;
	for(int i=0;i<S.size();i++)
		x = x*2 + S[i] - '0';

	return x;
}