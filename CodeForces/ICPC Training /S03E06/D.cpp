#include <bits/stdc++.h>

using namespace std;

int good(int, int);
int check(int, int, int, int, int, int, int, int);

int main()
{
	string P[4];

	for(int i=0;i<4;i++)
		cin >> P[i];

	for(int i=0;i<4;i++)
		cout << P[i] << endl;

	int Ky = P[0][0] - 'a',
		Kx = P[0][1] - '0',
		by = P[1][0] - 'a',
		bx = P[1][1] - '0',
		ky = P[2][0] - 'a',
		kx = P[2][1] - '0',
		ey = P[3][0] - 'a',
		ex = P[3][1] - '0';
		

	printf(":: %d %d %d %d %d %d %d %d\n",Ky,Kx,bx,by,kx,ky,ex,ey);
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			if((i || j) && check(bx,by,kx,ky,Kx+i,Ky+j,ex,ey))
				printf("K%c%d\n",P[0][0]+i,P[0][1]+j);

	for(int i=-8;i<8;i++)
	{
		if(i && check(bx+i,by+i,kx,ky,Kx,Ky,ex,ey))
			printf("B%c%d\n",P[1][0]+i,P[1][1]+i);

		if(i && check(bx+i,by-i,kx,ky,Kx,Ky,ex,ey))
			printf("B%c%d\n",P[1][0]+i,P[1][1]-i);
	}

	int A[] = {-2,-1,1,2};
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(abs(A[i]) != abs(A[j]))
				if(check(bx,by,kx+A[i],ky+A[j],Kx,Ky,ex,ey))
					printf("N%c%d\n",P[2][0]+A[i],P[2][1]+A[j]);

	printf("impossible\n");
}

int check(
	int bx, int by,
	int kx, int ky,
	int Kx, int Ky,
	int ex, int ey)
{
	printf("x %d %d %d %d %d %d %d %d\n\n",Ky,Kx,bx,by,kx,ky,ex,ey);

	bx += 2; by += 2;
	kx += 2; ky += 2;
	Kx += 2; Ky += 2;
	ex += 2; ey += 2;

	if(!good(bx, by))
		return 0;
	if(!good(kx, ky))
		return 0;
	if(!good(Kx, Ky))
		return 0;
	if(!good(ex, ey))
		return 0;

	int B[12][12];
	memset(B,0,sizeof(B));

	for(int i=0;i<12;i++)
	{
		B[i][0] = B[i][1] = B[i][10] = B[i][11] = 1;
		B[0][i] = B[1][i] = B[10][i] = B[11][i] = 1;
	}

	B[ex][ey] = 1;

	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			if(i || j)
				B[Kx+i][Ky+j] = 1;

	for(int i=-8;i<=8;i++)
	{
		if(i)
		{
			if(good(bx+i,by+i))
				B[bx+i][by+i] = 1;
				
			if(good(bx+i,by-i))
				B[bx+i][by-i] = 1;
		}
	}

	int A[4] = {-2,-1,1,2};

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(abs(A[i]) != abs(A[j]))
				B[kx+A[i]][ky+A[j]] = 1;

	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(i == bx && j == by)
				cout << 'b';
			else if(i == kx && j == ky)
				cout << 'k';
			else if(i == Kx && j == Ky)
				cout << 'Q';
			else if(i == ex && j == ey)
				cout << 'e';
			else
				cout << B[i][j];

			cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			if(B[ex + i][ey + j] == 0)
				return 0;

	return 1;
}

int good(int x, int y)
{	
	if(x < 2 || x > 9)
		return 0;

	if(y < 2 || y > 9)
		return 0;

	return 1;
}