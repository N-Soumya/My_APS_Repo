#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the dimension of matrix : ";
    cin>>n;
   

    int size=n*(n+1)/2;
    int arr[size];

  

   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           int x;
           cout<<"Enter element in [ "<<i<<","<<" "<<j<<" ] : ";
           cin>>x;
           int index=(size-((n-(i-1))*(n-(i-1)+1)/2))+(j-i);

           if(i<=j)
           arr[index]=x;
        
       }
   }
   cout<<endl;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           int index=(size-((n-(i-1))*(n-(i-1)+1)/2))+(j-i);
           if(i<=j)
           cout<<arr[index]<<" ";
           else
           cout<<"0 ";
       }
       cout<<endl;
   }

}
