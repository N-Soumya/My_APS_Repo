//print the nth element from the end of a linked list
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int a)
    {
        data=a;
        next=nullptr;
    }
    
};
node *append(node *head)
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
   
    node *temp=new node(data);
    if(head==nullptr)
    {
        head=temp;
    }
    else
    {
        node *p=head;
        while(p->next!=nullptr)
        p=p->next;
        p->next=temp;
    }
    return head;
}

void nth_from_last(node *head,int n)
{
    static int ind=0;
    if(head==nullptr)
    return;
    nth_from_last(head->next,n);
    ind=ind+1;
    if(ind==n)
    cout<<head->data;
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"\nEnter elements in the list : \n";
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append(head);
    int nlast;
    cout<<"Enter the nth position : ";
    cin>>nlast;
    if(nlast<=n)
    {
        cout<<"\nnth element from last is : ";
        nth_from_last(head,nlast);
    }
    else
    cout<<"Wrong n value.";
}
