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
void recur_traversal(node *head)
{
    if(head==nullptr)
    return;
    cout<<head->data<<" ";
    recur_traversal(head->next);
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append(head);
   recur_traversal(head);
}
