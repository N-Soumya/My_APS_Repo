/*
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer N
*/
#include<iostream>
using namespace std;

int countZeros(int n)
{
    if(n==0)
    return 0;
    else
    {
        if(n%10==0)
        return 1+countZeros(n/10);
        else
        return countZeros(n/10);
    }
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Total Zeros = "<<countZeros(n);
}
