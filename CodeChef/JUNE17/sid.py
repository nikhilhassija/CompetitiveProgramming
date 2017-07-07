from decimal import *
getcontext().prec=8001
e,fact=Decimal(0),Decimal(1)
for i in range(1,750):
    e+=2*i/fact
    fact*=2*i*(2*i+1)
b=e-1
n=int(input())
ans=Decimal(n*(n+1)//2)
factor=1
while(n>0):
    if(b>2):
        diff=b.to_integral_exact(rounding=ROUND_DOWN)-1
        ans+=diff*Decimal(n*(n+1)//2)*factor
        b-=diff
    else:
        newn=((b-1)*n).to_integral_exact(rounding=ROUND_DOWN)
        newb=1/(1-1/b)
        ans+=Decimal((n+newn)*(n+newn+1)//2)*factor
        factor*=-1
        b,n=newb,newn
print(ans)
    