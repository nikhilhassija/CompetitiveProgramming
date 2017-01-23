#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int A[n];
	for(int &i: A)
		cin >> i;

	set <int> S;

	for(int i: A)
	{
		S.insert(i);
		
		auto it = S.find(i);
		it++;

		if(it != S.end())
			S.erase(it);
	}

	cout << S.size() << endl;
}