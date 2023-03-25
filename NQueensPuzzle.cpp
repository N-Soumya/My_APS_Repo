#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,n;
	float f;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n;
	    
	    f = pow(0.143*n,n);
	    
	    if(f-int(f)<0.5)
	    cout << int(f) << endl;
	    
	    else
	    cout << int(f)+1 << endl;
	    
	    
	    
	}
	
	
	return 0;
}
