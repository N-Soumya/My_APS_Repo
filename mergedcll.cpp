#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data=x;
        next=nullptr;
        prev=nullptr;
    }
};

node *append(node *head)
{
    int x;
    cout<<"Enter the data : ";
    cin>>x;
    node *temp=new node(x);
    if(head==nullptr)
    {
        head=temp;
        head->next=temp;
        head->prev=temp;
    }
    else
    {
        node *p=head->prev;
        head->prev=temp;
        temp->next=head;
        temp->prev=p;
        p->next=temp;
    }
    cout<<"\n";
    return head;
}
void display(node *head)
{
    if(head==nullptr)
    {
        cout<<"List is empty.\n";
        return;
    }
    node *p=head->next;
    cout<<head->data<<" ";
    while(p!=head)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}
node *mergelists(node *nhead,node *head1,node *head2)
{
    node *p=head1->next;

    node *q=head2->next;
    nhead=head1;

    nhead->next=head2;

    nhead->next->prev=nhead;

    node *r=nhead->next;

    while(p!=head1)
    {
        node *temp1=p->next;
        node *temp2=q->next;


        r->next=p;
        p->next->prev=r;

        r=r->next;


        r->next=q;
        q->prev=r;


        nhead->prev=q;
        r->next->next=nhead;
        r->next->prev=r;

        r=r->next;

        p=temp1;
        q=temp2;

    }
    return nhead;

}
int main()
{
    int n;
    cout<<"Enter number of nodes in the lists : ";
    cin>>n;

    node *head1=nullptr;
    cout<<"List 1 : \n";

    for(int i=1;i<=n;i++)
    head1=append(head1);

    cout<<"List 2 : \n";
    node *head2=nullptr;

    for(int i=1;i<=n;i++)
    head2=append(head2);

    cout<<"Original lists are : \n";
    cout<<"List 1 : ";
    display(head1);
    cout<<"List 2 : ";
    display(head2);
    cout<<"Modified list is : \n";
    node *nhead=nullptr;
    nhead=mergelists(nhead,head1,head2);
    display(nhead);
}
