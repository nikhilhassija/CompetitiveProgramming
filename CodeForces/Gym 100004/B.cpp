#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string S;
		cin >> S;
		
		int angle = 0;

		S.push_back(S[0]);

		for(int i=1;i<S.size();i++)
		{
			if(S[i-1] == 'a')
			{
				switch(S[i])
				{
					case 'a': angle -= 360; break;
					case 'b': angle += 45; break;
					case 'c': angle -= 45; break;
				}
			}

			if(S[i-1] == 'b')
			{
				switch(S[i])
				{
					case 'a': angle += 45; break;
					case 'b': angle -= 360; break;
					case 'c': angle -= 45; break;
				}
			}

			if(S[i-1] == 'c')
			{
				switch(S[i])
				{
					case 'a': angle += 45; break;
					case 'b': angle -= 45; break;
					case 'c': angle -= 360; break;
				}
			}

		}

		while(angle < 0)
			angle += 360;

		if(angle %360)
			printf("open\n");
		else
			printf("closed\n");
	}
}