#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	while(n--)
	{
		string S;
		cin>>S;

		for(int i=0;i<S.size();i++)
		{
			S[i] = toupper(S[i]);

			switch(S[i])
			{
				case 'A':
				case 'B':
				case 'C': S[i] = 1; break;
				case 'D':
				case 'E':
				case 'F': S[i] = 2; break;
				case 'G':
				case 'H':
				case 'I': S[i] = 3; break;
				case 'J':
				case 'K':
				case 'L': S[i] = 4; break;
				case 'M':
				case 'N':
				case 'O': S[i] = 6; break;
				case 'P':
				case 'Q':
				case 'R':
				case 'S': S[i] = 7; break;
				case 'T':
				case 'U':
				case 'V': S[i] = 8; break;
				case 'W':
				case 'X':
				case 'Y':
				case 'Z': S[i] = 9; break;
			}

			S[i] += '0';
		}
		string A = S;
		reverse(A.begin(),A.end());

		if(A == S)
			printf("YES\n");
		else
			printf("NO\n");
	}
}