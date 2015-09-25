#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string S;
	int x,y,k;
	while(1)
	{
		deque <int> X;
		deque <int> Y;
		X.clear();
		Y.clear();
		while(1)
		{
			cin>>S;
			if(S=="0")
				return 0;
			else if(S=="createlist")
			{
				if(X.empty())
				break;
			}
			else if(S=="insertbeg")
			{
				cin>>x>>y;
				X.push_front(x);
				Y.push_front(y);
			}
			else if(S=="insertend")
			{
				cin>>x>>y;
				X.push_back(x);
				Y.push_back(y);
			}
			else if(S=="deletebeg")
			{
				if(X.size())
				{
					X.pop_front();
					Y.pop_front();
				}
			}
			else if(S=="deletelast")
			{
				if(X.size())
				{
					X.pop_back();
					Y.pop_back();
				}
			}
			else if(S=="deletelist")
			{
				X.clear();
				Y.clear();
			}
			else if(S=="printlist")
			{
				cin>>k;
				if(X.empty())
					cout<<"NULL"<<endl;
				else if(k)
				{
					deque<int>::reverse_iterator xit=X.rbegin();
					deque<int>::reverse_iterator yit=Y.rbegin();
					for(;xit!=X.rend() && yit!=Y.rend();xit++,yit++)
						cout<<*xit<<' '<<*yit<<endl;
				}
				else
				{
					deque<int>::iterator xit=X.begin();
					deque<int>::iterator yit=Y.begin();
					for(;xit!=X.end() && yit!=Y.end();xit++,yit++)
						cout<<*xit<<' '<<*yit<<endl;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}