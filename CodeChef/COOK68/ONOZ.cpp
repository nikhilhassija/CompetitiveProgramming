#include <bits/stdc++.h>

using namespace std;

int wz(int x)
{
	if(x%10 == 0)
		x = x/10;

	return x;
}

int match(int h, int m)
{
	vector <int> A;

	A.push_back(h%10);
	A.push_back(m%10);
	if(h>9)
		A.push_back(h/10);

	if(m>9)
		A.push_back(m/10);
	
	int f = 1;
	for(int i=1;i<A.size();i++)
		if(A[i] != A[i-1])
			f = 0;
	return f;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int h,m;

		cin>>h>>m;

		set <int> H;
		for(int i=0;i<h;i++)
			H.insert(wz(i));

		set <int> M;
		for(int i=0;i<m;i++)
			M.insert(wz(i));

		vector <int> A(H.begin(),H.end()); 
		vector <int> B(M.begin(),M.end()); 

		int x = 0;
		for(int i=0;i<A.size();i++)
			for(int j=0;j<B.size();j++)
				if(match(A[i],B[j]))
					x++;

		cout<<x<<endl;
	}
}