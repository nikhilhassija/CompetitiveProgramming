#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k,ans,a;
    cin>>n>>m;
    ans = 2 * n - m + 1;
    for (int i = 0; i < m; i++)
    {
        cin>>k;
        for (int i = 0; i < k; i++)
        {
            cin>>a;
            if (a == i + 1)
                ans -= 2;
        }
    }
    cout<<ans<<endl;
    return 0;
}