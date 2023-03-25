#include<iostream>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int rc[n+1];
    for(int i=0; i<=n; i++)
        {
            rc[i]=0;
        }
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i/2; j++)
        {
            int a = j*rc[i-j];
            int b = j*(i-j);
            rc[i] = max(rc[i], max(a, b));
        }
    }
    cout<<"MAximum product of rod of length n: "<<rc[n]<<endl;
    cout<<"Maximum product of rod of length n: "<<((n/2)*(n-(n/2)))<<endl;
}
