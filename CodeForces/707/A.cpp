#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	n *= m;

	char c;
	int bw = 1;
	for(int i=0;i<n && bw;i++)
	{
		cin>>c;

		switch(c)
		{
			case 'C':
			case 'M':
			case 'Y': bw = 0; break; 
		}
	}

	if(bw)
		printf("#Black&White\n");
	else
		printf("#Color\n");
}