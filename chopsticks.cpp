#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	
	long int n,d,i,c=0,x;
	
	cin >> n >> d;
	
	vector<int> a;
	
	for(i=0;i<n;i++)
	{
	    cin >> x;
	    a.push_back(x);
	    
	    
	}
	
	
	
	sort(a.begin(),a.end());
	
	for(i=0;i<n-1;i++)
	{
	    if(a[i+1]-a[i]<=d)
	    {
	        c++;
	        i++;
	    }
	    
	    
	}
	
	cout << c << endl;
	
	
	return 0;
}
