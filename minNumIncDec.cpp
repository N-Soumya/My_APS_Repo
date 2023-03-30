#include <bits/stdc++.h> 
using namespace std; 


int Get_Minimum_Opr(vector<int> &a, int n) 
{ 

 
    int s = *min_element(a.begin(), a.end()); 
  
    
    int l = *max_element(a.begin(), a.end()); 
  
    
    int dp[n][l + 1]; 
  
 
    for (int j = s; j <= l; j++) { 
        dp[0][j] = abs(a[0] - j); 
    } 
  
  
    
    for (int i = 1; i < n; i++) { 
        int minimum = INT_MAX; 
        for (int j = s; j <= l; j++) { 
        
        
            minimum = min(minimum, dp[i - 1][j]); 
            dp[i][j] = minimum + abs(a[i] - j); 
        } 
    } 
  

    
    int ans = INT_MAX; 
    for (int j = s; j <= l; j++) { 
        ans = min(ans, dp[n - 1][j]); 
    } 
    
   
    return ans; 
} 


int main() 
{ 
    vector<int> arr ;
  	int n,a;
    cout<<"Enter the total number of elements in the array"<<endl;
  	cin>>n;
    for(int i=0;i<n;i++)
    {
            cout<<"Enter the element"<<endl;
            cin>>a;
            arr.push_back(a);
    } 
    cout << Get_Minimum_Opr(arr,n); 
    return 0; 
} 
