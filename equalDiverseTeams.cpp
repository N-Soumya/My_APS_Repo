#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int temp;
		map<int,int> s;
		int extra=0;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			s[temp]++;
			if(s[temp]==2)
				extra++;
		}
		if(s.size()>2*k)
			cout<<"NO"<<endl;
		else if(s.size()==2*k)
			cout<<"YES"<<endl;
		else if(s.size()==k && extra==k)
			cout<<"YES"<<endl;
		else if(s.size()-k<k && s.size()+extra>=2*k)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
    return 0;
}
