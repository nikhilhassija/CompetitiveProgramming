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

int swapUD = 0;
int swapLR = 0;

void go(char);
void figure();

int n, m;
int fx, fy;

int main()
{
	cin >> n >> m;

	string S[n];
	for(int i=0; i<n; i++)
		cin >> S[i];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(S[i][j] == 'F')
			{
				fx = i;
				fy = j;
				break;
			}
		}
	}

	figure();

	int V[n][m];
	mset(V);

	queue <pair <pii, string> > Q;

	Q.push({{0,0}, ""});
	V[0][0] = 1;

	while(!Q.empty())
	{
		auto p = Q.front();
		Q.pop();

		int x, y;
		tie(x, y) = p.first;
		string cur = p.second;

		if(x == fx and y == fy)
		{
			cout << fx << " " << fy << endl;
			cout << cur << endl;
			for(int i=0; i<cur.size(); i++)
			{
				go(cur[i]);
				cin >> x >> y;
			}

			return 0;
		}

		if(x and (not V[x-1][y]) and (S[x-1][y] != '*'))
		{
			V[x-1][y] = 1;
			Q.push({{x-1, y}, cur + "U"});
		}

		if(x != n-1 and (not V[x+1][y]) and (S[x+1][y] != '*'))
		{
			V[x+1][y] = 1;
			Q.push({{x+1,y}, cur + "D"});
		}

		if(y and (not V[x][y-1]) and (S[x][y-1] != '*'))
		{
			V[x][y-1] = 1;
			Q.push({{x, y-1}, cur + "L"});
		}

		if((y != m-1) and (not V[x][y+1]) and (S[x][y+1] != '*'))
		{
			V[x][y+1] = 1;
			Q.push({{x, y+1}, cur + "R"});
		}
	}

	return (0-0);	
}

void figure()
{
	go('R');
	int x, y;
	cin >> x >> y;

	// cout << fx << " " << fy << endl;
	// cout << x << 
	if((fx+1) == x and (fy+1) == y)
	{
		exit(0);
	}

	if(y == 1)
	{
		swapLR = 1;
	}
	else
	{
		if(y != -1)
			go('L');
		if(y == -1)
			exit(0);
	}


	go('D');
	cin >> x >> y;

	if((fx+1) == x and (fy+1) == y)
	{
		exit(0);
	}

	if(x == 1)
	{
		swapUD = 1;
	}
	else
	{
		if(x != -1)
			go('U');
		if(x == -1)
			exit(0);
	}
}

void go(char x)
{
	switch(x)
	{
		case 'L': cout << ((swapLR)?'R':'L') << endl; break; 
		case 'R': cout << ((swapLR)?'L':'R') << endl; break; 
		case 'U': cout << ((swapUD)?'D':'U') << endl; break; 
		case 'D': cout << ((swapUD)?'U':'D') << endl; break; 
	}

	fflush(stdout);
}