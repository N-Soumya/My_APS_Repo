#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=nullptr;
    }
};
node *append(node *head)
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
    //now we will create a temporary node
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
node *arrange_even_odd(node *head)
{
    //first I will separate even and odd numberrs and create two new linked lists
    //,then I will merge both of them
    node *even=nullptr;
    node *odd=nullptr;
    node *p=head;//points to original list
    node *e=nullptr;//points to even linked list
    node *o=nullptr;
    int flag_even=0;
    int flag_odd=0;
    while(p!=nullptr)
    {
        if(even==nullptr && p->data % 2 == 0)
        {
            even=p;
            p=p->next;
            e=even;
            e->next=nullptr;
            flag_even=1;
        }
        else if(odd==nullptr && p->data%2==1)
        {
            odd=p;
            p=p->next;
            o=odd;
            o->next=nullptr;
            flag_odd=1;
        }
        else if(p->data%2==0 && even!=nullptr)
        {
            e->next=p;
            p=p->next;
            e=e->next;
            e->next=nullptr;
        }
        else if(p->data%2==1 && odd!=nullptr)
        {
            o->next=p;
            p=p->next;
            o=o->next;
            o->next=nullptr;
        }
    }
    //making last nodes of both the lists to nullptr
    if(flag_odd==0)
    {
        odd=nullptr;
    }
    if(flag_even==0)
    {
        even=nullptr;
    }
    cout<<"\n Odd list is : \n";
    recur_traversal(odd);
    cout<<"\n Even list is :\n";
    recur_traversal(even);
    cout<<"\n";
    //Now I will merge both the even and odd lists 
    e=even;
    o=odd;
    node *final_list=nullptr;
    node *f=nullptr;
    if(even==nullptr)
    {
        final_list=odd;
        return final_list;
    }
    if(odd==nullptr)
    {
        final_list=even;
        return final_list;
    }
    while(e!=nullptr && o!=nullptr)
    {
        if(final_list==nullptr)
        {
            final_list=e;
            f=final_list;
            e=e->next;
            f->next=o;
            o=o->next;
            f=f->next;
        }
        else
        {
            f->next=e;
            e=e->next;
            f=f->next;
            f->next=o;
            o=o->next;
            f=f->next;
        }
    }
    if(o!=nullptr)
    f->next=o;
    else
    f->next=e;
    
    return final_list;
}

int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    while(n--)
    {
        head=append(head);
    }
    cout<<"\nOLD LIST : \n";
    recur_traversal(head);
    
    head=arrange_even_odd(head);
    cout<<"\nNEW LIST : \n";
    recur_traversal(head);
}
