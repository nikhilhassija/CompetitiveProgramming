#include <bits/stdc++.h>

using namespace std;

int main()
{
	int f;
	cin >> f;

	string S;
	cin >> S;

	for(int i=0;i<5;i++)
		S[i] -= '0';

	int h = S[0]*10 + S[1];
	int m = S[3]*10 + S[4];

	if(f == 24)
	{
		if(h > 23)
			h = 10 + h%10;
	}
	else
	{
		if(h == 0)
		{
			h = 1;
		}
		else if(h > 12)
		{
			if(h % 10)
				h = h%10;
			else
				h = 10;
		}
	}

	if(m > 59)
		m = 10 + m%10;

	printf("%d%d:%d%d\n",h/10,h%10,m/10,m%10);
}