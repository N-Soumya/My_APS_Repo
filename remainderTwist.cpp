#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         int n, r;
        cin >> n >> r;
 
        vector<int> dp(n + 2);
 
        int  zero = 0;
 
        for (int i = 1; i <= n; i++) {
            int div = n / i;
            int rem = n - i * div;
 
            dp[rem]++;
            dp[i - 1] += div;
            zero += div;
        }
        dp[0] = zero;
        int val = 0;
        bool flag = true;
        for (int i = n - 1; i > 0; i--) {
            dp[i] += dp[i + 1];
        }
 
        for (int i = n; i >= 0; i--) {
            val += dp[i];
            if (val >= r) {
                cout << i << "\n";
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << -1 << "\n";
        }
    }
    return 0;
}
