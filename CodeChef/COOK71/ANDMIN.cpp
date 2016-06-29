#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
int A[MAX_N];
int T[4*MAX_N];
int L[4*MAX_N];

void build(int node, int start, int end);
void updateRange(int node, int start, int end, int l, int r, int val);
int queryRange(int node, int start, int end, int l, int r);

int main()
{
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++)
        cin>>A[i];

    build(1,0,n-1);

    while(q--)
    {
        int qt;
        cin>>qt;

        if(!qt)
        {
            int l,r;
            cin>>l>>r;
            printf("%d\n",queryRange(1,0,n-1,l-1,r-1));
        }
        else
        {
            int l,r,v;
            cin>>l>>r>>v;
            updateRange(1,0,n-1,l-1,r-1,v);
        }
    }
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        T[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        T[node] = min(T[2*node],T[2*node+1]);
    }
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(L[node] != 0)
    { 
        T[node] &= L[node];   
        if(start != end)
        {
            L[node*2] &= L[node];                  

            L[node*2+1] &= L[node];                
        }
        L[node] = 0;                                  
    }
    if(start > end or start > r or end < l)              
        return;
    if(start >= l and end <= r)
    {
        
        T[node] &= val;
        if(start != end)
        {
            L[node*2] &= val;
            L[node*2+1] &= val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   
    T[node] = min(T[node*2],T[node*2+1]);        
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         
    if(L[node] != 0)
    {
        T[node] &= L[node];            
        if(start != end)
        {
            L[node*2] &= L[node];         
            L[node*2+1] &= L[node];    
        }
        L[node] = 0;                 
    }
    if(start >= l and end <= r)             
        return T[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); 
    return min(p1,p2);
}