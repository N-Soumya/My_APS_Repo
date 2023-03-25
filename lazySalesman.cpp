#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,n,w,i;
	
	cin >> t;
	
	while(t--)
	{
	    
	    int c = 0,sum =0;
	    
	    cin >> n >> w;
	    
	    vector<int> a(n);
	    
	    for(i=0;i<n;i++)
	    {
	        cin >> a[i];
	    }
	    
	    sort(a.begin(),a.end(),greater<int>());
	    
	    for(i=0;i<n;i++)
	    {
	        sum += a[i];
	        c++;
	        
	        if(sum>=w)
	        break;
	        
	        
	    }
	    
	    cout << n-c << endl;
	    
	    
	    
	    
	    
	}
	
	
	return 0;
}
