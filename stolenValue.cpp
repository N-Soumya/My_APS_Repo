#include<iostream>
using namespace std;

int main()
{

    int arr[8] = {0,9,3,5,8,2,4,7};
    int n=7;

    int dp[n+1];
    dp[0] = 0;
    dp[1] = arr[1];
    for(int i=2; i<=n; i++)
    {

        dp[i] = max (dp[i-1], dp[i-2]+arr[i]);
    }
    cout<<"Total profit: "<<dp[n]<<endl;
    for(int i=n; i>=0; i--)
    {

        if(dp[i] != dp[i-1])
        {

            cout<<"Robbed: index- "<<i<<" Value- "<<arr[i]<<endl;
            i--;
        }



    }

}

