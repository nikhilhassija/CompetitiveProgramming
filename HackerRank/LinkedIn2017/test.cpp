#include <bits/stdc++.h>

using namespace std;

void socialGraphs(vector < int > counts) 
{
	int n = counts.size();

	int has_group[n];
	memset(has_group, 0, sizeof(has_group));

	vector < vector < int > > A(n + 1);

	for (int i = 0; i < n; i++)
		A[counts[i]].push_back(i);

	int num_groups = 0;

	vector < vector < int> > G(n);

	vector < int > L(A.size(), 0);

	for (int i = 0; i < n; i++)
	{
		if (not has_group[i])
		{
			has_group[i] = 1;

			G[num_groups].push_back(i);

			int c = counts[i];

			for (; L[c] < A.size() and G[num_groups].size() < c; L[c]++)
			{
				int x = A[c][L[c]];

				if (not has_group[x])
				{
					has_group[x] = 1;
					G[num_groups].push_back(x);
				}
			}

			num_groups++;
		}
	}

	for (int i = 0; i < num_groups; i++)
	{
		for (int x : G[i])
			cout << x << " ";
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;

	vector < int > A;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		A.push_back(x);
	}

	socialGraphs(A);

	return 0;
}