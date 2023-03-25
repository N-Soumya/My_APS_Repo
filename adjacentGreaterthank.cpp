#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n,k, flag=0;
        cin>>n>>k;
        if(k >= n+2)
             cout<<"-1"<<endl;
        else if(k<=3)
        {
            for(int i=0; i<n; i++)
            cout<<i+1<<" ";
            cout<<endl;
        }
        else if(k%2 ==0)
        {
            int a = 1;
            int b = k - 1;
            while (a < b) {
                cout << a << " " << b << " ";
                a++;
                b--;
            }
            cout << a << " ";
            for(int i=k; i<=n; i++)
                cout << i << " ";
            cout << endl;
        }
        
        else {
             int a = 1;
            int b = k - 1;
            while (a<b) {
                cout << a << " " << b << " ";
                a++; b--;
            }
            for (int i=k; i<=n; i++)
                cout << i << " ";
            cout << endl;
        }

    }
    return 0;
}
