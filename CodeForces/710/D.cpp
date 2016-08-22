#include <bits/stdc++.h>

#define lli long long int

using namespace std;

void EE(lli, lli, lli *, lli *);
lli numterms(lli, lli, lli);

int main()
{
	lli a1,b1,a2,b2,l,r;
	cin>>a1>>b1>>a2>>b2>>l>>r;

	lli a = a1;
	lli b = -a2;
	b = b + ((-b)/a)*a;

	while(b<0)
		b += a;

	lli d = b2 - b1;

	lli g = __gcd(a,b);

	if(d % g)
		printf("0\n");
	else
	{
		lli x,y;

		EE(min(a,b),max(a,b),&x,&y);

		x++;
		y++;
		x *= d/g;
		y *= d/g;

		lli ia = (a1*a2)/g;
		lli id = (a1*x + b1)%ia;

		lli L,R;

		if(l<0)
			L = -numterms(ia,-id,-l);
		else
			L = numterms(ia,id,l);

		if(r<0)
			R = numterms(ia,-id,-r);
		else
			R = numterms(ia,id,r);
		
		printf("L-%lld R-%lld\n",L,R);
		lli ans = max(0ll,R-L);
		printf("%lld\n",ans);
	}
}

void EE(lli a, lli b, lli *x, lli *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return;
    }
 
    lli x1, y1;
    EE(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
}

lli numterms(lli a, lli d, lli x)
{
	return (x-d-1)/a;
}