/*
iven two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.
Input format :
Line 1 : Integer M
Line 2 : Integer N
*/

#include<iostream>
using namespace std;

int multiply(int m,int n)
{
    if(n==0)
    return 0;
    else
    {
        return  m+multiply(m,n-1);
    }
}
int main()
{
    int m,n;
    cout<<"Enter two numbers : ";
    cin>>m>>n;
    cout<<m<<" x "<<n<<" = "<<multiply(m,n);
}
