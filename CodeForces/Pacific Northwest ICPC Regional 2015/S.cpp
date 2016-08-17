#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

const lli max_t = 2e6 + 6;

struct wave
{
	lli m,f,w;
};

bool comp(wave a, wave b)
{
	return a.m < b.m;
}

vector <wave> W;
lli F[max_t];

int main()
{
	lli n;
	cin>>n;

	W.resize(n);

	for(lli i=0;i<n;i++)
		cin>>W[i].m>>W[i].f>>W[i].w;

	sort(W.begin(),W.end(),comp);

	memset(F,0,sizeof(F));

	F[0] = 0;
	lli w = 0;
	for(lli i=1;i<max_t;i++)
	{
		F[i] = max(F[i],F[i-1]);

		while(i == W[w].m)
		{
			F[i+W[w].w] = F[i] + W[w].f;
			w++;
		}
	}

	lli ans = F[max_t-1];
	for(lli i=0;i<max_t;i++)
		ans = max(ans,F[i]);

	printf("%lld\n",ans);
}	