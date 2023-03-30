#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int findMinAbsDiff(vector<int> const &S, int n, int S1, int S2)
{
  
    if (n < 0) {
        return abs(S1 - S2);
    }
 
    int inc = findMinAbsDiff(S, n - 1, S1 + S[n], S2);
 
    
    int exc = findMinAbsDiff(S, n - 1, S1, S2 + S[n]);
 
    return min(inc, exc);
}
 
int main()
{
   
    vector<int> S = { 10, 20, 15, 5, 25};
 
 
    int n = S.size();
 
    cout << "The minimum difference is " << findMinAbsDiff(S, n - 1, 0, 0);
 
    return 0;
}
